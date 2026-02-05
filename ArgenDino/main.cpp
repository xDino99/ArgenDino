#include "primec.h"
#include "glbengine.h"

int colorAcento = LIGHTGREEN;
str playerName = "Jugador";
str playerGender = "No especificado";
int playerAge = 0;

static void MenuSeleccionarEdad() {
	str tempAge = "";
	int key = 0;

	clear();
	drawBox(colorAcento);
	printCentered(8, "INGRESA TU EDAD (Max 2 digitos)", WHITE);
	hideCursor(False);

	gotoxy((WIN_WIDTH / 2) - 1, 12);
	setColor(colorAcento);
	write("> ");

	flushInput();

	while (True) {
		key = getKey();

		if (key is 13) {
			if (not tempAge.empty()) {
				playerAge = intCast(tempAge);
				break;
			}
		}
		else if (key is 8) {
			if (not tempAge.empty()) {
				tempAge.pop_back();
				write("\b \b");
			}
		}
		elif(key >= '0' and key <= '9') {
			tempAge += to_char(key);
			write(str_cast((char)key));
		}
	}

	hideCursor(True);
}

void MenuCambiarNombre() {
	str tempName = "";
	int key = 0;

	clear();
	drawBox(colorAcento);
	printCentered(8, "INGRESA TU NOMBRE (Max 12)", WHITE);
	hideCursor(False);

	gotoxy((WIN_WIDTH / 2) - 6, 12);
	setColor(colorAcento);
	write("> ");

	flushInput();

	while (True) {
		key = getKey();

		if (key is 13) {
			if (not tempName.empty()) break;
		}
		else if (key is 8) {
			if (not tempName.empty()) {
				tempName.pop_back();
				write("\b \b");
			}
		}
		else if (isprint((char)key) and len(tempName) < 12) {
			tempName += to_char(key);
			write(str_cast((char)key));
		}
	}

	playerName = tempName;
	hideCursor(True);
}

void MenuSeleccionarGenero() {
	int option = 0;
	int key = 0;
	str genders[] = { "Masculino", "Femenino", "Otro / No Binario" };
	while (True) {
		clear();
		drawBox(colorAcento);
		printCentered(6, "SELECCIONA TU GENERO", WHITE);
		for (int i : range(3)) {
			if (i is option) printCentered(10 + (i * 2), ">> " + genders[i] + " <<", colorAcento);
			else printCentered(10 + (i * 2), genders[i], DARKGRAY);
		}

		key = getKey();
		
		if (key == 72 && option > 0) {
			option--;
		}

		else if (key == 80 && option < 5) {
			option++;
		}

		else if (key is 13) {
			playerGender = genders[option];
			break;
		}
	}
}

void MenuSeleccionarColor() {
	int option = 0;
	int key = 0;
	str colorNames[] = { "Verde Hacker", "Cyan Neon", "Magenta Retro", "Amarillo Sol", "Rojo Fuego", "Aguamarina", "Azul Brillante", "Purpura", "Hielo Blanco" };
	int colorCodes[] = { LIGHTGREEN, LIGHTCYAN, LIGHTMAGENTA, YELLOW, LIGHTRED, CYAN, LIGHTBLUE, MAGENTA, WHITE };
	while (True) {
		clear();
		drawBox(colorAcento);
		printCentered(5, "ELIGE COLOR DE INTERFAZ", WHITE);
		for (int i : range(9)) {
			if (i is option) printCentered(8 + i, "-> " + colorNames[i] + " <-", colorCodes[i]);
			else printCentered(8 + i, colorNames[i], DARKGRAY);
		}

		key = getKey();
		if (key == 72) option--;
		if (key == 80) option++;
		else if (key is 13) {
			colorAcento = colorCodes[option];
			break;
		}
	}
}

