#include "stdafx.h"
#include "RandomRaylib.h"
#include "raylib.h"
#include "time.h"

#ifdef RANDOMRAYLIB
nugget::RandomRaylib nuggetRandomRaylib;
nugget::random* nugget::nugRand = &nuggetRandomRaylib;
#endif // RANDOMRAYLIB

void nugget::RandomRaylib::Initalize() {
	SetRandomSeed(time(0));
}

int nugget::RandomRaylib::getRandom(int lower, int upper) {
	return GetRandomValue(lower, upper);
}