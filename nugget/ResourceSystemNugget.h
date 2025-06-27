#pragma once
#include "ResourceSystem.h"
#include "unzip.h"

typedef unzFile file;

namespace nugget {
    class ResourceSystemNugget : public ResourceSystem {
    public:
        void Initalize() final;
        void Shutdown() final;

        Image LoadImage(file ziphandle, char* path) final;
        Audio LoadAudio() final;

        Image getImage() final;
        Audio getAudio() final;
    };
}