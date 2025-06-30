#pragma once
#include "stdafx.h"

class file
{
	virtual int LoadData(const std::string& filePath, std::vector<unsigned char>& buffer) = 0;
};

