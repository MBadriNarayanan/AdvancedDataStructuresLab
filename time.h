#ifndef time_h
#define  time_h
#include<iostream>
 
using namespace std;
 
class Time
{
		int 	hours; 
		int 	minutes;
		int 	seconds;
	public :
		Time();
		Time(int hr,int min,int sec);
		int input();
		int display();
		Time operator + (Time time1);
		Time operator - (Time time1);
		Time operator * (int i);
};
#endif
