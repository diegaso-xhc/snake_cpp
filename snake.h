#pragma once
#include <vector>
#include "environment.h"
#include "food.h"
#include "assorted.h"

class Snake {
	public:
		int length;
		bool eating;
		bool hurt = false;
		std::vector<std::vector<int>> body_positions;

	public:
		Snake(int length, int init_x, int init_y);
		void track_head(int inc_x, int inc_y, Environment env, Food snack);
		void clear_snake(Environment& env);
		void draw_snake(Environment& env);

	private:
		void update_position();
};