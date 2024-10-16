#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

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

	int l_snake = 10;
	int init_x = 20;
	int init_y = 20;
	int height_environment = 30;
	int width_environment = 30;

	Environment square_1(height_environment, width_environment, "square");
	Snake sneaky(l_snake, init_x, init_y);
	
	char x = 't';
	int inc_x = 0;
	int inc_y = 0;
	bool time_flag = true;

	while (true) {

		std::cout << "RUNNING PROGRAM" << std::endl;
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = ' ';
		std::this_thread::sleep_for(std::chrono::milliseconds(100));


		if (_kbhit())
		{
			x = _getch();
		}
		if (x == 'w') {
			inc_x = -1;
			inc_y = 0;	
		}
		else if (x == 's') {
			inc_x = 1;
			inc_y = 0;
		}
		else if (x == 'a') {
			inc_x = 0;
			inc_y = -1;
		}
		else if (x == 'd') {
			inc_x = 0;
			inc_y = 1;
		}
		else if (x == 'q')
			break;
		sneaky.track_head(inc_x, inc_y, square_1);
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = '*';
		square_1.display_environment();
		clear_console();
	}
	
	
	/*
	for (int it = 0; it < 10; it++) {
		std::cout << "RUNNING PROGRAM" << std::endl;
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = ' ';
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if (it < 5)
			sneaky.track_head(0, 1);
		else
			sneaky.track_head(1, 0);
		for (int i = 0; i < l_snake; i++)
			square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = '*';
		square_1.display_environment();
		clear_console();
	}*/
	/*
	char x;
	while (1)
	{
		x = _getch();
		std::cout << x << std::endl;
		if (x == 'w')
			std::cout << "up" << std::endl;
		else if (x == 's')
			std::cout << "down" << std::endl;
		else if (x == 'a')
			std::cout << "left" << std::endl;
		else if (x == 'd')
			std::cout << "right" << std::endl;


	}//while1*/


	//std::cin.get();
	return 0;
}