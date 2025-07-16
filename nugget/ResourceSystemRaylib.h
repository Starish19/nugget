#pragma once
#include "ResourceSystem.h"
#include "zipFile.h"
#include "raylib.h"

namespace nugget {
	class ResourceSystemRaylib : public ResourceSystem
	{
	public:
		void Initalize() final;
		void Shutdown() final;

		void addFile(const std::string& fileName, const std::string& filePath) final;

		Image* LoadImage(const std::string& name, const std::string& handle, const std::string& filePath) final;
		Wave* LoadWave(const std::string& name, const std::string& handle, const std::string& filePath) final;
		Music* LoadMusic(const std::string& name, const std::string& handle, const std::string& filePath) final;

		Image* getImage(const std::string& name) final;
		Wave* getWave(const std::string& name) final;
		Music* getMusic(const std::string& name) final;

		Texture* getTextureFromImage(const std::string& name) final;
		Sound* getSoundFromWave(const std::string& name) final;
	};
}