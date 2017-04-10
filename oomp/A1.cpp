/*1. Create a class named weather report that holds a daily weather report with data
members day_of_month,hightemp,lowtemp,amount_rain and amount_snow. The
constructor initializes the fields with default values: 99 for day_of_month, 999 for
hightemp,-999 for low emp and 0 for amount_rain and amount_snow. Include a
function that prompts the user and sets values for each field so that you can override
the default values. Write a C++/Java/Python program that creates a monthly report.
d) Menu driven program with options to Enter data and Display report*/

#include<iostream>
using namespace std;
#define max 31

class weather_report
{
	private:
	int date[max];
	float high_temp[max], low_temp[max], amt_rain[max], amt_snow[max];
	float avg_high, avg_low, avg_rain, avg_snow;
	
	public:
	int days;
	void input();
	void output();
	void calc_avg();
	weather_report()
	{
		for(int i = 0; i<max; i++) {
			date[i] = 99;
			high_temp[i] = 999;
			low_temp[i] = -999;
			amt_rain[i] = 0;
			amt_snow[i] = 0;
		}
	}
};

void weather_report::input()
{
	cout<<"\nHow many days' weather report do you wish to enter? ";
	cin>>days;
	for(int i = 0; i<days; i++) {
		cout<<"\nEnter day number: ";
		cin>>date[i];
		cout<<"\nEnter amount of rain: ";
		cin>>amt_rain[i];
		cout<<"\nEnter amount of snow: ";
		cin>>amt_snow[i];
		cout<<"\nEnter highest temperature: ";
		cin>>high_temp[i];
		cout<<"\nEnter lowest temperature: ";
		cin>>low_temp[i];
	}
}

void weather_report::calc_avg()
{
	float sum_rain, sum_snow, sum_high, sum_low = 0;
	for(int i = 0; i<days; i++) {
		sum_rain = sum_rain + amt_rain[i];
		sum_snow = sum_snow + amt_snow[i];
		sum_high = sum_high + high_temp[i];
		sum_low = sum_low + low_temp[i];
	}
	avg_rain = sum_rain/days;
	avg_snow = sum_snow/days;
	avg_high = sum_high/days;
	avg_low = sum_low/days;
}

void weather_report::output()
{
	cout<<"\n\nDay\t    Amt_rain\t    Amt_snow\t    High_temp\t    Low_temp";
	for(int i = 0; i<days; i++) {
		cout<<"\n\n"<<date[i]<<"\t\t"<<amt_rain[i]<<"\t\t"<<amt_snow[i]<<"\t\t"<<high_temp[i]<<"\t\t"<<low_temp[i];
	}
	cout<<"\n\nAvg\t\t"<<avg_rain<<"\t\t"<<avg_snow<<"\t\t"<<avg_high<<"\t\t"<<avg_low<<endl<<endl;
}

int main()
{
	weather_report w;
	w.input();
	w.calc_avg();
	w.output();
}
































