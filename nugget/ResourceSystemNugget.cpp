#include "ResourceSystemNugget.h"

#ifdef RESOURCESYSTEMNUGGET
nugget::ResourceSystemNugget nugResourceSystemNugget;
nugget::ResourceSystem* nugResource = &nugResourceSystemNugget;
#endif // RESOURCESYSTEMNUGGET

void nugget::ResourceSystemNugget::Initalize() {
	imagePool = new Image[10];
	audioPool = new Audio[3];
}

nugget::Image nugget::ResourceSystemNugget::LoadImage(file ziphandle, char* filePath) {
	int result = unzLocateFile(ziphandle, "assets/images/mudkip.png", 1);
	int totalread = 0;
	int read;
	if (result == UNZ_OK) {
		result = unzOpenCurrentFile(ziphandle);
		for (int i = 0; (read = unzReadCurrentFile(ziphandle, &(buffers[i][0]), 50000)) > 0; i++) {
			totalread += read;
		}
		unzCloseCurrentFile(ziphandle);
	}
	unzClose(ziphandle);

}