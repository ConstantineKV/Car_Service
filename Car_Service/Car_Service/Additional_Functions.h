#ifndef ADDITIONAL_FUNCTIONS
#define ADDITIONAL_FUNCTIONS
#include "Models.h"
#include <string>

class CompareCars
{
public:
	bool operator()(CAR* first_car, CAR* second_car);
};

class FindEqualCar
{
	string name;
public:
	FindEqualCar(string new_name)
	{
		name = new_name;
	}
	bool operator()(CAR* searching_car)
	{
		return name == (*searching_car).GetName();
	}
};

void paint(CAR* painting_car, c_color new_color);
c_color descriptColor(string color_text);
inline int test(int a);

#endif
