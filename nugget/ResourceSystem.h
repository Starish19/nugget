#pragma once
#include "subsystem.h"

//Forward Declarations
struct file;

namespace nugget {
    struct Image {
        char data[100000];
        int location;
        int length;
    };

    struct Audio {
        char data[12000];
        int location;
        int length;
    };

    class ResourceSystem : public nugget::subsystem {
    public:
        void Shutdown() { delete imagePool; delete audioPool; }

        virtual Image LoadImage(file handle, char* path);
        virtual Audio LoadAudio();

        virtual Image getImage();
        virtual Audio getAudio();

        virtual void setImagePool(Image* pool) {imagePool = pool;}
        virtual void setAudioPool(Audio* pool) {audioPool = pool;}

    protected:
        Image* imagePool;
        Audio* audioPool;
    };

    extern ResourceSystem* nugResource;
}