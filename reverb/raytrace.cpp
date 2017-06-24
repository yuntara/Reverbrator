#include "raytrace.h"

namespace raytrace {

	using namespace mymath;

	Plane* raytrace::Room::addPlane()
	{
		Plane _plane;

		planes.push_back(_plane);

		return &*(planes.end());
	}

	Reflection Room::getReflection(Ray * ray)
	{
		vector3Df intersection;
		float min_dist = -1;
		//get intersection distanse
		Plane* intersect_plane{nullptr};
		for(auto& plane : planes){
			float dist = Dot(plane.v , (plane.c - ray->origin));
			if (dist > 0 && (dist < min_dist || min_dist < 0)) {
				min_dist = dist;
				intersect_plane = &plane;
			}
			else {
				break;
			}
		}
		if (min_dist <= 0) {
			return InvalidReflection;
		}
		Reflection ref;
		ref.intersection = ray->origin + min_dist * ray->direction;
		//ref.reflection = ray->direction - 2 * (ray->direction | intersect_plane->v)*intersect_plane->v;
		ref.reflectance = intersect_plane->getReflectance();
		return ref;
	}

	Room::Room()
	{
		InvalidReflection.isValid = false;
	}

	Room::~Room()
	{
	}
	
	Plane::Plane(){
	}

	Plane::~Plane(){
	}


	RayTracer::RayTracer(Room & sourceRoom) : room(sourceRoom) {

	}

	void RayTracer::trace(Ray sourceRay, TraceCallback func)
	{
		TraceEvent e;
		Ray _ray,newRay;
		
		std::stack<Ray> rays;
		rays.push(sourceRay);

		while (1) {
			if (rays.size() == 0) {
				break;
			}
			_ray = rays.top();
			rays.pop();
			e.setRay(&_ray);
			
			if (func(&e)) {
				Reflection r = room.getReflection(&_ray);
				if (r.isValid) {
					if (e.getDoReflect()) {
						newRay = Ray();

						newRay.reflectionChain = _ray.reflectionChain;
						newRay.reflectionChain.push_back(r);
						//newRay.intensity *= r.reflectance;
						rays.push(std::move(newRay));
					}
					if (e.getDoScatter()) {

					}
				}
				
			}
			
		}
	}

}