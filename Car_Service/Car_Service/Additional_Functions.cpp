
#include "Additional_Functions.h"

bool CompareCars::operator()(CAR* first_car, CAR* second_car)
{
	return (*first_car)<(*second_car);
}

void paint(CAR* painted_car, c_color new_color)
{
	painted_car->car_color = new_color;
};

c_color descriptColor(string color_text)
{
	if (color_text=="�������")
								return red;
							else if (color_text=="������")
								return yellow;
							else if (color_text=="���������")
								return orange;
							else if (color_text=="�������")
								return green;
							else if (color_text=="�����")
								return blue;
							else if (color_text=="�����")
								return white;
							else if (color_text=="������")
								return black;
							else
								return black;
}

int test(int a)
{
	return a++;
}