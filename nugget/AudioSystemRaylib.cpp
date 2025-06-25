#include "AudioSystemRaylib.h"

#ifdef AUDIOSYSTEM_RAYLIB
	nugget::AudioSystemRaylib nugAudioSystemRaylib;
	nugget::AudioSystem* nugget::nugAudio = &nugAudioSystemRaylib;
#endif

nugget::AudioSystemRaylib::AudioSystemRaylib() {

}

nugget::AudioSystemRaylib::~AudioSystemRaylib() {

}

void nugget::AudioSystemRaylib::Initalize() {
	InitAudioDevice();
}

void nugget::AudioSystemRaylib::Shutdown() {
	CloseAudioDevice();
}

void nugget::AudioSystemRaylib::PlayNoise(Sound* sound) {
	SetSoundVolume(*sound, 0.1);
	if (!IsSoundPlaying(*sound)) PlaySound(*sound);
}

void nugget::AudioSystemRaylib::StartMusic(Music* music, bool loop) {
	PlayMusicStream(*music);
	music->looping = loop;

	std::unique_ptr<Music> m_music(music);
}

void nugget::AudioSystemRaylib::EndMusic() {
	StopMusicStream(*m_music.get());
}

void nugget::AudioSystemRaylib::Pause() {
	PauseMusicStream(*m_music.get());
}

void nugget::AudioSystemRaylib::Resume() {
	ResumeMusicStream(*m_music.get());
}