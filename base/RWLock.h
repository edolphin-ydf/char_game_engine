#ifndef RWLOCK_H_5RIVAXOV
#define RWLOCK_H_5RIVAXOV

#include "Lock.h"
#include <mutex>

namespace edolphin
{
	

class RWLock
{
public:
	RWLock ();
	virtual ~RWLock ();

	virtual void rlock();
	virtual void runlock();
	
	virtual void wlock();
	virtual void wunlock();

private:
	/* data */
	std::mutex lock;

	std::mutex internalLock;
	int rcnt = 0;
};


class RScopeLock
{
public:
	RScopeLock(RWLock& _lock): lock(_lock) {
		lock.rlock();
	}

	virtual ~RScopeLock() {
		lock.runlock();
	}
private:
	RWLock& lock;
};

class WScopeLock
{
public:
	WScopeLock(RWLock& _lock): lock(_lock) {
		lock.wlock();
	}

	virtual ~WScopeLock() {
		lock.wunlock();
	}
private:
	RWLock& lock;
};


} /* edolphin */ 
#endif /* end of include guard: RWLOCK_H_5RIVAXOV */


