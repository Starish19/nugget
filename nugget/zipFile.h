#pragma once
#include "file.h"
#include "unzip.h"

namespace nugget {
		class zipFile : public file
		{
		public:
			zipFile() {};
			zipFile(const std::string& handle);
			~zipFile();

			int LoadData(const std::string& filePath, std::vector<unsigned char> &buffer) final;

			void closeFile() final { unzClose(zipHandle);};
		protected:
			unzFile zipHandle;
		};
}
