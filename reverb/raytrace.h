#pragma once
#include "vector.h"

namespace raytrace {
	class Object {
	private:
		float Reflectance;
		float scatSpreading;
		float scatIntensity;
	public:
		virtual float getReflectance();
		virtual float getScatSpreading();
		virtual float getScatIntensity();
		virtual Reflection getReflection(Ray* ray);
	};
	class Plane: Object {
	private:
		vector3Df c;//center point
		vector3Df v;//normal vector
	public:
		

	};
	class Room {
	private:
		std::vector<Plane> planes;

	public:
		Plane* addPlane();
		Room();
		~Room();

	};
	class Reflection {

	};
	class Ray {
	private:
		float intensity;
		vector3Df origin;
		vector3Df direction;
		std::vector<Reflection> reflectionChain;
	public:

	};
	class TraceEvent {
	private:
		Tracer* parent;
		Ray* ray;
	public:
		Ray* getRay();

		void transact();
	};
	class Tracer {
	private:
		Room* room;
		std::list<Ray> rays;
	public:
		Tracer(Room* sourceRoom) :room(sourceRoom) {

		}
		TraceEvent* get();
	};
	class RayTrace {
	private:
		Room room;
	public:
		RayTrace(Room& sourceRoom):room(sourceRoom) {

		}
		Tracer* trace(Ray);
	};
}