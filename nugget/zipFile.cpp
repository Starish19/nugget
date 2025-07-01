#include "stdafx.h"
#include "zipFile.h"

nugget::zipFile::zipFile(const std::string& handle) {
	zipHandle = unzOpen64(handle.c_str());
	int result = unzOpenCurrentFile(zipHandle);
	if (result == UNZ_OK) m_isInitalized = true;
}

nugget::zipFile::~zipFile() {

}

int nugget::zipFile::LoadData(const std::string& filePath, std::vector<unsigned char> &buffer) {

	if (!m_isInitalized) {return 0;}

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