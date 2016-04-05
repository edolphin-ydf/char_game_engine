#ifndef EDLOBJECT_H_5TEISVUF
#define EDLOBJECT_H_5TEISVUF

#include <stdio.h>
#include <string>

#include "GetterSetter.h"

//************************************************************************
//***********important: all object must be created in the heep************
//************************************************************************

namespace edolphin {

#define SafeRelease(_var) \
    do{ \
        if(_var){   \
            _var->release();\
            _var = NULL;    \
        }       \
    }while(0)

#define SafeDelete(_var) \
do{ \
    if(_var){   \
        delete _var;\
        _var = NULL;    \
    }       \
}while(0)

#define SafeDeleteS(_var) \
do{ \
    if(_var){   \
        delete [] _var;\
        _var = NULL;    \
    }       \
}while(0)

#define SafeDeleteA(_var) SafeDeleteS(_var)

#define GeterAssign(_type, _var, _funcName)   \
public: \
    _type get##_funcName(){    \
        return _var;      \
    }

#define SeterAssign(_type, _var, _funcName)    \
public: \
    void set##_funcName(_type _##_var){    \
        this->_var = _##_var;   \
    }

#define GeterRetain(_type, _var, _funcName)    \
public: \
    _type *get##_funcName(){     \
        return this->_var;  \
    }

#define SeterRetain(_type, _var, _funcName)    \
public: \
    void set##_funcName(_type *_##_var){      \
        if(this->_var != _##_var){      \
            SafeRelease(this->_var);       \
            this->_var = _##_var;        \
            this->_var->retain();        \
        }    \
    }

#define SeterGeterAssign(_type, _var, _funcName)    \
GeterAssign(_type, _var, _funcName) \
SeterAssign(_type, _var, _funcName) 

#define SeterGeterRetain(_type, _var, _funcName)    \
GeterRetain(_type, _var, _funcName) \
SeterRetain(_type, _var, _funcName) 


class ArcObject
{
private:
	int retainCount;

public:
	ArcObject(void);
	virtual ~ArcObject(void);
	
public:
	void retain();
	void release();
	void autoRelease();

    //GeterAssign(int, retainCount, RetainCount);
//	int getRetainCount(){return retainCount;}

	virtual bool isEqualTo(ArcObject *obj);

	virtual std::string toString();

	Getter<int> getRetainCount = Getter<int>(retainCount);
	Setter<int> setRetainCount = Setter<int>(retainCount);
};

}	// end of namespace edolphin

#endif /* end of include guard: EDLOBJECT_H_5TEISVUF */


