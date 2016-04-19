#ifndef PICLOADER_H_2ZGXIZEQ
#define PICLOADER_H_2ZGXIZEQ

namespace edolphin {

class Picture;
class PicLoader {
public:
	PicLoader(){}
	~PicLoader() {}
	static Picture* load(const char* filename);
};

}	// edolphin

#endif /* end of include guard: PICLOADER_H_2ZGXIZEQ */
