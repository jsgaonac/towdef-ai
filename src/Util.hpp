#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <random>

struct Point
{
	int x;
	int y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	bool operator==(const Point &q)
	{
		return x == q.x && y == q.y;
	}
};


void generateRandomCrom(std::vector<bool> &crom, std::size_t length);

int getRandomInteger(int low, int high);

double getRandomReal(double low, double high);

#endif