#pragma once
#include "subsystem.h"
#include "memory"

//Forward Declarations
struct Sound;
struct Music;

namespace nugget {
	//Abstract Audio System
	class AudioSystem : public subsystem
	{
	public:
		virtual void PlayNoise(Sound* sound) = 0; // Play sound once

		virtual void StartMusic(Music* music, bool loop) = 0; // Play longer music with option for automatic looping
		virtual void EndMusic() = 0; // Permanently stop music

		virtual void Pause() = 0; // Temporary stop music
		virtual void Resume() = 0; // Contiinue music

	protected:
		// music stream stored in smart pointer
		std::unique_ptr<Music> m_music;
	};

	//Global instance of Audio System
	extern AudioSystem* nugAudio;
}

