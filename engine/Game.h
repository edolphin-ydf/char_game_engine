#ifndef _GAME_H_
#define _GAME_H_ 

#include "PainterDelegate.h"
#include "Singleton.h"
#include "GetterSetter.h"
#include "ArcObject.h"
#include "Scene.h"

namespace edolphin {

class Scene;
class Logger;
class KeyboardInputCollector;
class KeyboardBuffer;
class Game : public Singleton<Game> {
public:
	bool init();
	void destory();

	void main();

	Getter<PainterDelegate*> getPainter = Getter<PainterDelegate*>(_painter);

	SeterGeterRetain(Scene, _scene, Scene);

	static Logger* getLogger();

	GeterRetain(KeyboardBuffer, keyboardBuffer, KeyboardBuffer);

private:
	friend class Singleton;
	Game();
	~Game();
	void draw();


private:

	volatile bool finished = false;

	bool showColor = false;

	PainterDelegate *_painter;

	Scene *_scene = nullptr;

	KeyboardBuffer *keyboardBuffer;

	KeyboardInputCollector* keyboardInputCollector;

	static Logger* logger;
};

}	// edolphin

#endif /* ifndef _GAME_H_ */

