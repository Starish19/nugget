#pragma once
#include "Random.h"

namespace nugget {
	class RandomRaylib : public random
	{
	public:
		void Initalize() final;
		void Shutdown() final {};

		int getRandom(int lower, int upper) final;
	};
}