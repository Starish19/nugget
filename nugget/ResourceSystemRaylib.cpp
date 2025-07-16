#include "stdafx.h"
#include "ResourceSystemRaylib.h"
#include "raylib.h"

#ifdef RESOURCESYSTEMRAYLIB
nugget::ResourceSystemRaylib nugResourceSystemRaylib;
nugget::ResourceSystem* nugget::nugResource = &nugResourceSystemRaylib;
#endif // RESOURCESYSTEMRAYLIB

void nugget::ResourceSystemRaylib::Initalize() {

}

void nugget::ResourceSystemRaylib::Shutdown() {
	for (auto& file : files) {
		file.second->closeFile();
	}
}

void nugget::ResourceSystemRaylib::addFile(const std::string& fileName, const std::string& filePath) {
	std::unique_ptr<zipFile> newFile = std::make_unique<zipFile>(filePath);
	files[fileName] = std::move(newFile);
}

Image* nugget::ResourceSystemRaylib::LoadImage(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::vector<unsigned char> buffer(80000);

	file* file = files[handle].get();

	int totalread = file->LoadData(filePath.c_str(), buffer);
	Image img = LoadImageFromMemory(".png", &buffer[0], totalread);
	imgs[name] = img;

	return &imgs[name];
}

Wave* nugget::ResourceSystemRaylib::LoadWave(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::vector<unsigned char> buffer(6000);

	file* file = files[handle].get();

	int totalread = file->LoadData(filePath.c_str(), buffer);
	Wave wav = LoadWaveFromMemory(".mp3", &buffer[0], totalread);
	wavs[name] = wav;

	return &wavs[name];
}

Music* nugget::ResourceSystemRaylib::LoadMusic(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::vector<unsigned char> buffer(200000);

	file* file = files[handle].get();
	int totalread = file->LoadData(filePath.c_str(), buffer);

	streams[name] = std::move(buffer);

	Music mus = LoadMusicStreamFromMemory(".mp3", &streams[name][0], totalread);

	musics[name] = mus;
	return &musics[name];
}

std::unique_ptr<std::vector<unsigned char>> nugget::ResourceSystemRaylib::LoadFile(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::unique_ptr<std::vector<unsigned char>> buffer = std::make_unique<std::vector<unsigned char>>(6000);

	file* file = files[handle].get();

	int totalread = file->LoadData(filePath.c_str(), *buffer);

	return std::move(buffer);
}

Image* nugget::ResourceSystemRaylib::getImage(const std::string& name) {
	return &imgs[name];
}

Wave* nugget::ResourceSystemRaylib::getWave(const std::string& name) {
	return &wavs[name];
}

Music* nugget::ResourceSystemRaylib::getMusic(const std::string& name) {
	return &musics[name];
}

Texture* nugget::ResourceSystemRaylib::getTextureFromImage(const std::string& name) {
	if (texs.find(name) == texs.end())
		texs[name] = LoadTextureFromImage(imgs[name]);
	return &texs[name];
}

Sound* nugget::ResourceSystemRaylib::getSoundFromWave(const std::string& name) {
	if (snds.find(name) == snds.end())
		snds[name] = LoadSoundFromWave(wavs[name]);
	return &snds[name];
}

void nugget::ResourceSystemRaylib::unload(const std::string& name) {
	if (imgs.find(name) != imgs.end()) {
		UnloadImage(imgs[name]);
		imgs.erase(name);
	}
	if (texs.find(name) != texs.end()) {
		UnloadTexture(texs[name]);
		texs.erase(name);
	}
	if (snds.find(name) != snds.end()) {
		UnloadSound(snds[name]);
		snds.erase(name);
	}
	if (wavs.find(name) != wavs.end()) {
		UnloadWave(wavs[name]);
		wavs.erase(name);
	}
	if (musics.find(name) != musics.end()) {
		UnloadMusicStream(musics[name]);
		musics.erase(name);
	}
	if (streams.find(name) != streams.end()) {
		streams[name].clear();
		streams.erase(name);
	}
}