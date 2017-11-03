
#include "Neuron.hpp"
#include "gtest/gtest.h"
#include "Constants.hpp"
#include <cmath>
#include <vector>
#include <random>

using namespace std;

TEST(NeuronTest,OneCycleTest)
{
	const double A = exp(-(DT/TAU));
	const double B = R*(1-A);
	Neuron n;
	n.update(1, 1);
	EXPECT_NEAR(B,n.getPot(),0.001);
	
}

TEST(NeuronTest,NoSpikes)
{
	Neuron n({2});
	int count(0);
	
	for(int i(0);i<1000;++i)
	{
		vector<int> spike = n.update(i,1);
		if(!spike.empty())
		{
			++count;
		}
	}
	
	EXPECT_EQ(count,0);
}

TEST(NeuronTest,spike)
{

	Neuron n({2});
	int count(0);
	
	for(int i(0);i<1000;++i)
	{
		std::vector<int> spike = n.update(i,1.1);
		if(!spike.empty())
		{
			++count;
		}
	}
	
	EXPECT_NE(count,0);	
}

TEST(TwoNeuronTest,Link)
{
	Neuron N1({1});
	Neuron N2({5});
	
	double N2totpot(0);
	
	for(int i(0);i<500;i++)
	{
		double Iext = 1.1;
		
		vector<int> tar1(N1.update(i,Iext));
			
		if(!tar1.empty())
		{
			N2.recieve(i,D,false);
		}
		
		vector<int> tar2(N2.update(i,0));
		
		N2totpot += N2.getPot();
		
	}
	
	EXPECT_GT(N2totpot,0);	
}

TEST(Main,ConnectionsGeneration)
{
	const unsigned int nbrENeurons(10000);
	const unsigned int nbrINeurons(2500);
	
	//initialisation----------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	const unsigned int nbrNeurons = nbrENeurons + nbrINeurons; //simulation of 12'500 neurons
	const unsigned int inhibitoryBegin (nbrENeurons); // 10'000 exitatory and 2'500 inhibitory : the firste inhibitory is brain[10000]
	
	const unsigned int nbrEConnections = nbrENeurons/10; //10 percent connection
	const unsigned int nbrIConnections = nbrINeurons/10;
	
	array<Neuron,nbrNeurons> brain; 
	
	for(unsigned int i(inhibitoryBegin);i<brain.size();i++) //set the inhibitory neurons
	{
		brain[i].setNeuronType(true);
	}
	
	std::random_device rd;    
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni1(0,inhibitoryBegin-1);
	std::uniform_int_distribution<int> uni2(inhibitoryBegin,brain.size()-1); //set the random number generators
	
	for(unsigned int n(0);n<brain.size();n++) //every neuron recieves the connection of 1000 exitatory neuron and 250 inhibitory ones (10 percent connection)
	{
		for(unsigned int i(0);i<nbrEConnections;i++)
		{
			unsigned int target;
			
			do
			{
				target = uni1(rng);
				
			} while(target == n);
			
			brain[target].addTarget(n);
		}
		
		for(unsigned int j(0);j<nbrIConnections;j++)
		{
			unsigned int target;
			
			do
			{
				target = uni2(rng);
				
			} while(target == n);
			
			brain[target].addTarget(n);
		}
	}
	
	
}

