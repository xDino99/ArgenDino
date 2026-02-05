#ifndef PRIMEC_H
#define PRIMEC_H

#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#define to_char(x) static_cast<char>(x)

#pragma warning(disable : 4996)
#pragma warning(disable : 4244)
#pragma warning(disable : 4305)
#pragma comment(lib, "winmm.lib")

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <thread>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>

using namespace std;
using std::cout;
using std::endl;
using std::cin;

const int WIN_WIDTH = 120;
const int WIN_HEIGHT = 40;

using str = string;
using Bool = bool;
using num = double;
using integer = int;

template<typename T> using list = vector<T>;
template<typename K, typename V> using dict = map<K, V>;

#define True true
#define False false
#define None nullptr
#define and &&
#define or ||
#define not !
#define elif else if
#define is ==
#define is_not !=
#define pass (void)0
#define self (*this)

enum Colors {
	BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LIGHTGRAY = 7,
	DARKGRAY = 8, LIGHTBLUE = 9, LIGHTGREEN = 10, LIGHTCYAN = 11, LIGHTRED = 12, LIGHTMAGENTA = 13, YELLOW = 14, WHITE = 15
};

template <typename T>
str str_cast(T val) {
	stringstream ss;
	ss << val;
	return ss.str();
}

inline int intCast(str s) {
	try { return stoi(s); }
	catch (...) { return 0; }
}

inline double floatCast(str s) {
	try { return stod(s); }
	catch (...) { return 0.0; }
}

inline void print() {
	cout << endl;
}

template <typename T, typename... Args>
inline void print(const T& first, const Args&... args) {
	cout << first;
	if (sizeof...(args) > 0) {
		cout << " ";
		print(args...);
	}
	else {
		cout << endl;
	}
}

inline str input(str prompt = "") {
	cout << prompt;
	str line;
	getline(cin, line);
	return line;
}

inline int getKey() {
	int k = _getch();
	if (k == 0 || k == 224) {
		k = _getch();
	}
	return k;
}

inline void waitKey() {
	(void)_getch();
}

template <typename T>
inline int len(const vector<T>& v) {
	return static_cast<int>(v.size());
}

inline int len(const str& s) {
	return static_cast<int>(s.length());
}

template <typename K, typename V>
inline int len(const map<K, V>& m) {
	return static_cast<int>(m.size());
}

inline list<int> range(int start, int stop, int step = 1) {
	list<int> result;
	if (step == 0) return result;
	if (step > 0) {
		for (int i = start; i < stop; i += step) result.push_back(i);
	}
	else {
		for (int i = start; i > stop; i += step) result.push_back(i);
	}
	return result;
}

inline list<int> range(int stop) {
	return range(0, stop, 1);
}

inline void playSound(str path) {
	PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC);
}

inline void loopSound(str path) {
	PlaySoundA(path.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

inline void stopSound() {
	PlaySoundA(NULL, NULL, 0);
}

inline void beep(int freq, int duration) {
	Beep(freq, duration);
}

inline void sleep(double seconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long long>(seconds * 1000)));
}

template <typename T>
inline bool in(const T& item, const list<T>& container) {
	return find(container.begin(), container.end(), item) != container.end();
}

inline bool in(char item, const str& container) {
	return container.find(item) != str::npos;
}

inline bool in(const str& item, const str& container) {
	return container.find(item) != str::npos;
}

template<typename T>
inline void append(list<T>& l, T val) {
	l.push_back(val);
}

template<typename T>
inline T pop(list<T>& l) {
	if (l.empty()) return T();
	T val = l.back();
	l.pop_back();
	return val;
}

inline int randint(int min, int max) {
	static bool seed_set = false;
	if (!seed_set) {
		srand(static_cast<unsigned int>(time(0)));
		seed_set = true;
	}
	return min + (rand() % (max - min + 1));
}

inline void clear() {
	system("cls");
}

inline void quit() {
	exit(0);
}

inline void write(str text) {
	std::cout << text;
}

inline void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

inline void setColor(int text, int background = 0) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}

inline POINT getMousePos(HWND hwnd) {
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hwnd, &p);
	return p;
}

inline bool isMousePressed(int button) {
	return (GetAsyncKeyState(button) & 0x8000) != 0;
}

inline void hideCursor(bool hidden = true) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = !hidden;
	SetConsoleCursorInfo(consoleHandle, &info);
}

inline void flushInput() {
	while (_kbhit()) (void)_getch();
}

inline void printCentered(int y, str text, int color) {
	int x = (WIN_WIDTH - len(text)) / 2;
	gotoxy(x, y);
	setColor(color);
	cout << text;
}