void ConfigMenu() {
	int option = 0;
	int key = 0;
	while (True) {
		clear();
		drawBox(colorAcento);
		printCentered(4, "CONFIGURACION DE PERFIL", WHITE);
		str options[] = { "Nombre: " + playerName, "Genero: " + playerGender, "Color de Interfaz", "Edad: " + str_cast(playerAge), "Volver al Menu" };
		for (int i : range(5)) {
			if (i is option) printCentered(14 + (i * 2), ">> [ " + options[i] + " ] <<", colorAcento);
			else printCentered(14 + (i * 2), options[i], WHITE);
		}

		key = getKey();
		
		if (key == 72 && option > 0) {
			option--;
		}

		else if (key == 80 && option < 5) {
			option++;
		}

		else if (key is 13) {
			if (option is 0) MenuCambiarNombre();
			elif(option is 1) MenuSeleccionarGenero();
			elif(option is 2) MenuSeleccionarColor();
			elif(option is 3) MenuSeleccionarEdad();
			else break;
		}
	}
}

void GameSelectionMenu() {
	int option = 0;
	int key = 0;
	while (True) {
		clear();
		drawBox(colorAcento);
		printCentered(4, "SELECCIONA MODO DE JUEGO", WHITE);
		str games[] = { "1. ArgenDino Clasico", "2. GameType2 (WIP)", "3. GameType3 (WIP)", "4. GameType4 (WIP)", "5. GameType5 (WIP)", "Volver al Menu" };
		for (int i : range(6)) {
			if (i is option) printCentered(12 + (i * 2), ">> [ " + games[i] + " ] <<", colorAcento);
			else printCentered(12 + (i * 2), games[i], WHITE);
		}

		key = getKey();
		if (key is 72 and option > 0) option--;
		if (key is 80 and option < 5) option++;
		else if (key is 13) {
			if (option is 0) RunClassicSnake();
			elif(option is 5) break;
		}
	}
}

int main() {

	if (not startLauncher()) {
		return 0;
	}

	setWindowSize();
	startScreen();
	loadingScreen(LIGHTGREEN);

	int option = 0;
	int key = 0;

	while (True) {
		clear();
		drawBox(colorAcento);
		drawBigTitle(colorAcento);
		printCentered(11, "Hola, " + playerName + "!", LIGHTBLUE);

		str options[] = { "JUGAR", "CONFIGURAR", "INFORMACION", "DINO WEB BROWSER", "ONLINE (ALPHA)", "SALIR DEL JUEGO" };

		for (int i : range(6)) {
			if (i is option) printCentered(16 + (i * 2), ">> [ " + options[i] + " ] <<", colorAcento);
			else printCentered(16 + (i * 2), options[i], WHITE);
		}

		str infoIzquierda = "System: Windows";
		gotoxy(3, WIN_HEIGHT - 4);
		setColor(DARKGRAY);
		write(infoIzquierda);

		printCentered(WIN_HEIGHT - 4, "https://linktr.ee/xDino99", DARKGRAY);

		str infoDerecha = "Status: Console";
		int xPos = WIN_WIDTH - len(infoDerecha) - 3;
		gotoxy(xPos, WIN_HEIGHT - 4);
		setColor(DARKGRAY);
		write(infoDerecha);

		gotoxy(2, WIN_HEIGHT - 3); setColor(colorAcento);
		for (int i : range(WIN_WIDTH - 4)) write("\xC4");

		printCentered(WIN_HEIGHT - 2, "[any_key] Refrescar [Flechas] Navegar [ENTER] Seleccionar", WHITE);

		key = getKey();

		if (key == 72 && option > 0) {
			option--;
		}

		else if (key == 80 && option < 5) {
			option++;
		}

		else if (key == 13) {
			if (option == 0) GameSelectionMenu();
			elif(option == 1) ConfigMenu();
			elif(option is 2) infoMenu(colorAcento);
			elif(option is 3) webView(colorAcento);
			elif(option is 4) abort();
			elif(option is 5) quit();
		}
	}

	system("pause");
	return 0;
}