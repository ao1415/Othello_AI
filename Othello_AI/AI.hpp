#pragma once

#include "Engine.hpp"

class AI {
private:

	int fieldSize;
	int lifetime;

	Color color;

	int time;

	Table table;

	Stopwatch sw;

public:

	void first() {

		cin >> fieldSize;

		cin >> lifetime;

		char c;
		cin >> c;

		switch (c)
		{
		case Black: color = Color::Black; break;
		case White: color = Color::White; break;
		default:
			break;
		}

	}

	bool loop() {

		cin >> time;

		string line;
		for (int y = 0; y < fieldSize; y++)
		{
			cin >> line;
			for (int x = 0; x < fieldSize; x++)
			{
				switch (line[x])
				{
				case Black: table[y][x] = Color::Black; break;
				case White: table[y][x] = Color::White; break;
				case Empty: table[y][x] = Color::None; break;
				default:
					break;
				}
			}
		}

		string end;
		cin >> end;

		return (end == "END");
	}

	const string think();

};
