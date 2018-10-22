#pragma once

#include "Base.hpp"

class Engine {
private:

	Table table;
	set<Point> putTable;

	Color color;
	Color rColor;

	const unsigned char mask(const int& d) const;

	void creatTable();


public:

	Engine() {}

	Engine(Table&& _table, const Color& _color) {
		table = _table;

		color = _color;
		rColor = reverse(color);

		creatTable();
	}

	const Table& getTable() const { return table; }

	const bool isPut(const int x, const int y) const {
		return (putTable.find({ x,y }) != putTable.end());
	}
	const bool isPut(const Point& pos) const { return isPut(pos.x, pos.y); }

	const set<Point>& getPut() const { return putTable; }

	Engine getNext(const Point& pos) const {

		Table nextTable = table;
		Color nextColor = reverse(color);

		return Engine(move(nextTable), nextColor);
	}

};
