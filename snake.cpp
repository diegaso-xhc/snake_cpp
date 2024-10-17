#include "snake.h"
#include "environment.h"

Snake::Snake(int len, int init_x, int init_y) {
	length = len; // Initial desired length of snake
	for (int i = 0; i < length; i++) {
		if (i == 0)
			body_positions.push_back({ init_x, init_y }); // initialize positions for all body
		else
			body_positions.push_back({ init_x, init_y - i }); // initialize positions for all body
	}
}

void Snake::track_head(int inc_x, int inc_y, Environment env) {
	update_position();
	int tmp_x = body_positions[0][0] + inc_x;
	int tmp_y = body_positions[0][1] + inc_y;
	if (tmp_x > env.x_length - 2) {
		body_positions[0][0] = 1;
		body_positions[0][1] = body_positions[0][1] + inc_y;
	}		
	else if (tmp_x < 1) {
		body_positions[0][0] = env.x_length - 2;
		body_positions[0][1] = body_positions[0][1] + inc_y;
	}		
	else if (tmp_y > env.y_length - 2) {
		body_positions[0][0] = body_positions[0][0] + inc_x;
		body_positions[0][1] = 1;
	}		
	else if (tmp_y < 1) {
		body_positions[0][0] = body_positions[0][0] + inc_x;
		body_positions[0][1] = env.y_length - 2;
	}		
	else {
		body_positions[0][0] = body_positions[0][0] + inc_x;
		body_positions[0][1] = body_positions[0][1] + inc_y;
	}	
}

void Snake::update_position() {
	for (int i = body_positions.size() - 1; i > 0; i--) {
		body_positions[i][0] = body_positions[i - 1][0];
		body_positions[i][1] = body_positions[i - 1][1];
	}
}
