#include "assorted.h"

bool Assorted::find_vector_in_vector(std::vector<int> x, std::vector<std::vector<int>> y) {
	bool present = false;
	for (int i = 2; i < y.size(); i++) {
		if (y[i][0] == x[0] && y[i][1] == x[1]) {
			present = true;
			return present;
		}
	}
	return present;
};

std::vector<int> Assorted::random(int min_x, int max_x, int min_y, int max_y) {

	std::vector<int> random_coordinates;
	int x, y;

	x = rand() % (max_x - min_x);
	y = rand() % (max_y - min_y);
	if (x < min_x)
		x = min_x;
	if (y < min_y)
		y = min_y;
	random_coordinates.push_back(x);
	random_coordinates.push_back(y);

	return 	random_coordinates;
}
