#pragma once
#include "Position.h"

class Car
{

private:
	char icon;
	Position position;

public:
	Car();
	Car(char icon);
	void setIcon(char icon);
	void setPosition(Position pos);

	char getIcon();
	Position getPosition();

};

