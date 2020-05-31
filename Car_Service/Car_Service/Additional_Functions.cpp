
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
	if (color_text=="Красный")
								return red;
							else if (color_text=="Желтый")
								return yellow;
							else if (color_text=="Оранжевый")
								return orange;
							else if (color_text=="Зеленый")
								return green;
							else if (color_text=="Синий")
								return blue;
							else if (color_text=="Белый")
								return white;
							else if (color_text=="Черный")
								return black;
							else
								return black;
}

int test(int a)
{
	return a++;
}