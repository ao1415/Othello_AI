#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AI {
public:

	void first() {

		cin >> fieldSize;

		cin >> lifetime;

		cin >> color;

		table.resize(fieldSize);
		for (auto& t : table) t.resize(fieldSize);

	}

	bool loop() {

		cin >> time;

		string line;
		for (int y = 0; y < fieldSize; y++)
		{
			cin >> line;
			for (int x = 0; x < fieldSize; x++)
			{
				table[y][x] = line[x];
			}
		}

		string end;
		cin >> end;

		return (end == "END");
	}

	string think() {

		int maxScore = 0;
		string com = "0 0";

		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				int count = isReverse(x, y, color);
				cerr << count << endl;
				if (count > maxScore)
				{
					maxScore = count;
					com = to_string(x) + " " + to_string(y);
				}
			}
		}

		return com;
	}

private:

	int fieldSize;
	int lifetime;

	char color;

	int time;

	vector<vector<char>> table;

	int isReverse(int _x, int _y, char color)
	{
		int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
		int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };

		char rColor = reverseColor(color);

		if (table[_y][_x] != '-') return -1;

		int count = 0;

		for (int d = 0; d < 8; d++)
		{
			int x = _x + dx[d];
			int y = _y + dy[d];

			if (inside(x, y))
			{
				if (table[y][x] == rColor)
				{
					for (int i = 1; i < 8; i++)
					{
						x += dx[d];
						y += dy[d];
						if (inside(x, y))
						{
							if (table[y][x] == '-') break;
							if (table[y][x] == color)
							{
								int rx = _x;
								int ry = _y;

								count += i;

								break;
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}

		return count;
	}

	bool inside(int x, int y)
	{
		return (inside(x) && inside(y));
	}
	bool inside(int x)
	{
		return (0 <= x && x < 8);
	}
	char reverseColor(char color)
	{
		if (color == 'b') return 'w';
		if (color == 'w') return 'b';
		return 'd';
	}

};

int main() {

	cout << "ao1415" << endl;
	cout.flush();

	AI ai;

	ai.first();

	while (ai.loop())
	{
		const auto& com = ai.think();

		cout << com << endl;
		cout.flush();
	}

	return 0;
}
