// Car_Service.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <Windows.h>
#include <string>
#include "Models.h"
#include "Additional_Functions.h"
#include <tchar.h>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <Windows.h>
#include <functional>
#include <time.h>
#include <thread>
#include <mutex>

using namespace std;


void RepairAll(list<CAR*>::iterator first,list<CAR*>::iterator last)
{
	
	list<CAR*>::iterator iter;
	for(iter=first;iter!=last;iter++)
				{	
					int err;
					CAR* temp_car=*iter;
					//cout<<"Идет ремонт автомобиля "<<temp_car->GetModel()<<" Хозяин: "<<temp_car->GetName()<<endl; 
					err = temp_car->Repair();
					
				}				
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(0,"rus");
	vector<thread> mechs;
	list<CAR*> Park;
	list<KIA> Park_KIA;
	list<CAR*>::iterator iter;
	list<CAR*>::iterator iter2;
	FILE* text_file;
	string name_temp,model_string_temp,color_temp_string;
	long body_temp=0,engine_temp=0,transmission_temp=0,model_temp=0,computer_temp=0,number_temp=0;
	c_color color_temp;

	short choise;
	short mechanics_number;
	CAR* test_car;
	CAR* test_car2;
	char scanstr1[5],scanstr2[10],scanstr3[10],scanstr4[10],scanstr5[10],scanstr6[10],scanstr7[10];
	thread mech;

	while(1)
		{
			cout<<"		МЕНЮ"<<endl;
			cout<<"1.Вывести парк на экран"<<endl;
			cout<<"2.Добавить автомобиль в парк"<<endl;
			cout<<"3.Удалить автомобиль из парка"<<endl;
			cout<<"4.Прочитать список автомобилей парка из текстового файла"<<endl;
			cout<<"5.Записать список автомобилей парка в текстовый файл"<<endl;
			cout<<"6.Сортировать автомобили в парке по имени"<<endl;
			cout<<"7.Отправить автомобиль на ремонт"<<endl;
			cout<<"8.Полный ремонт всех автомобилей в парке"<<endl;
			cout<<"9.Отправить автомобиль на покраску"<<endl;
			cout<<"10.Выход"<<endl;
			cin>>choise;
			if(choise!=10)
			{
					switch(choise)
						{
					case 1:
						if (Park.empty())
							cout<<"В парке нет автомобилей"<<endl<<endl;
						else
							{
								number_temp = 1;
								for (iter=Park.begin();iter!=Park.end();iter++)
								{
						
									CAR* temp_car=*iter;
									cout<<number_temp<<".";
									cout<<temp_car->GetModel()<<"  ";
									cout<<temp_car->GetName()<<"  ";
									cout<<"Состояние кузова = "<<temp_car->GetBodyStatus(true)<<" ";
									cout<<"Состояние двигателя = "<<temp_car->GetEngineStatus(true)<<" ";
									cout<<"Состояние коробки передач = "<<temp_car->GetTransmissionStatus(true)<<" ";
									cout<<"Цвет = "<<temp_car->GetColor()<<" ";
									if (temp_car->GetModel() == "BMW")
										cout<<"Состояние бортового компьютера = "<<((BMW*)temp_car)->GetComputerStatus(true);
									cout<<endl;
									number_temp++;
								}
							}
							break;
					case 2:
							cout<<"Введите модель:"<<endl;
							cout<<"1.LADA"<<endl;
							cout<<"2.KIA"<<endl;
							cout<<"3.BMW"<<endl;
							cin>>model_temp;
							cout<<"Введите имя владельца"<<endl;
							cin>>name_temp;
							cout<<"Введите состояние кузова"<<endl;
							cin>>body_temp;
							cout<<"Введите состояние двигателя"<<endl;
							cin>>engine_temp;
							cout<<"Введите состояние коробки передач"<<endl;
							cin>>transmission_temp;
							cout<<"Введите цвет"<<endl;
							cin>>color_temp_string;
							color_temp = descriptColor(color_temp_string);
							if (model_temp==3)
								{
									cout<<"Введите состояние компьютера"<<endl;
									cin>>computer_temp;
								}
							if(model_temp==1)
								Park.push_back(new LADA(name_temp,body_temp,engine_temp,transmission_temp,color_temp));
							else if (model_temp==2)
								Park.push_back(new KIA(name_temp,body_temp,engine_temp,transmission_temp,color_temp));
							else if (model_temp==3)
								Park.push_back(new BMW(name_temp,body_temp,engine_temp,transmission_temp,computer_temp,color_temp));
							else 
								break;
							cout<<"Автомобиль добавлен в парк"<<endl;
							break;
						case 3:
							cout<<"Введите имя владельца"<<endl;
							cin>>name_temp;
							iter = find_if(Park.begin(),Park.end(),FindEqualCar(name_temp));
							if (iter != Park.end())
							{
								cout<<"Автомобиль владельца "<<name_temp<<" выгоняется из парковки"<<endl;
								Park.remove(*iter);
								cout<<"Автомобиль успешно выгнан из парковки"<<endl;
							}
							else
								cout<<"Автомобиль с таким именем владельца не найден"<<endl;
							break;
						case 4:
							fopen_s(&text_file,"park_list.txt","r");
							
							Park.clear();
							while(!feof(text_file))
								{
								
									fscanf(text_file,"%s%s%s%s%s%s%s",scanstr1,scanstr2,scanstr3,scanstr4,scanstr5,scanstr6,scanstr7);//,model_string_temp,name_temp,body_temp,engine_temp,transmission_temp);
									
									model_string_temp = string(scanstr2);
									name_temp = string(scanstr3);
									body_temp = atol(scanstr4);
									engine_temp = atol(scanstr5);
									transmission_temp = atol(scanstr6);
									color_temp = descriptColor(scanstr7);
									if(model_string_temp=="BMW")
										{
											
										fscanf(text_file,"%s",scanstr6);
										computer_temp = atol(scanstr6);
										}
									fscanf(text_file,"\n");
									if(model_string_temp=="LADA")
											Park.push_back(new LADA(name_temp,body_temp,engine_temp,transmission_temp,color_temp));
									else if (model_string_temp=="KIA")
											{
											Park.push_back(new KIA(name_temp,body_temp,engine_temp,transmission_temp,color_temp));
											Park_KIA.push_back(KIA(name_temp,body_temp,engine_temp,transmission_temp,color_temp));
											}
									else if (model_string_temp=="BMW")
											Park.push_back(new BMW(name_temp,body_temp,engine_temp,transmission_temp,computer_temp,color_temp));
									else 
										break;
								}
							fclose(text_file);
							break;
						case 5:
							fopen_s(&text_file,"park_list.txt","w");
							number_temp=1;
							for(iter=Park.begin();iter!=Park.end();iter++)
								{
									CAR* temp_car = *iter;
									model_string_temp = temp_car->GetModel();
									name_temp = temp_car->GetName();
									body_temp = (long)(temp_car->GetBodyStatus(false));
									engine_temp = (long)(temp_car->GetEngineStatus(false));
									transmission_temp = (long)(temp_car->GetTransmissionStatus(false));
									color_temp_string = temp_car->GetColor();
									if(!(model_string_temp=="BMW"))
										fprintf_s(text_file,"%d. %s %s %d %d %d %s\n",number_temp, model_string_temp.c_str(),name_temp.c_str(),body_temp,engine_temp,transmission_temp,color_temp_string);
									else
										{
										computer_temp = (long)((BMW*)temp_car)->GetComputerStatus(false);
										fprintf_s(text_file,"%d. %s %s %d %d %d %d %s\n",number_temp, model_string_temp.c_str(),name_temp.c_str(),body_temp,engine_temp,transmission_temp,computer_temp,color_temp_string);
										}
									number_temp++;
								}
							fclose(text_file);
							break;
						case 6:
							iter = Park.begin();
							test_car = *iter;
							iter++;
							test_car2 = *iter; 
							//sort(Park.begin(),Park.end());
							//sort(Park.begin(),Park.end());
							Park.sort(CompareCars());
							break;
						case 7:
							cout<<"Введите имя владельца"<<endl;
							cin>>name_temp;
							iter = find_if(Park.begin(),Park.end(),FindEqualCar(name_temp));	
							if (iter != Park.end())
								{
								cout<<"Идет ремонт"<<endl;
								(*iter)->Repair();
								cout<<"Автомобиль успешно отремонтирован"<<endl;
								}
							else
								cout<<"Автомобиль с таким именем владельца не найден"<<endl;
							break;
						case 8:
							
							cout<<"Сколько механиков отправить на ремонт автомобилей?"<<endl;
							cin>>mechanics_number;
							if (mechanics_number==1)
								for(iter=Park.begin();iter!=Park.end();iter++)
								{
									CAR* temp_car=*iter;
									//cout<<"Идет ремонт автомобиля "<<temp_car->GetModel()<<" Хозяин: "<<temp_car->GetName()<<endl; 
									temp_car->Repair();
									//cout<<"Автомобиль успешно отремонтирован"<<endl;
								}
							else
								if ((mechanics_number>1)&&(mechanics_number<=8))
								{
									/*
									mechs.push_back(thread(RepairAll,Park.begin(),Park.end()));
									mechs.push_back(thread(RepairAll,Park.begin(),Park.end()));
									mechs.push_back(thread(RepairAll,Park.begin(),Park.end()));
									mechs.push_back(thread(RepairAll,Park.begin(),Park.end()));
									*/
									int park_size = Park.size();
									int step = park_size/mechanics_number;
									int current_step = step;
									int i,j;
									for(i=1;i<=mechanics_number;i++)
									{
										if (i==1)
										{
										iter = Park.begin();
										iter2 = iter;
										for (j=0;j<current_step;j++)
										{
											if (iter2!=Park.end())
												iter2++;
											else
												break;
										}
										mechs.push_back(thread(RepairAll,iter,iter2));
										iter = iter2;
										}
										if((i>1)&&(i<mechanics_number))
										{
											for (int j=current_step;j<(current_step+step);j++)
												{
													if (iter2!=Park.end())
														iter2++;
													else
														break;
												}
											current_step = current_step + step;
											mechs.push_back(thread(RepairAll,iter,iter2));
											iter = iter2;

										}
										if(i==mechanics_number)
										{
											mechs.push_back(thread(RepairAll,iter,Park.end()));
										}
									}
										
									for_each(mechs.begin(),mechs.end(),mem_fn(&thread::join));
									cout<<"Все автомобили успешно отремантированы"<<endl;
									mechs.clear();
								}
							break;
						case 9:
							cout<<"Введите имя владельца"<<endl;
							cin>>name_temp;
							
							iter = find_if(Park.begin(),Park.end(),FindEqualCar(name_temp));
							if (iter != Park.end())
							{
								cout<<"Введите цвет"<<endl;
								cin>>color_temp_string;
								paint(*iter,descriptColor(color_temp_string));
							}
							else
								cout<<"Автомобиль с таким именем владельца не найден"<<endl;
							break;
						default:
							break;
						}
			}
			else
				break;
		}
		
	return 0;
}

