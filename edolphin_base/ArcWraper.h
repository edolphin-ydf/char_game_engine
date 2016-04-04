#ifndef AUTOREFERENCECOUNTER_H_2WDN0DYA
#define AUTOREFERENCECOUNTER_H_2WDN0DYA

template<class T>
class ArcWraper
{
public:
	ArcWraper (T* pointer)
   		:p(pointer)	{
	}
	virtual ~ArcWraper ();

	T* operator -> () {
		return p;
	}

	T operator * () {
		return *p;
	}

	void retain() {
		refCount++;
	}

	void release() {
		refCount--;
		if (refCount <= 0) {
			delete this;
		}
	}

private:
	T* p;

	int refCount = 1;
};	
#endif /* end of include guard: AUTOREFERENCECOUNTER_H_2WDN0DYA */
