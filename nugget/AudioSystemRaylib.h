#pragma once
#include "AudioSystem.h"

namespace nugget {

	class AudioSystemRaylib : public AudioSystem
	{
	public:
		AudioSystemRaylib();
		~AudioSystemRaylib();

		void Initalize() final;
		void Shutdown() final;

		void setMasterVolume(float volume) final;

		void PlayNoise(Sound* sound, float volume) final;

		void StartMusic(Music* music, bool loop) final;
		void UpdateMusic() final;
		void EndMusic() final;

		void Pause() final;
		void Resume() final;
	};
}

