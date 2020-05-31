#ifndef MODELS
#define MODELS

#include <string>
#include <thread>
#include <mutex>
#include <iostream>
#include <memory>
#include "Owner.h"

using namespace std;

	enum c_color
		{
			red = 1,
			yellow = 2,
			orange = 3,
			green = 4,
			blue = 5,
			black = 6,
			white = 7
		};

class CAR
	{
		
		
	protected:
		string model;
		string name;
		long body;
		long body_max;
		long engine;
		long engine_max;
		c_color car_color;
		enum trans
			{
				manual = 1,
				automatic = 2
			};
		shared_ptr<Owner> Car_owner;
		mutex protector;
public:		
		explicit CAR();
		explicit CAR(const CAR& test);
		CAR(string new_name, long new_body, long new_engine, c_color car_color);
		string GetModel();
		string GetName();
		void SetName(string new_name);
		double GetBodyStatus(bool percent);
		double GetEngineStatus(bool percent);
		string GetColor();
		virtual double GetTransmissionStatus(bool percent)=0;
		virtual int Repair()=0;
		friend void paint(CAR* painted_car,c_color new_color);
		bool operator ==(CAR& compared_CAR)
		{
			return name == compared_CAR.name;
		}
		bool operator ==(string searching_name)
		{
			return name == searching_name;
		}
		bool operator !=(CAR& compared_CAR)
		{
			return name != compared_CAR.name;
		}
		bool operator !=(string searching_name)
		{
			return name != searching_name;
		}
		bool operator >(CAR& compared_CAR)
			{
				if (name > compared_CAR.name)
					return true;
				else
					return false;
			}
		bool operator <(CAR& compared_CAR)
			{
				if (name < compared_CAR.name)
					return true;
				else
					return false;
			}
	};

class LADA : public CAR
{
	long mechanic_transmission;
	long mechanic_transmission_max;
public:
	explicit LADA();
	explicit LADA(string new_name, long new_body, long new_engine, long new_transmission, c_color new_color);
	int Repair();
	double GetTransmissionStatus(bool percent);
};

class KIA : public CAR
	{
			long automatic_transmission;
			long automatic_transmission_max;

	public:
	 explicit 	KIA();
	 explicit	KIA(string new_name,long new_body, long new_engine, long new_transmission, c_color new_color);
		int Repair();
		double GetTransmissionStatus(bool percent);
	};

class BMW : public CAR
{
	long automatic_transmission;
	long automatic_transmission_max;
	long computer;
	long computer_max;
public:
	explicit BMW();
	explicit BMW(string new_name,long new_body, long new_engine, long new_transmission, long new_computer, c_color new_color);
	int Repair();
	double GetTransmissionStatus(bool percent);
	double GetComputerStatus(bool percent);
};
#endif