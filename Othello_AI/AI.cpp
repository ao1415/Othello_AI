#include "AI.hpp"

const string AI::think() {

	/*
	とりあえずいつものように幅優先探査にした
	手番が交互に回ってくるのであまり適してない？
	　木構造にしたほうが良い？
	　　パスの表現方法は？
	　　　木構造の場合、深度のターン数が常に一定
	相手番の場合、自分が最低値になる箇所に置かせたい
	　各手番上位5個保存していく？
	　　木ごとに状態の管理が必要
	適当にすると読み切れない
	*/

	auto initTable = table;
	Engine engine(move(initTable), color);

	const int Turn = min(6, 64 - turn);

	const auto& best = minmax(engine, 0, Turn);

	return best.second.toString();
}

const pair<double, Point> AI::minmax(const Engine& engine, const int turn, const int depth) {

	if (turn >= depth)
		return { evaluation(engine),Point(0,0) };

	const auto& position = engine.getPut();

	pair<double, Point> best;
	best.first = -99999999;
	best.second = Point(0, 0);

	if (position.empty())
	{
		return { evaluation(engine),Point(0,0) };
	}
	else
	{
		for (const auto& pos : position)
		{
			auto nextEngine = engine.getNext(pos);

			auto score = minmax(nextEngine, turn + 1, depth);
			score.second = pos;

			if (engine.getColor() == color)
			{
				if (best.first < score.first)
				{
					best = score;
				}
			}
			else
			{
				if (best.first < -score.first)
				{
					best = score;
				}
			}

		}
	}

	return best;
}

const double AI::evaluation(const Engine& engine) {

	double score = 0;

	if (turn < 64 - 12)
	{
		const auto& position = engine.getPut();

		score = (double)position.size();
	}
	else
	{
		const auto& table = engine.getTable();

		int count = 0;
		for (int y = 0; y < Size; y++)
		{
			for (int x = 0; x < Size; x++)
			{
				if (table[y][x] == color)
				{
					count++;
				}
			}
		}
		score += count;
	}

	score += random.rand();

	return score;
}
