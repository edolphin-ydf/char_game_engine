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
	ObjectContainer ();
	virtual ~ObjectContainer ();

	Getter<std::vector<T*> > getObjects = Getter<std::vector<T*> >(_objects);

	void addObject(T* obj);
	void addObjectAtIndex(T* obj, int idx);
	void removeObjectAtIndex(int idx);

	void foreach(std::function<void(T*)> callback);

protected:
	/* data */
	std::vector<T*> _objects;
};

}

#endif /* end of include guard: OBJECTCONTAINER_H_DMJL8YDZ */
