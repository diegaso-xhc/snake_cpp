#pragma once
#include<vector>
#include "environment.h"

class Snake {
	public:
		int length;
		std::vector<std::vector<int>> body_positions;

	public:
		Snake(int length, int init_x, int init_y);
		void track_head(int inc_x, int inc_y, Environment env);

	private:
		void update_position();
};