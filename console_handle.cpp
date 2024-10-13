#include "console_handle.h"

void clear_console() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console, topLeft);
}