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
		Wave* LoadAudio(const std::string& name, const std::string& handle, const std::string& filePath) final;

		Image* getImage(const std::string& name) final;
		Wave* getAudio(const std::string& name) final;
	private:
		std::unordered_map<std::string, zipFile> files;
	};
}