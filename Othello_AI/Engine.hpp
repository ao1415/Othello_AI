#pragma once

#include "Base.hpp"

class Engine {
private:

	Table table;
	set<Point> putTable;

	const Color color;
	Color rColor;

	const unsigned char mask(const int& d) const;

	void creatTable();


public:

	Engine(Table&& _table, const Color& _color) : color(_color) {
		table = _table;

		rColor = reverse(color);

		creatTable();

	}

	const bool isPut(const int x, const int y) const {
		return (putTable.find({ x,y }) != putTable.end());
	}
	const bool isPut(const Point& pos) const { return isPut(pos.x, pos.y); }

	const set<Point> getPut() const { return putTable; }

	const Engine&& getNext(const Point& pos) const {

		Table nextTable = table;
		Color nextColor = reverse(color);


		return Engine(move(nextTable), nextColor);
	}

};
