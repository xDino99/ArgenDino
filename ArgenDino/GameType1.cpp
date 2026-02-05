#include "primec.h"
#include "glbengine.h"

static bool gameOver;
static int x, y, fruitX, fruitY, score;
static int tailX[100], tailY[100];
static int nTail;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
static eDirecton dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = WIN_WIDTH / 2;
	y = WIN_HEIGHT / 2;
	fruitX = randint(1, WIN_WIDTH - 2);
	fruitY = randint(1, WIN_HEIGHT - 2);
	score = 0;
	nTail = 0;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': if (dir != RIGHT) dir = LEFT; break;
		case 'd': if (dir != LEFT) dir = RIGHT; break;
		case 'w': if (dir != DOWN) dir = UP; break;
		case 's': if (dir != UP) dir = DOWN; break;
		case 'x': gameOver = true; break;
		}
	}
}

void Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {
	case LEFT: x--; break;
	case RIGHT: x++; break;
	case UP: y--; break;
	case DOWN: y++; break;
	default: break;
	}

	if (x >= WIN_WIDTH - 1 || x <= 0 || y >= WIN_HEIGHT - 1 || y <= 0) gameOver = true;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y) gameOver = true;

	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = randint(1, WIN_WIDTH - 2);
		fruitY = randint(1, WIN_HEIGHT - 2);
		nTail++;
	}
}

void RunClassicSnake() {
	hideCursor(true);
	clear();
	drawBox(colorAcento);
	Setup();

	while (!gameOver) {
		if (nTail > 0) {
			gotoxy(tailX[nTail - 1], tailY[nTail - 1]); cout << " ";
		}
		gotoxy(x, y); cout << " ";

		Input();
		Logic();

		setColor(LIGHTRED); gotoxy(fruitX, fruitY); cout << "V";
		setColor(colorAcento); gotoxy(x, y); cout << "O";
		for (int k = 0; k < nTail; k++) {
			gotoxy(tailX[k], tailY[k]); cout << "o";
		}

		setColor(LIGHTGRAY); gotoxy(2, 0); cout << " Score: " << score << " ";
		sleep(0.1);
	}

	printCentered(WIN_HEIGHT / 2, "FIN DEL JUEGO - VOLVIENDO AL MENU - Espera 1 Segundo", WHITE);
	sleep(1.0);
}