inline void drawBox(int color) {
	setColor(color);
	gotoxy(0, 0); cout << "\xC9";
	for (int i : range(WIN_WIDTH - 2)) cout << "\xCD"; cout << "\xBB";
	for (int i : range(1, WIN_HEIGHT - 1)) {
		gotoxy(0, i); cout << "\xBA";
		gotoxy(WIN_WIDTH - 1, i); cout << "\xBA";
	}
	gotoxy(0, WIN_HEIGHT - 1); cout << "\xC8";
	for (int i : range(WIN_WIDTH - 2)) cout << "\xCD"; cout << "\xBC";
}

inline void drawBigTitle(int color_acento) {
	int startY = 3;
	str argen[] = { "  _    ____   ____ _____ _   _ ", " / \\  |  _ \\ / ___| ____| \\ | |", "/ _ \\ | |_) | |  _|  _| |  \\| |", "/ ___ \\|  _ <| |_| | |___| |\\  |", "/_/   \\_\\_| \\_\\\\____|_____|_| \\_|" };
	str dino[] = { "____ ___ _   _   ___  ", "|  _ \\_ _| \\ | |/ _ \\ ", "| | | | ||  \\| | | | |", "| |_| | || |\\  | |_| |", "|____/___|_| \\_|\\___/ " };
	int startX = (WIN_WIDTH - 54) / 2;

	for (int i : range(5)) {
		gotoxy(startX, startY + i);
		setColor(color_acento); cout << argen[i];
		setColor(WHITE); cout << dino[i];
	}
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
public:
	HWND hwnd;
	HINSTANCE hInst;
	str title;
	int width, height;
	bool running;

	Window(str t, int w, int h) : title(t), width(w), height(h), running(false) {
		hInst = GetModuleHandle(NULL);

		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInst;
		wc.lpszClassName = L"DinoWindowClass";
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);

		RegisterClass(&wc);

		std::wstring stemp = std::wstring(title.begin(), title.end());

		hwnd = CreateWindowEx(
			0, L"DinoWindowClass", stemp.c_str(),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			width, height, NULL, NULL, hInst, this
		);

		if (hwnd) {
			running = true;
			ShowWindow(hwnd, SW_SHOW);
		}
	}

	void update() {
		MSG msg = {};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) running = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void drawRect(int x, int y, int w, int h, COLORREF color) {
		HDC hdc = GetDC(hwnd);
		HBRUSH brush = CreateSolidBrush(color);
		RECT r = { x, y, x + w, y + h };
		FillRect(hdc, &r, brush);
		DeleteObject(brush);
		ReleaseDC(hwnd, hdc);
	}

	void drawPixel(int x, int y, COLORREF color) {
		HDC hdc = GetDC(hwnd);
		SetPixel(hdc, x, y, color);
		ReleaseDC(hwnd, hdc);
	}
};

inline LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	} return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

