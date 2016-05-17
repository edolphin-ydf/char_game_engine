#include "Scene.h"
#include "CollisionDetection.h"

namespace edolphin {

void Scene::draw() {
	foreach([](Drawable* obj) {obj->draw();});
}

void Scene::collisionDection() {
	for ( auto i = _objects.begin(); i != _objects.end(); ++i) {
		if (!(*i)->isCollisionable()) {
			continue;
		}
		for (auto j=i +1; j!=_objects.end(); ++j) {
			if (!(*j)->isCollisionable()) {
				continue;	
			}	

			if ((*i)->getGeometryType() == DrawableGeometryTypePoint) {
				if ((*j)->getGeometryType() == DrawableGeometryTypeRect) {
					if(CollisionDetection::CollisionDectectionRectPoint((*j)->getRect(), (*i)->position())						) {
						(*i)->onCollision(*j);
						(*j)->onCollision(*i);
					}
				}	
			}
		

			if ((*i)->getGeometryType() == DrawableGeometryTypeRect) {
				if ((*j)->getGeometryType() == DrawableGeometryTypeRect) {
					if(CollisionDetection::CollisionDectectionRectRect((*j)->getRect(), (*i)->getRect())						) {
						(*i)->onCollision(*j);
						(*j)->onCollision(*i);
					}
				}	
				if ((*j)->getGeometryType() == DrawableGeometryTypePoint) {
					if(CollisionDetection::CollisionDectectionRectPoint((*i)->getRect(), (*j)->position())						) {
						(*i)->onCollision(*j);
						(*j)->onCollision(*i);
					}
				}	
			}

		}
	}
}

}
