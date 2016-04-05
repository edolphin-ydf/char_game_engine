#ifndef _GAME_H_
#define _GAME_H_ 

#include "PainterDelegate.h"

namespace edolphin {

class Game {
public:
	void init();
	void destory();

	void main();

private:
	void draw();


private:
	volatile bool finished = false;

	bool showColor = false;

	PainterDelegate *painter;
};

}	// edolphin

#endif /* ifndef _GAME_H_ */

