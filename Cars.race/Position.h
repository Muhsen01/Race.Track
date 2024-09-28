#pragma once

struct Position

{

	int col = 0;
	int row = 0;
	Position() {};
	Position(int c, int r)

	{
		col = c;
		row = r;
	}
};