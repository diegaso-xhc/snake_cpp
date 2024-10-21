#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

#include "environment.h"
#include "console_handle.h"
#include "snake.h"
#include "food.h"

int main() {

	int l_snake = 21;
	int init_x = 10;
	int init_y = 25;
	int x_food = 2;
	int y_food = 2;
	int height_environment = 15;
	int width_environment = 30;	
	int inc_x = 0;
	int inc_y = 0;
	int pause = 50;

	bool time_flag = true;	
	bool start = false;

	char x = 't';
	std::vector<int> tmp_pos;

	Environment square_environment(height_environment, width_environment, "square");
	Snake sneaky(l_snake, init_x, init_y);
	Food snack(x_food, y_food);
	
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
			
			sneaky.clear_snake(square_environment);
			std::this_thread::sleep_for(std::chrono::milliseconds(pause));
			sneaky.track_head(inc_x, inc_y, square_environment, snack);
			sneaky.draw_snake(square_environment);

			if (sneaky.eating) {
				snack.clear_food(square_environment);
				tmp_pos = Assorted::random(2, height_environment, 2, width_environment);
				snack.x_pos = tmp_pos[0];
				snack.y_pos = tmp_pos[1];
			}
			else {
				snack.draw_food(square_environment);
			}

			square_environment.display_environment();

			clear_console();
		}		
	}
	return 0;
}