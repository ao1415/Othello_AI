#include "AI.hpp"

const string AI::think() {

	int maxScore = 0;
	string com = "0 0";

	auto next = table;

	Engine engine(move(next), color);
	
	const auto& poition = engine.getPut();

	com = poition.begin()->toString();

	return com;
}
