#include <iostream>
#include <iomanip>
#include <ctime>
//#include <chrono>
//#include <thread>
#include <windows.h> //Sleep is defined in windows.h
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
	int h=0,m=0,s=0,m_=0,h_=0; //s,m,h are the original parameters of hours,minutes and secs entered by the user
	cout << "Enter the time for the timer (hh : mm : ss): ";
	cin >> h>> m>> s;
	int s_=s-1;
	m_=m;
	h_=h;
	while (h_||m_||s_) {
		
	for (;s_>=0;s_--)
	{
		system("cls");
		for (int j=1;j<=5;j++)
	    cout << '\t';
	    
		cout <<h_<<" : "<<m_<<" : "<<s_<<'\n';
		//delay(1000);
		Sleep(1000);
		system("cls"); //clears the screen
	}
	if (h_||m_) 
	{
		s_=59;
		m_--;
		if (m<0)
		{
			m_=59;
			h_--;
		}
		
	} 
	
}//while-loop
//PlaySound (D:\\Kalimba.wav,NULL,SND_FILENAME);
Beep(523,500000);
}
