#ifndef _GAME_H_
#define _GAME_H_ 

#include "PainterDelegate.h"
#include "Singleton.h"

namespace edolphin {

class Game : public Singleton<Game> {
public:
	bool init();
	void destory();

	void main();

private:
	void draw();


private:
	Game();
	~Game();

	volatile bool finished = false;

	bool showColor = false;

	PainterDelegate *painter;
};

}	// edolphin

#endif /* ifndef _GAME_H_ */

