#include "AI.hpp"

int main() {

	cout << "ao1415AI" << endl;
	cout.flush();

	AI ai;

	ai.first();

	Stopwatch sw;

	while (ai.loop())
	{
		sw.start();
		const auto& com = ai.think();
		sw.stop();

		cerr << sw.toString_ms() << endl;
		cerr.flush();

		cout << com << endl;
		cout.flush();
	}

	return 0;
}
