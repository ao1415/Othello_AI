#include "Engine.hpp"

const unsigned char Engine::mask(const int& d) const {
	switch (d)
	{
	case 0: return 0b00000011;
	case 1: return 0b00001100;
	case 2: return 0b00110000;
	case 3: return 0b11000000;
	default: return 0b11111111;
	}
}

void Engine::creatTable() {

	FixedGrid<unsigned char> lookup1(0);
	FixedGrid<unsigned char> lookup2(0);

	const array<int, 4> dx1{ -1,0,1,-1 };
	const array<int, 4> dy1{ -1,-1,-1,0 };

	const array<int, 4> dx2{ 1,-1,0,1 };
	const array<int, 4> dy2{ 0,1,1,1 };

	const auto search = [&](const int& x, const int& y, const array<int, 4>& dx, const array<int, 4>& dy, FixedGrid<unsigned char>& lookup) {

		if (table[y][x] == color)
		{
			lookup[y][x] = 0b01010101;
		}
		else if (table[y][x] == Color::None)
		{
			for (int d = 0; d < 4; d++)
			{
				const Point pos(x + dx[d], y + dy[d]);

				if (pos.inside())
				{
					const auto bit = mask(d);

					if (table[pos] != color && (lookup[pos] & bit) > 0)
					{
						putTable.insert(Point(x, y));
					}
				}
			}
		}
		else
		{
			for (int d = 0; d < 4; d++)
			{
				const Point pos(x + dx[d], y + dy[d]);

				if (pos.inside())
				{
					const auto bit = mask(d);

					lookup[y][x] |= (lookup[pos] & bit);
				}
			}
		}

	};

	for (int y = 0; y < Size; y++)
	{
		for (int x = 0; x < Size; x++)
		{
			search(x, y, dx1, dy1, lookup1);
			search(Size - 1 - x, Size - 1 - y, dx2, dy2, lookup2);
		}
	}

}
