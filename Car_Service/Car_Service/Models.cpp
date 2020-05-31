#include "Models.h"

using namespace std;

CAR::CAR()
		{
			
		}
CAR::CAR(const CAR& test)
{

}
CAR::CAR(string new_name, long new_body, long new_engine, c_color new_color)
		{
			name = new_name;
			body = new_body;
			engine = new_engine;
			car_color = new_color;
		}


string CAR::GetModel()
	{
		return model;
	}
string CAR::GetName()
		{
			return name;
		}
double CAR::GetBodyStatus(bool percent)
		{
			if(percent)
			{
				double status = (double)body/body_max*100;
				return status;
			}
			else
				return body;
		}
string CAR::GetColor()
{
	switch(car_color)
	{
	case 1:
		return "Красный";
	case 2:
		return "Жёлтый";
	case 3:
		return "Оранжевый";
	case 4:
		return "Зеленый";
	case 5:
		return "Синий";
	case 6:
		return "Белый";
	case 7:
		return "Черный";
	default:
		return "Черный";
	}
}
void CAR::SetName(string new_name)
		{
			name = new_name;			
		}
double CAR::GetEngineStatus(bool percent)
		{
			if (percent)
			{
				double status = (double)engine/engine_max*100;
				return status;
			}
			else
				return engine;
		}


//класс LADA
LADA::LADA()
	{
		model = "LADA";
		name = "Неизвестно";
		body_max = 10000;
		engine_max = 10000;
		mechanic_transmission_max = 10000;
		car_color = black;
	}
LADA::LADA(string new_name, long new_body, long new_engine, long new_transmission, c_color new_color)
		{
			model = "LADA";
			body_max = 10000;
			engine_max = 10000;
			mechanic_transmission_max = 10000;
			name = new_name;
			body = new_body;
			engine = new_engine;
			mechanic_transmission = new_transmission;
			car_color = new_color;
		}
inline int LADA::Repair()
{
	lock_guard<mutex> guardian(protector);
	cout<<"Механик отправлен на ремонт автомобиля "<<model<<" Хозяин: "<<name<<endl; 
	if ((body==body_max)&&(engine==engine_max)&&(mechanic_transmission==mechanic_transmission_max))	//если автомобиль в исправном состоянии, то завершаем функцию с ошибкой
		{
		cout<<"Ошибка! Автомобиль "<<model<<" Хозяин: "<<name<<" не нуждался в ремонте"<<endl;
		return -1;
		}

	for(;body<body_max;body++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	for(;engine<engine_max;engine++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	for(;mechanic_transmission<mechanic_transmission_max;mechanic_transmission++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	
	cout<<"Автомобиль "<<model<<" Хозяин: "<<name<<" успешно отремонтирован"<<endl;		
	return 0;
}
double LADA::GetTransmissionStatus(bool percent)
{
	if(percent)
	{
		double status = (double)mechanic_transmission/mechanic_transmission_max*100;
		return status;
	}
	else
		return mechanic_transmission;
	
}

//класс KIA
KIA::KIA()
{
	model = "KIA";
	name = "Неизвестно";
	body_max = 20000;
	engine_max = 20000;
	automatic_transmission_max = 20000;
	car_color = black;
}
KIA::KIA(string new_name, long new_body, long new_engine, long new_transmission, c_color new_color)
		{
			model = "KIA";
			body_max = 20000;
			engine_max = 20000;
			automatic_transmission_max = 20000;
			name = new_name;
			body = new_body;
			engine = new_engine;
			automatic_transmission = new_transmission;
			car_color = new_color;
		}
int KIA::Repair()
{
	lock_guard<mutex> guardian(protector);
	cout<<"Механик отправлен на ремонт автомобиля  "<<model<<" Хозяин: "<<name<<endl; 
	if ((body==body_max)&&(engine==engine_max)&&(automatic_transmission==automatic_transmission_max))	//если автомобиль в исправном состоянии, то завершаем функцию с ошибкой
		{
		cout<<"Ошибка! Автомобиль "<<model<<" Хозяин: "<<name<<" не нуждается в ремонте"<<endl;
		return -1;
		}

	for(;body<body_max;body++)
		{
			int j;
			for (j=0;j<10000;j++);
		};
	for(;engine<engine_max;engine++)
		{
			int j;
				for (j=0;j<10000;j++);
		}
	for(;automatic_transmission<automatic_transmission_max;automatic_transmission++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	
		cout<<"Автомобиль "<<model<<" Хозяин: "<<name<<" успешно отремонтирован"<<endl;				
	return 0;
}
double KIA::GetTransmissionStatus(bool percent)
{
	if(percent)
	{
		double status = (double)automatic_transmission/automatic_transmission_max*100;
		return status;
	}
	else
		return automatic_transmission;
	
}

//класс BMW
BMW::BMW()
{
	model = "BMW";
	name = "Неизвестно";
	body_max = 30000;
	engine_max = 30000;
	automatic_transmission_max = 30000;
}
BMW::BMW(string new_name, long new_body, long new_engine, long new_transmission, long new_computer, c_color new_color)
		{
			model = "BMW";
			body_max = 30000;
			engine_max = 30000;
			automatic_transmission_max = 30000;
			computer_max = 30000;
			name = new_name;
			body = new_body;
			engine = new_engine;
			automatic_transmission = new_transmission;
			computer = new_computer;
			car_color = new_color;
		}
int BMW::Repair()
{
	lock_guard<mutex> guardian(protector);
	cout<<"Механик отправлен на ремонт автомобиля  "<<model<<" Хозяин: "<<name<<endl; 

	if ((body==body_max)&&(engine==engine_max)&&(automatic_transmission==automatic_transmission_max)&&(computer==computer_max))	//если автомобиль в исправном состоянии, то завершаем функцию с ошибкой
	{
		cout<<"Ошибка! Автомобиль "<<model<<" Хозяин: "<<name<<" не нуждается в ремонте"<<endl;
		return -1;
	}
	for(;body<body_max;body++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	for(;engine<engine_max;engine++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	for(;automatic_transmission<automatic_transmission_max;automatic_transmission++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	for(;computer<computer_max;computer++)
	{
		int j;
		for (j=0;j<10000;j++);
	}
	cout<<"Автомобиль "<<model<<" Хозяин: "<<name<<" успешно отремонтирован"<<endl;				
	return 0;
}
double BMW::GetTransmissionStatus(bool percent)
{
	if(percent)
	{
		double status = (double)automatic_transmission/automatic_transmission_max*100;
		return status;
	}
	else
		return automatic_transmission;
}
double BMW::GetComputerStatus(bool percent)
{
	if(percent)
	{
		double status = (double)computer/computer_max*100;
		return status;	
	}
	else
		return computer;
}



