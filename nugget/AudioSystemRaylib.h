#pragma once
#include "AudioSystem.h"
#include "raylib.h"

namespace nugget {

	class AudioSystemRaylib : public AudioSystem
	{
	public:
		AudioSystemRaylib();
		~AudioSystemRaylib();

		void Initalize() final;
		void Shutdown() final;

		void PlayNoise(Sound* sound) final;

		void StartMusic(Music* music, bool loop) final;
		void EndMusic() final;

		void Pause() final;
		void Resume() final;
	};
}

