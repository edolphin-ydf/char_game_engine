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

	bool containObject(T* obj);
	void addObject(T* obj);
	void addObjectIfNotExist(T* obj);
	void addObjectAtIndex(T* obj, int idx);
	void removeObject(T* ojb);
	void removeObjectAtIndex(int idx);

	void foreach(std::function<void(T*)> callback);

protected:
	/* data */
	std::vector<T*> _objects;
};

template<class T>
bool ObjectContainer<T>::containObject(T* obj) {
	for (auto o : _objects) {
		if (o == obj) {
			return true;
		}
	}
	return false;
}

template<class T>
void ObjectContainer<T>::addObject(T* obj) {
	_objects.push_back(obj);
	obj->retain();
}

template<class T>
void ObjectContainer<T>::addObjectIfNotExist(T* obj) {
	if (containObject(obj)) {
		return;
	}
	addObject(obj);
}

template<class T>
void ObjectContainer<T>::addObjectAtIndex(T* obj, int idx) {
	typename std::vector<T*>::iterator it = _objects.begin();
	it = it + idx;
	_objects.insert(it, obj);
	obj->retain();
}

template<class T>
void ObjectContainer<T>::removeObject(T *obj) {
	typename std::vector<T*>::iterator it = _objects.begin();
	for (; it != _objects.end(); ++it) {
		if (*it == obj) {
			_objects.erase(it);
			break;
		}
	}
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
