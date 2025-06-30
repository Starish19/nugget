#pragma once
#include "file.h"
#include "unzip.h"

namespace nugget {
		class zipFile : public file
		{
		public:
			zipFile(const std::string& handle);
			~zipFile();

			int LoadData(const std::string& filePath, std::vector<unsigned char> &buffer) final;

		protected:
			unzFile zipHandle;
		};
}
