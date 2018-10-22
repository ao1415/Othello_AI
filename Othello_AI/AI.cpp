#include "AI.hpp"

const string AI::think() {

	const int Turn = 10;
	const int ChokudaiWidth = 3;

	array<priority_queue<Data>, Turn + 1> qData;

	{
		Data init;

		auto initTable = table;
		init.engine = Engine(move(initTable), color);

		qData[0].emplace(init);
	}

	Timer timer(chrono::milliseconds(50));

	timer.start();

	const int LastTurn = min(Turn, (Size * Size) - turn);

	while (!timer)
	{
		for (int turn = 0; turn < LastTurn; turn++)
		{
			for (int w = 0; w < ChokudaiWidth; w++)
			{
				if (qData[turn].empty()) break;

				const auto& top = qData[turn].top();

				const auto& poition = top.engine.getPut();

				for (const auto& pos : poition)
				{
					Data next;

					next.engine = top.engine.getNext(pos);

					next.score = evaluation(next.engine);

					if (turn == 0) next.pos = pos;
					else next.pos = top.pos;

					qData[turn + 1].push(next);
				}

				qData[turn].pop();
			}
		}
	}

	if (!qData[LastTurn].empty())
	{
		const auto& top = qData[LastTurn].top();
		cerr << "Score:" << top.score << endl;

		return top.pos.toString();
	}

	return "0 0";
}

const double AI::evaluation(const Engine& engine) {

	double score = 0;

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

	score += random.rand();

	if (engine.getColor() != color)
		score *= -1;

	return score;
}
