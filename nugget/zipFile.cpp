#include "stdafx.h"
#include "zipFile.h"

nugget::zipFile::zipFile(const std::string& handle) {
	zipHandle = unzOpen64(handle.c_str());
}

nugget::zipFile::~zipFile() {
	unzClose(zipHandle);
}

int nugget::zipFile::LoadData(const std::string& filePath, std::vector<unsigned char> &buffer) {
	int result = unzLocateFile(zipHandle, filePath.c_str(), 1);
	int read, totalread = 0;

	int size = buffer.size();

	if (result == UNZ_OK) {
		unzOpenCurrentFile(zipHandle);
		for (int i = 0; (read = unzReadCurrentFile(zipHandle, &buffer[i * size], size)) > 0; i++) {
			totalread += read;

			if (totalread == size * (i + 1)) {
				buffer.resize((size * (i + 2)));
			}
			else break;
		}
		unzCloseCurrentFile(zipHandle);
	}

	return totalread;
}