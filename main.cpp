#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

#include "environment.h"
#include "console_handle.h"
#include "snake.h"
#include "food.h"


int main() {

	/*
	int x1 = 5;
	char* chars = new char[10];
	chars[2] = 5;
	int* ptr = &x1;
	int** ptrptr = &ptr;
	float x2 = 0.00014444;
	std::cout << x2 << std::endl;
	std::cout << std::scientific << x2 << std::endl;
	*/

	int l_snake = 7;
	int init_x = 10;
	int init_y = 10;
	int x_food = 2;
	int y_food = 2;
	int height_environment = 15;
	int width_environment = 20;

	Environment square_1(height_environment, width_environment, "square");
	Snake sneaky(l_snake, init_x, init_y);
	Food snack(x_food, y_food);

	char x = 't';
	int inc_x = 0;
	int inc_y = 0;
	bool time_flag = true;
	std::vector<int> tmp_pos;
	bool start = false;
	
	while (true) {

		if (sneaky.hurt) {
			start = false;
			clear_console();
			std::cout << "You bit yourself. Try again!" << std::endl;
		}

		if (_kbhit())
		{
			x = _getch();
		}
		if (x == 'w') {
			inc_x = -1;
			inc_y = 0;
			start = true;
		}
		else if (x == 's') {
			inc_x = 1;
			inc_y = 0;
			start = true;
		}
		else if (x == 'a') {
			inc_x = 0;
			inc_y = -1;
			start = true;
		}
		else if (x == 'd') {
			inc_x = 0;
			inc_y = 1;
			start = true;
		}
		else if (x == 'q')
			break;
				
		if (start) {
			for (int i = 0; i < sneaky.length; i++)
				square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = ' ';

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			sneaky.track_head(inc_x, inc_y, square_1, snack);

			for (int i = 0; i < sneaky.length; i++)
				square_1.environment[sneaky.body_positions[i][0]][sneaky.body_positions[i][1]] = '*';

			if (sneaky.eating) {
				square_1.environment[snack.x_pos][snack.y_pos] = ' ';
				tmp_pos = Assorted::random(2, height_environment, 2, width_environment);
				snack.x_pos = tmp_pos[0];
				snack.y_pos = tmp_pos[1];
			}
			else {
				square_1.environment[snack.x_pos][snack.y_pos] = '+';
			}

			square_1.display_environment();

			clear_console();
		}
		
	}
	return 0;
}