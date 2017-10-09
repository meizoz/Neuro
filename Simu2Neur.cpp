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
	
	int nbrCycles(50);
	
	for(int i(0);i<nbrCycles;i++)
	{
		for(int j(0);j<brain.size();j++)
		{
			vector<int> tar(brain[j].update(i,0));
			
			if(!tar.empty())
			{
				for(int k(0);k<tar.size();k++)
				{
					brain[tar[k]].recieve(i+D);
				}
			}
		}
	}
	
}
