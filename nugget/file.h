#pragma once
#include "stdafx.h"

namespace nugget {
	class file
	{
	public:
		virtual int LoadData(const std::string& filePath, std::vector<unsigned char>& buffer) {return 0;};
		virtual void closeFile() {};
	protected:
		bool m_isInitalized = false;
	};
}