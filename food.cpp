#include "food.h"

Food::Food(int x, int y) {
	x_pos = x;
	y_pos = y;
}

void Food::clear_food(Environment& env) {
	env.environment[this->x_pos][this->y_pos] = ' ';
}

void Food::draw_food(Environment& env) {
	env.environment[this->x_pos][this->y_pos] = '+';
}