#include "snake.h"

Snake::Snake(int len, int init_x, int init_y) {
	length = len; // Initial desired length of snake
	for (int i = 0; i < length; i++) {
		if (i == 0)
			body_positions.push_back({ init_x,init_y }); // initialize positions for all body
		else
			body_positions.push_back({ init_x - i,init_y }); // initialize positions for all body
	}
}

void Snake::track_head(int inc_x, int inc_y) {
	body_positions[0][0] = body_positions[0][0] + inc_x;
	body_positions[0][1] = body_positions[0][1] + inc_y;
	update_position();
}

void Snake::update_position() {
	for (int i = 1; i < body_positions.size(); i++) {
		body_positions[i][0] = body_positions[i - 1][0];
		body_positions[i][1] = body_positions[i - 1][1];
	}
}

