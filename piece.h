#pragma once
#include <assert.h>
#include <string>

using namespace std;

class piece
{
public:
	enum Type
	{
		King = 'k',
		Queen = 'q',
		Rook = 'r',
		Bishop = 'b',
		Knight = 'n',
		Pawn = 'p'
	};
	enum Color { White, Black };

	piece(Type typeIn, Color colorIn) {
		color = colorIn;
		type = typeIn;
		assignValue();
	};
	~piece() {};

	const int getValue() { return value; };
	void setValue(int valIn) { value = valIn; };
	
	char getName() { return type; };
	char getColor() { return color; };

	void promote(Type typeIn) 
	{
		assert(typeIn != Pawn);
		type = typeIn;
		value = assignValue();
	};
private:

	char value;
	Type type;
	Color color;
	char assignValue()
	{
		switch (type)
		{
		case King:
			return value = 255;
		case Queen:
			return value = 9;
		case Rook:
			return value = 5;
		case Bishop:
			return value = 3;
		case Knight:
			return value = 3;
		case Pawn:
			return value = 1;
		}
	}
};

