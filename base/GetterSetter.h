#ifndef GETTERSETTER_H_LNGZ0CR3
#define GETTERSETTER_H_LNGZ0CR3

namespace edolphin {


template<class T>
class Getter {
public:
	Getter(T& _val):val(_val)
	{}

	T& operator()() {
		return val;	
	}
private:
	T& val;
};

template<class T>
class Setter {
public:
	Setter(T& _val):val(_val)	
	{}

	void operator() (T _val) {
		val = _val;	
	}

private:
	T& val;
};

template<class T>
class SetterGetter {
public:
	SetterGetter(T& _val)
		:getter(_val), setter(_val){}

	void operator() (T& _val) {
		setter(_val);
	}

	T operator() () {
		return getter();
	}

private:
	Getter<T> getter;
	Setter<T> setter;
};

}	// namespace edolphin

#endif /* end of include guard: GETTERSETTER_H_LNGZ0CR3 */