inline void processEvents() {
	MSG msg = {};
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

inline void setWindowSize() {
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	HWND consoleWindow = GetConsoleWindow();

	str command = "mode con cols=" + str_cast(WIN_WIDTH) + " lines=" + str_cast(WIN_HEIGHT);
	system(command.c_str());

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	style &= ~WS_THICKFRAME;
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	SetWindowPos(consoleWindow, NULL, 0, 0, 0, 0,
		SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);

	hideCursor(True);
}

inline void setTitle(str title) {
	SetConsoleTitleA(title.c_str());
}

inline str toUpper(str s) {
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return s;
}

inline str toLower(str s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

inline bool startLauncher() {
	HWND hConsole = GetConsoleWindow();
	ShowWindow(hConsole, SW_HIDE);

	int msg = MessageBox(
		NULL,
		L"ArgenDino ~ Multi Game System\n\n[CONFIG] WINDOW 120x40@hz.\n[SUPPORT] Use conhost.exe for a better experience.\n[TIPS] You can adjust the window size with CTRL+SMU/SMD and you can also change the typography and font of the terminal, although it is better to leave it as default (437 IBM Classic Console).\n\nWant to start the game?",
		L"ArgenDino Launcher (BETA)",
		MB_YESNO | MB_DEFBUTTON1 | MB_SETFOREGROUND
	);

	if (msg == IDYES) {
		ShowWindow(hConsole, SW_SHOW);
		SetForegroundWindow(hConsole);
		return true;
	}
	return false;
}

inline void startScreen() {
	clear();
	str dinoASCII[] = {
	"            __",
	"             /  \\",
	"       _____/   __J",
	"      /         /  ",
	"     /   __    /   ",
	"    /   /  \\  /    ",
	"   /__/    /__/    "
	};

	int startY = (WIN_HEIGHT / 2) - 4;
	for (int i : range(7)) {
		printCentered(startY + i, dinoASCII[i], LIGHTBLUE);
	}

	printCentered(startY + 8, "A R G E N D I N O   ~   D I N O   E N G I N E", WHITE);

	sleep(1);
	flushInput();
	clear();
}

inline void loadingScreen(int aColor) {
	clear();
	drawBox(aColor);

	int totalSeconds = 5;
	int barWidth = 40;
	int timePerSegment = (totalSeconds * 1000) / barWidth;
	int startX = (WIN_WIDTH - barWidth) / 2;
	int y = WIN_HEIGHT / 2;

	printCentered(y - 3, "INICIALIZANDO DINO ENGINE...", WHITE);

	gotoxy(startX - 1, y - 1); cout << "\xDA";
	for (int i : range(barWidth)) cout << "\xC4";
	cout << "\xBF";

	gotoxy(startX - 1, y); cout << "\xB3";
	gotoxy(startX + barWidth, y); cout << "\xB3";

	gotoxy(startX - 1, y + 1); cout << "\xC0";
	for (int i : range(barWidth)) cout << "\xC4";
	cout << "\xD9";

	for (int i : range(barWidth)) {
		gotoxy(startX + i, y);
		setColor(aColor);
		cout << "\xDB";

		int percentage = (i + 1) * 100 / barWidth;
		printCentered(y + 3, "CARGANDO RECURSOS: " + str_cast(percentage) + "%", WHITE);

		sleep((float)timePerSegment / 1000.0f);
	}

	printCentered(y + 5, "SISTEMA LISTO", LIGHTGREEN);
	sleep(0.5);
	flushInput();
	clear();
}

inline void webView(int aColor) {
	clear();
	drawBox(aColor);

	setColor(DARKGRAY);
	gotoxy(2, 1); cout << " [ DinoWV ]  Address: host://home/";

	setColor(aColor);
	gotoxy(1, 2);
	for (int i : range(WIN_WIDTH - 2)) cout << "\xCD";

	printCentered(6, "BIENVENIDO AL DINO-WEB BROWSER", aColor);
	printCentered(9, " ERROR 404: PAGINA EN CONSTRUCCION ", LIGHTRED);
	printCentered(11, "Estamos trabajando en nuevos juegos para el", WHITE);
	printCentered(12, "Dino Engine. Vuelve pronto para ver las ", WHITE);
	printCentered(13, "ultimas novedades del sistema.", WHITE);
	printCentered(16, "<--- [ RED CONECTADA ] --->", LIGHTGREEN);
	printCentered(20, "Presiona ENTER para volver", LIGHTRED);

	flushInput();
	while (True) {
		if (_kbhit()) {
			int key = _getch();
			if (key is 13) break;
		}
	}
	clear();
}

inline void infoMenu(int aColor) {
	clear();
	drawBox(aColor);
	printCentered(4, "INFORMACION DEL SISTEMA", WHITE);

	printCentered(7, "ArgenDino ~ Multi Game System", aColor);
	printCentered(9, "Dino Engine v1.0.0.re -  ArgenDino v1.0.0.de", WHITE);
	printCentered(11, "Compiled: " + str(__DATE__) + " " + str(__TIME__), LIGHTGRAY);
	printCentered(13, "License: Freeware", DARKGRAY);
	printCentered(14, "Online Status: OFF - Private Servers Status: OFF", DARKGRAY);
	printCentered(15, "Langs: Prime C, Python, HTML, C++, C, Batchfile", DARKGRAY);
	printCentered(16, "DinoEngine Modules for Windows Platform 1.0", DARKGRAY);
	printCentered(17, "Build ID: v1.0-rev_" + str_cast((void*)(unsigned long long)(hash<str>{}(str(__DATE__) + str(__TIME__)))).substr(2, 6), DARKGRAY);
	printCentered(18, "Data: w: 120x40c@hz - ch: 437 by default - c: conhost", DARKGRAY);
	printCentered(19, "Libs: primec.h, glbengine.h", DARKGRAY);
	printCentered(20, "Runtime: MSVCP RT-Dynamic Link Library", DARKGRAY);
	printCentered(21, "Compiler: MSVC v143 / v144 (Visual Studio 2026)", DARKGRAY);
	printCentered(22, "Architecture: C++ Nativo v14 2026 | ArgenDino x64 & ARM64", DARKGRAY);

	printCentered(24, "Developer: xDino99", LIGHTBLUE);
	printCentered(26, "Gracias por jugar!", WHITE);
	printCentered(30, "Presiona ENTER para volver", LIGHTRED);

	flushInput();
	while (True) {
		int key = _getch();
		if (key is 13 or key is 27) break;
	}
}

#endif