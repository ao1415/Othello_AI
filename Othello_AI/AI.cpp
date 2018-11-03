#include "AI.hpp"

const string AI::think() {

	/*
	�Ƃ肠���������̂悤�ɕ��D��T���ɂ���
	��Ԃ����݂ɉ���Ă���̂ł��܂�K���ĂȂ��H
	�@�؍\���ɂ����ق����ǂ��H
	�@�@�p�X�̕\�����@�́H
	�@�@�@�؍\���̏ꍇ�A�[�x�̃^�[��������Ɉ��
	����Ԃ̏ꍇ�A�������Œ�l�ɂȂ�ӏ��ɒu��������
	�@�e��ԏ��5�ۑ����Ă����H
	�@�@�؂��Ƃɏ�Ԃ̊Ǘ����K�v
	�K���ɂ���Ɠǂݐ؂�Ȃ�
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
