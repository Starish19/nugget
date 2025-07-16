#include "stdafx.h"
#include "AudioSystemRaylib.h"
#include "raylib.h"

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

void nugget::AudioSystemRaylib::PlayNoise(Sound* sound, float volume) {
	SetSoundVolume(*sound, volume);
	if (!IsSoundPlaying(*sound)) PlaySound(*sound);
}

void nugget::AudioSystemRaylib::StartMusic(Music* music, bool loop) {
	if (!IsMusicValid) return;

	PlayMusicStream(*music);
	SetMusicVolume(*music, 1);
	music->looping = loop;

	m_music = music;
}

void nugget::AudioSystemRaylib::EndMusic() {
	StopMusicStream(*m_music);
}

void nugget::AudioSystemRaylib::Pause() {
	PauseMusicStream(*m_music);
}

void nugget::AudioSystemRaylib::Resume() {
	ResumeMusicStream(*m_music);
}