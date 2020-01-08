#include"time.h"
Time :: Time()
{
	hours = 10;
	minutes  = 56;
	seconds = 35;
}
Time :: Time(int hr,int min,int sec)
{
	hours = hr;
	minutes = min;
	seconds = sec;
}
int Time :: input()
{
	cout<<"\n\n Input \n\n";
	cout<<" Enter The Hours : ";
	cin>>hours;
	cout<<" Enter The Minutes : ";
	cin>>minutes;
	cout<<" Enter The Seconds : ";
	cin>>seconds;
	return 1;
}
int Time :: display()
{
	cout<<"\n\n Display \n\n";
	cout<<" The Time Is \n\n";
	if((hours<10)&&(minutes<10)&&(seconds<10))
	{
		cout<<" "<<"0"<<hours<<" : "<<"0"<<minutes<<" : "<<"0"<<seconds<<"\n\n";
	}
	else if((hours<10)&&(minutes<10))
	{
		cout<<" "<<"0"<<hours<<" : "<<"0"<<minutes<<" : "<<seconds<<"\n\n";
	}
	else if((hours<10)&&(seconds<10))
	{
		cout<<" "<<"0"<<hours<<" : "<<minutes<<" : "<<"0"<<seconds<<"\n\n";
	}
	else if((seconds<10)&&(minutes<10))
	{
		cout<<" "<<hours<<" : "<<"0"<<minutes<<" : "<<"0"<<seconds<<"\n\n";
	}
	else if(hours<10)
	{
		cout<<" "<<"0"<<hours<<" : "<<minutes<<" : "<<seconds<<"\n\n";
	}
	else if(minutes<10)
	{
		cout<<" "<<hours<<" : "<<"0"<<minutes<<" : "<<seconds<<"\n\n";
	}
	else if(seconds<10)
	{
		cout<<" "<<hours<<" : "<<minutes<<" : "<<"0"<<seconds<<"\n\n";
	}
	else cout<<" "<<hours<<" : "<<minutes<<" : "<<seconds<<"\n\n";
}
Time Time :: operator + (Time time1)
{
	Time    time2;
	    time2.hours = hours + time1.hours;	
		time2.minutes = minutes + time1.minutes;
		time2.seconds = seconds + time1.seconds;
		if(time2.seconds >= 60)
		{
			time2.minutes += 1;
			time2.seconds -= 60;
		 }
		 
		if(time2.minutes >= 60)
		{
			time2.hours += 1;
			time2.minutes -= 60;
		}
		 
		if(time2.hours >= 24)
		{
			time2.hours -= 24;
		}
		return time2;
}
Time Time :: operator - (Time t1)
{
	Time t;
	int totalseconds;
	totalseconds = ((hours - t1.hours) * 3600)+ ((minutes - t1.minutes) * 60) + (seconds - t1.seconds);
	t.minutes = totalseconds / 60;
    t.hours = t.minutes / 60;
    t.minutes = t.minutes % 60;
    t.seconds = totalseconds % 60;
	return t;
} 
Time Time :: operator * (int i)
{
	int 	option;
	int		hr,min,sec,newtime;
	Time 	t;
			cout<<" Enter If The Time To Be Added Is \n";
			cout<<" 1. Hours \n";
			cout<<" 2. Minutes \n";
			cout<<" 3. Seconds \n";
			cout<<" Enter Your Option : ";
			cin>>option;
			switch(option)
			{
				case 1 :
					    {
					    	hr = (hours * 3600 )+(i * 3600);
					    	min = minutes * 60;
					    	sec = seconds;
					    	newtime = hr + min + sec;
					    	t.minutes = newtime / 60;
    						t.hours = t.minutes / 60;
    						t.minutes = t.minutes % 60;
    						t.seconds = newtime % 60;
    						break;

					    }
				case 2 :
					    {
					    	hr = hours * 3600;
					    	min = (minutes * 60) + (i * 60);
					    	sec = seconds;
					    	newtime = hr + min + sec;
					    	t.minutes = newtime / 60;
    						t.hours = t.minutes / 60;
    						t.minutes = t.minutes % 60;
    						t.seconds = newtime % 60;
    						break;

					    }
				case 3 :
					    {
					    	hr = hours * 3600;
					    	min = minutes * 60;
					    	sec = seconds + i;
					    	newtime = hr + min + sec;
					    	t.minutes = newtime / 60;
    						t.hours = t.minutes / 60;
    						t.minutes = t.minutes % 60;
    						t.seconds = newtime % 60;
    						break;

					    }
				default :
						{
							cout<<"\n\n Wrong Input \n\n";
							break;
						}
			}
			return t;
}
