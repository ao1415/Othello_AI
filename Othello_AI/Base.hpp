#pragma once

#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <array>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>

#include <algorithm>
#include <memory>
#include <functional>

using namespace std;

constexpr int Size = 8;
constexpr char Black = 'b';
constexpr char White = 'w';
constexpr char Empty = '-';

const inline bool inside(const int& v) {
	return (0 <= v && v < Size);
}
const inline bool inside(const int& x, const int& y) {
	return (inside(x) && inside(y));
}

struct Point {
	int x = -1;
	int y = -1;

	Point() {}
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	const bool inside() const { return ::inside(x, y); }
	const string toString() const { return to_string(x) + " " + to_string(y); }

	Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }

	void operator+=(const Point& o) { x += o.x; y += o.y; }
	void operator-=(const Point& o) { x -= o.x; y -= o.y; }

	const bool operator==(const Point& o) const { return (x == o.x && y == o.y); }
	const bool operator!=(const Point& o) const { return !(*this == o); }

	const bool operator<(const Point& o) const {
		if (y != o.y)
			return y < o.y;
		return x < o.x;
	}

};

#include "FixedGrid.hpp"
#include "Stopwatch.hpp"
#include "Timer.hpp"

using namespace alib;

enum class Color {
	Black,
	White,
	None
};

using Table = FixedGrid<Color>;
using BoolTable = FixedGrid<bool>;

const inline Color reverse(const Color& color) {
	switch (color)
	{
	case Color::Black: return Color::White;
	case Color::White: return Color::Black;
	default: return Color::None;
	}
}

inline void show(const Table& table) {

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			switch (table[y][x])
			{
			case Color::Black: cerr << Black; break;
			case Color::White: cerr << White; break;
			case Color::None: cerr << Empty; break;
			default:
				break;
			}
		}
		cerr << endl;
	}
}
