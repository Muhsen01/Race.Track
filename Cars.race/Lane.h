#pragma once
#include "Car.h"
#include "Position.h"
#include<string>
using namespace std;


class Lane
{
private:
		int LBnd;
		int Cntr;
		int RBnd;
		Car car;
		string name;

public:
		Lane();
		Lane(int lbnd, int cntr, int rbnd, Car car, string name);

		void setLBnd(int lbnd);
		void setCntr(int cntr);
		void setRBnd(int rbnd);
		void setCar(Car car);
		string getName();

		int getLBnd();
		int getCntr();
		int getRbnd();
		Car* getCar();

};



