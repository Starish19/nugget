#pragma once
#include "subsystem.h"

namespace nugget {
	class random : public subsystem {
	public:
		virtual int getRandom(int lower, int upper) = 0;
	};

	extern random* nugRand;
}