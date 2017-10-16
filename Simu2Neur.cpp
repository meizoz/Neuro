#include "Neuron.hpp"
#include "Constants.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
using namespace std;

int main()
{
	array<Neuron,2> brain;
	Neuron N1({1});
	Neuron N2;
	
	brain[0] = N1;
	brain[1] = N2;
	
	int nbrCycles(1000); //steps of simulation, multiplie by DT (Constants.hpp) to find duration of simulation
	
	ofstream file1;
	file1.open("potentialsNpre.txt");
	ofstream file2;
	file2.open("potentialsNpost.txt");
	
	for(int i(0);i<nbrCycles;i++)
	{
		double Iext = 1;
		
		vector<int> tar1(N1.update(i,Iext));
			
		if(!tar1.empty())
		{
			N2.recieve(i,D);
		}
		
		vector<int> tar2(N2.update(i,0));
		
		
		if(file1.is_open())
		{
			file1<<N1.getPot()<<endl;
		}
		
		if(file2.is_open())
		{
			file2<<N2.getPot()<<endl;
		}
		
	}
	
	
	file1.close();
	file2.close();
}
