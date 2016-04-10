#ifndef OBJECTCONTAINER_H_DMJL8YDZ
#define OBJECTCONTAINER_H_DMJL8YDZ

#include "ArcObject.h"
#include <vector>
#include <functional>

namespace edolphin {

template<class T>
class ObjectContainer : public ArcObject
{
public:
	ObjectContainer () {};
	virtual ~ObjectContainer () {
		foreach([](T* obj) {obj->release();});
	};

	Getter<std::vector<T*> > getObjects = Getter<std::vector<T*> >(_objects);

	void addObject(T* obj);
	void addObjectAtIndex(T* obj, int idx);
	void removeObjectAtIndex(int idx);

	void foreach(std::function<void(T*)> callback);

protected:
	/* data */
	std::vector<T*> _objects;
};

template<class T>
void ObjectContainer<T>::addObject(T* obj) {
	_objects.push_back(obj);
	obj->retain();
}

template<class T>
void ObjectContainer<T>::addObjectAtIndex(T* obj, int idx) {
	typename std::vector<T*>::iterator it = _objects.begin();
	it = it + idx;
	_objects.insert(it, obj);
	obj->retain();
}

template<class T>
void ObjectContainer<T>::removeObjectAtIndex(int idx) {
	typename std::vector<T*>::iterator it = _objects.begin();
	it = it + idx;
	T* obj = *it;
	_objects.erase(it);
	obj->release();
}

template<class T>
void ObjectContainer<T>::foreach(std::function<void(T*)> callback) {
	typename std::vector<T*>::iterator it = _objects.begin();
	for (; it != _objects.end(); it++) {
		callback(*it);	
	}
}
}

#endif /* end of include guard: OBJECTCONTAINER_H_DMJL8YDZ */
