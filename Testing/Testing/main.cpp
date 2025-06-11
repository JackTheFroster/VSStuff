#include <windows.h>

// Spielfeldgröße
const int BREITE = 800;
const int HOEHE = 600;

// Ball- und Balken-Positionen
int ballX = BREITE / 2;
int ballY = HOEHE / 2;
int ballRichtungX = 4, ballRichtungY = 4;
int spielerPos = HOEHE / 2;
int kiPos = HOEHE / 2;

// Fensterprozedur: Behandelt Nachrichten (z. B. Tastatur, Zeichnen)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;

    case WM_KEYDOWN: // Spielersteuerung
        if (wParam == 'W' && spielerPos > 0) spielerPos -= 20; // Nach oben
        if (wParam == 'S' && spielerPos < HOEHE - 100) spielerPos += 20; // Nach unten
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Spielfeldhintergrund
        Rectangle(hdc, 0, 0, BREITE, HOEHE);

        // Spieler-Balken (links)
        Rectangle(hdc, 50, spielerPos, 70, spielerPos + 100);

        // KI-Balken (rechts)
        Rectangle(hdc, BREITE - 70, kiPos, BREITE - 50, kiPos + 100);

        // Ball zeichnen
        Ellipse(hdc, ballX - 10, ballY - 10, ballX + 10, ballY + 10);

        EndPaint(hwnd, &ps);
        return 0;
    }

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

// Ballbewegung und Kollisionen
void AktualisiereSpiel() {
    ballX += ballRichtungX;
    ballY += ballRichtungY;

    // Abprallen an Ober- und Unterkante
    if (ballY <= 0 || ballY >= HOEHE) ballRichtungY *= -1;

    // Kollision mit dem Spieler-Balken
    if (ballX <= 70 && ballY >= spielerPos && ballY <= spielerPos + 100)
        ballRichtungX = 4;

    // Kollision mit dem KI-Balken
    if (ballX >= BREITE - 70 && ballY >= kiPos && ballY <= kiPos + 100)
        ballRichtungX = -4;

    // Ball zurücksetzen bei Punkt
    if (ballX <= 0 || ballX >= BREITE) {
        ballX = BREITE / 2;
        ballY = HOEHE / 2;
        ballRichtungX *= -1;
    }

    // Einfache KI-Bewegung
    if (kiPos + 50 < ballY) kiPos += 4;
    if (kiPos + 50 > ballY) kiPos -= 4;
}

// Haupteinstiegspunkt der Windows-Anwendung
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Fensterklasse registrieren
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"PongFenster";
    RegisterClass(&wc);

    // Fenster erstellen
    HWND hwnd = CreateWindowEx(0, L"PongFenster", L"Pong Spiel", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, BREITE, HOEHE, NULL, NULL, hInstance, NULL);
    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    // Nachrichten-Schleife
    MSG msg = {};
    while (true) {
        // Windows-Nachrichten abfragen
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return 0;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Spiel aktualisieren
        AktualisiereSpiel();

        // Fenster neu zeichnen
        InvalidateRect(hwnd, NULL, TRUE);

        // Verzögern für Spielgeschwindigkeit
        Sleep(16); // ~60 FPS
    }

    return 0;
}
