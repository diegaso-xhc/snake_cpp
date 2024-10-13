#include <iostream>
#include <chrono>
#include <thread>

#include "environment.h"
#include "console_handle.h"
#include "snake.h"


int main() {

	/*
	int x = 5;
	char* chars = new char[10];
	chars[2] = 5;
	int* ptr = &x;
	int** ptrptr = &ptr;
	float x1 = 0.00014444;
	std::cout << x1 << std::endl;
	std::cout << std::scientific << x1 << std::endl;*/

	int l_snake = 5;
	int init_x = 10;
	int init_y = 10;
	int height_environment = 20;
	int width_environment = 40;


	Environment square_1(height_environment, width_environment, "square");
	Snake sneaky(l_snake, init_x, init_y);
		
	for (int it = 0; it < 20; it++) {
		std::cout << "RUNNING PROGRAM" << std::endl;
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = ' ';
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		sneaky.track_head(0, 1);
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = '~';
		square_1.display_environment();
		clear_console();
	}

	std::cin.get();
	return 0;
}