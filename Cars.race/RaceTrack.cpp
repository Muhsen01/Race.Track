#include <iostream>
#include <windows.h>
#include <vector>
#include "Position.H"
#include "Lane.h"
#include "Car.h"
#include "time.h"

using namespace std;

bool gameOver = false;

void setCursor(Position position);

const int startLine = 24;
vector<Lane*> lanes;

// create cars
Car car1(206);
Car car2(219);
Car car3(64);
Car car4(156);
Car car5(178);
Car car6(94);

// create lanes and add cars
Lane lane1(1, 10, 20, car1, "Lane1");
Lane lane2(21, 30, 40, car2, "Lane2");
Lane lane3(41, 50, 60, car3, "Lane3");
Lane lane4(61, 70, 80, car4, "Lane4");
Lane lane5(81, 90, 100, car5, "Lane5");
Lane lane6(101, 110, 120, car6, "Lane6");


int main()
{
	// add lanes with cars to the vector
	lanes.push_back(&lane1);
	lanes.push_back(&lane2);
	lanes.push_back(&lane3);
	lanes.push_back(&lane4);
	lanes.push_back(&lane5);
	lanes.push_back(&lane6);

	// position cars at staring point 
	for (Lane* pLane : lanes)
	{
		Position position(pLane->getCntr(), startLine);
		Car* car = pLane->getCar();
		car->setPosition(position);

		setCursor(position);
		cout << char(car->getIcon());
	}

	// draw vertical alne markers
	for (int i = 1; i <= 5; i++)
	{
		for (int j = startLine; j > 0; j--)
		{
			setCursor(Position(lanes[i]->getLBnd(), j));
			cout << "|";
		}

	}

	while (true) // Game Loop
	{
		srand(time(0));

		for (Lane* lane : lanes)
		{
			int jump = rand() % 4;
			int leftRight = rand() % 3;
			int posNeg = rand() % 10;
			if (posNeg <= 2)
			{
				jump *= -1;
				leftRight *= -1;
			}

			Car* car = lane->getCar();
			Position oldPosition = car->getPosition();
			setCursor(oldPosition);            // erase previous car position on screen
			cout << " ";

			// calculate new car position
			Position newPosition(oldPosition.col -= leftRight, oldPosition.row -= jump);

			// prevent cars from going backward, behind starting line

			car->setPosition(newPosition);             // save new position in car object
			setCursor(newPosition);						// position to new position on screen
			cout << char(car->getIcon());            // draw car

			// cheaking for winner
			if (newPosition.row <= 0)
			{
				setCursor(newPosition);
				cout << "WINNER " + lane->getName();
				gameOver = true;
				break;
			}

			// cheacking for violation
			if (newPosition.col <= lane->getLBnd() || newPosition.col >= lane->getRbnd())
			{
				setCursor(newPosition);
				// or we can use this code: setCursor(lane->getCar()->getPosition());
				cout << "Lane Vioaltion in: " + lane->getName();
				gameOver = true;
				break;
			}

		}

		Sleep(500);

		if (gameOver)
		break;
		
	}
}


//**************************
// Function Definition
//**************************

void setCursor(Position position)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { position.col, position.row };
	SetConsoleCursorPosition(hConsole, coord);
}