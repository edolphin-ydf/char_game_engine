#ifndef SINGLETON_H_KIPD0ZR1
#define SINGLETON_H_KIPD0ZR1

namespace edolphin {

template<class T>
class Singleton
{
public:
	static T* getInstance() {
		if (inst == nullptr) {
			inst = new T();
		}
		return inst;
	}

	static void deleteInstance() {
		delete inst;
	}

protected:
	Singleton (){};
	virtual ~Singleton (){};

	/* data */
	static T *inst;
};

template<class T>
T* Singleton<T>::inst = nullptr;
}

#endif /* end of include guard: SINGLETON_H_KIPD0ZR1 */
