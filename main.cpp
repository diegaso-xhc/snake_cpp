#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

#include "environment.h"
#include "console_handle.h"
#include "snake.h"
#include "food.h"

constexpr int height_environment = 30;
constexpr int width_environment = 70;
constexpr int pause = 100;

int main() {

	int l_snake = 15;
	int init_x = 15;
	int init_y = 15;
	int x_food = height_environment / 2;
	int y_food = width_environment / 2;
	int inc_x = 0;
	int inc_y = 0;
	bool time_flag = true;	
	bool start = false;
	char x = 't';
	int direction = 0;
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
		if (x == 'w' && direction != 2) {
			inc_x = -1;
			inc_y = 0;
			start = true;
			direction = 1;
		}
		else if (x == 's' && direction != 1) {
			inc_x = 1;
			inc_y = 0;
			start = true;
			direction = 2;
		}
		else if (x == 'a' && direction != 4) {
			inc_x = 0;
			inc_y = -1;
			start = true;
			direction = 3;
		}
		else if (x == 'd' && direction != 3) {
			inc_x = 0;
			inc_y = 1;
			start = true;
			direction = 4;
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
				tmp_pos = Assorted::random(environment_clearence, height_environment, environment_clearence, width_environment);
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