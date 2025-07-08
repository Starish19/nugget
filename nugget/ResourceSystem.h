#pragma once
#pragma once
#include "subsystem.h"
#include "file.h"
#include "stdafx.h"

//Forward Declarations
struct Image;
struct Wave;
struct Texture;
struct Sound;

namespace nugget {
    class ResourceSystem : public nugget::subsystem {
    public:
        virtual void addFile(const std::string& fileName, const std::string& filePath) = 0;

        virtual Image* LoadImage(const std::string& name, const std::string& handle, const std::string& filePath) = 0;
        virtual Wave* LoadWave(const std::string& name, const std::string& handle, const std::string& filePath) = 0;

        virtual Image* getImage(const std::string& name) = 0;
        virtual Wave* getWave(const std::string& name) = 0;

        virtual Texture getTextureFromImage(const std::string& name) = 0;
        virtual Sound getSoundFromWave(const std::string& name) = 0;
    protected:
        std::unordered_map<std::string, Image> imgs;
        std::unordered_map<std::string, Wave> wavs;

        std::unordered_map<std::string, std::unique_ptr<file>> files;
    };

    extern ResourceSystem* nugResource;
}