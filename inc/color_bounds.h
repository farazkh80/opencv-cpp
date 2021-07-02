#pragma once
#ifndef COLOR_BOUNDS_H

#include <vector>
using namespace std;

vector<int> BLACK_LOWER_BOUND{ 0, 0, 0 };
vector<int> BLACK_UPPER_BOUND{ 180, 255, 30 };

vector<int> WHITE_LOWER_BOUND{ 0, 0, 231 };
vector<int> WHITE_UPPER_BOUND{ 180, 18, 255 };

vector<int> RED1_LOWER_BOUND{ 159, 50, 70 };
vector<int> RED1_UPPER_BOUND{ 180, 255, 255 };

vector<int> RED2_LOWER_BOUND{ 0, 50, 70 };
vector<int> RED2_UPPER_BOUND{ 9, 255, 255 };

vector<int> GREEN_LOWER_BOUND{ 36, 50, 70 };
vector<int> GREEN_UPPER_BOUND{ 89, 255, 255 };

vector<int> BLUE_LOWER_BOUND{ 90, 50, 70 };
vector<int> BLUE_UPPER_BOUND{ 128, 255, 255 };

vector<int> YELLOW_LOWER_BOUND{ 25, 50, 70 };
vector<int> YELLOW_UPPER_BOUND{ 35, 255, 255 };

vector<int> PURPLE_LOWER_BOUND{ 129, 50, 70 };
vector<int> PURPLE_UPPER_BOUND{ 158, 255, 255 };

vector<int> ORANGE_LOWER_BOUND{ 10, 50, 70 };
vector<int> ORANGE_UPPER_BOUND{ 24, 255, 255 };

vector<int> GRAY_LOWER_BOUND{ 0, 0, 40 };
vector<int> GRAY_UPPER_BOUND{ 180, 18, 230 };

#endif