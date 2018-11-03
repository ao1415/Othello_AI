#pragma once

#include "Engine.hpp"

class AI {
private:

	int fieldSize;
	int lifetime;

	int turn = 0;

	Color color;

	int time;

	Table table;

	Stopwatch sw;
	XorShift random;

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

		turn = 0;

		cin >> time;

		string line;
		for (int y = 0; y < fieldSize; y++)
		{
			cin >> line;
			for (int x = 0; x < fieldSize; x++)
			{
				switch (line[x])
				{
				case Black:
					table[y][x] = Color::Black;
					turn++;
					break;
				case White:
					table[y][x] = Color::White;
					turn++;
					break;
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

	const pair<double, Point> minmax(const Engine& engine, const int turn, const int depth);

	const double evaluation(const Engine& engine);

};
