#pragma once
#include "environment.h"

class Food {
public:
	int x_pos;
	int y_pos;

public:
	Food(int x_pos, int y_pos);	
	void clear_food(Environment& env);
	void draw_food(Environment& env);
};