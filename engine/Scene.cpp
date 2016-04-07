#include "Scene.h"

namespace edolphin {

	void Scene::draw() {
		foreach([](Drawable* obj) {obj->draw();});
	}

}
