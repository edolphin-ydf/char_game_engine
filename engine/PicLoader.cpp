#include "PicLoader.h"
#include "Picture.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

namespace edolphin
{
	
Picture* PicLoader::load(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		return nullptr;
	}
	std::vector<std::string> picDatas;
	char buf[1024]  = {0};
	DWORD width = 0;
	DWORD height = 0;
	while(fgets(buf, sizeof(buf) -1, file) != NULL) {
		std::string bufstr = buf;
		picDatas.push_back(bufstr);
		DWORD len = strnlen(buf, 1024) + 1;
		if (len > width) {
			width = len;
		}
		height++;
	}

	char* data = new char[width * height];
	for (int i = 0; i < picDatas.size(); ++i) {
		strncpy(data + width * i, picDatas[i].c_str(), width);
		*(data + width * (i + 1) -1) = 0;
	}

	return new Picture((BYTE*)data, width, height);
}

} /* edolphin */ 
