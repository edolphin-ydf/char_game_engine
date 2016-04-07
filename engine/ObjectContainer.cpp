#include "ObjectContainer.h"

namespace edolphin {

template<class T>
void ObjectContainer<T>::addObject(T* obj) {
	_objects.push_back(obj);
}

template<class T>
void ObjectContainer<T>::addObjectAtIndex(T* obj, int idx) {
	typename std::vector<T*>::iterator it = _objects.begin();
	it = it + idx;
	_objects.insert(it, obj);
}

template<class T>
void ObjectContainer<T>::removeObjectAtIndex(int idx) {
	typename std::vector<T*>::iterator it = _objects.begin();
	it = it + idx;
	_objects.erase(it);
}

template<class T>
void ObjectContainer<T>::foreach(std::function<void(T*)> callback) {
	typename std::vector<T*>::iterator it = _objects.begin();
	for (; it != _objects.end(); it++) {
		callback(*it);	
	}
}


}
