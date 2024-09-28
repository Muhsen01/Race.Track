#include "Lane.h"


Lane::Lane() {};
Lane::Lane(int lbnd, int cntr, int rbnd, Car car, string name)

{
	LBnd = lbnd;
	Cntr = cntr;
	RBnd = rbnd;
	this->car = car;
	this->name = name;

}

void Lane::setLBnd(int lbnd) { LBnd = lbnd; }
void Lane::setCntr(int cntr) { Cntr = cntr; }
void Lane::setRBnd(int rbnd) { RBnd = rbnd; }
void Lane::setCar(Car car) { this->car = car; }



int Lane::getLBnd() { return LBnd; }
int Lane::getCntr() { return Cntr; }
int Lane::getRbnd() { return RBnd; }
Car* Lane::getCar() { return &car; }
string Lane::getName() { return name; }
