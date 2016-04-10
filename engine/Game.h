#ifndef _GAME_H_
#define _GAME_H_ 

#include "PainterDelegate.h"
#include "Singleton.h"
#include "GetterSetter.h"

namespace edolphin {

class Scene;
class Game : public Singleton<Game> {
public:
	bool init();
	void destory();

	void main();

	Getter<PainterDelegate*> getPainter = Getter<PainterDelegate*>(_painter);
	Getter<Scene*> getScene = Getter<Scene*>(_scene);
	
private:
	friend class Singleton;
	Game();
	~Game();
	void draw();


private:

	volatile bool finished = false;

	bool showColor = false;

	PainterDelegate *_painter;

	Scene *_scene;
};

}	// edolphin

#endif /* ifndef _GAME_H_ */

