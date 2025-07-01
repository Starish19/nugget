#include "stdafx.h"
#include "ResourceSystemRaylib.h"

#ifdef RESOURCESYSTEMRAYLIB
nugget::ResourceSystemRaylib nugResourceSystemRaylib;
nugget::ResourceSystem* nugget::nugResource = &nugResourceSystemRaylib;
#endif // RESOURCESYSTEMRAYLIB

void nugget::ResourceSystemRaylib::Initalize() {

}

void nugget::ResourceSystemRaylib::Shutdown() {
	for (auto& file : files) {
		file.second.closeFile();
	}
}

void nugget::ResourceSystemRaylib::addFile(const std::string& fileName, const std::string& filePath) {
	zipFile newFile(filePath);
	files[fileName] = std::move(newFile);
}

Image* nugget::ResourceSystemRaylib::LoadImage(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::vector<unsigned char> buffer(80000);

	file* file = &files.at(handle);

	int totalread = file->LoadData(filePath.c_str(), buffer);
	Image img = LoadImageFromMemory(".png", &buffer[0], totalread);
	imgs[name] = img;

	return &img;
}

Wave* nugget::ResourceSystemRaylib::LoadAudio(const std::string& name, const std::string& handle, const std::string& filePath) {
	std::vector<unsigned char> buffer(6000);

	file* file = &files[handle];

	int totalread = file->LoadData(filePath.c_str(), buffer);
	Wave wav = LoadWaveFromMemory(".mp3", &buffer[0], totalread);
	wavs[name] = std::move(wav);

	return &wav;
}

Image* nugget::ResourceSystemRaylib::getImage(const std::string& name) {
	return &imgs.at(name);
}

Wave* nugget::ResourceSystemRaylib::getAudio(const std::string& name) {
	return &wavs.at(name);
}