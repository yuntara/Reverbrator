#include "raytrace.h"

namespace raytrace {




	Object::Object(){
	}

	Object::~Object(){
	}

	Plane* raytrace::Room::addPlane()
	{
		Plane _plane;

		planes.push_back(_plane);

		return &*(planes.end());
	}

	Reflection* Room::getReflection(Ray * ray)
	{
		return nullptr;
	}

	Room::Room()
	{
	}

	Room::~Room()
	{
	}
	
	Plane::Plane(){
	}

	Plane::~Plane(){
	}


	RayTrace::RayTrace(Room & sourceRoom) : room(sourceRoom) {

	}

	void RayTrace::trace(Ray ray, TraceCallback func)
	{
		TraceEvent e;
		Ray _ray;
		std::list<Ray> rays;
		rays.push_back(ray);
		auto it = rays.begin();
		while (1) {
			
			e.setRay(&*it);

			if (func(&e)) {
				Reflection *r = room.getReflection(&*it);
				if (r != nullptr) {
					if (e.getDoReflect) {

						
					}
					if (e.getDoScatter) {

					}
				}
				
			}
			it = rays.erase(it);
			if (it == rays.end()) {
				break;
			}
		}
	}

}