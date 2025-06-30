#pragma once
#pragma once
#include "subsystem.h"

//Forward Declarations
struct Image;
struct Audio;

namespace nugget {
    class ResourceSystem : public nugget::subsystem {
    public:
        virtual Image* LoadImage(char* filePath) = 0;
        virtual Audio* LoadAudio(char* filePath) = 0;

        virtual Image* getImage(char* name) = 0;
        virtual Audio* getAudio(char* name) = 0;
    protected:
    };

    extern ResourceSystem* nugResource;
}