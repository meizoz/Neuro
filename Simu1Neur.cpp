#include "Neuron.hpp"
#include "Constants.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Neuron n1;
	
	int numbCycles = 50;
	
	double current(0);
	cout<<"enter the external current : ";
	cin>>current;
	
	double inf;
	double sup; //inferior and superior limits in time of the current
	
	do
	{
		cout<<"enter the start time of that current : ";
		cin>>inf;
		cout<<"enter the stop time of that current : ";
		cin>>sup;
	}while(inf < 0 or inf > sup or sup > numbCycles*DT);
	
	ofstream file;
	file.open("potentialsN1.txt");
	
	for(int i(0);i<=numbCycles;i++)
	{
		double extCur(0);
		if(i*DT >= inf and i*DT < sup)
		{
			extCur = current;
		}
		
		double t(i*DT);
		n1.update(t, extCur);
		
		if(file.is_open())
		{
			file<<n1.getPot()<<" ";
		}
	}
	
	file.close();
	
	return 0;
}
