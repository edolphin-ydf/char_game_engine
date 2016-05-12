#ifndef LOCK_H_16ZJJGIH
#define LOCK_H_16ZJJGIH

namespace edolphin
{
	
class Lock
{
public:
	Lock ();
	virtual ~Lock ();

	virtual void lock() = 0;
	virtual void unlock() = 0;
};


class ScopeLock {
public:
	ScopeLock(Lock& _lock) : lock(_lock){
		lock.lock();
	}

	virtual ~ScopeLock() {
		lock.unlock();
	}

private:
	Lock& lock;
};

} /* edolphin */ 

#endif /* end of include guard: LOCK_H_16ZJJGIH */
