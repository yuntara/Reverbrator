#pragma once
#include <vector>
#include <list>
#include <functional>

#include "vector.h"

using namespace mymath;

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
		Object();
		~Object();
	};
	class Plane: public Object {
	private:
		vector3Df c;//center point
		vector3Df v;//normal vector
	public:
		Plane();
		~Plane();

	};
	class Reflection {

	};

	class Room {
	private:
		std::vector<Plane> planes;

	public:
		Plane* addPlane();
		Reflection* getReflection(Ray* ray);
		Room();
		~Room();

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
		Ray* ray;
		bool doReflect;
		bool doScatter;
	public:
		Ray* getRay() { return ray; }
		void setRay(Ray* _ray) { ray = _ray; }

		bool getDoReflect() { return doReflect; }
		void setDoReflect(bool _doReflect) { doReflect = true; }

		bool getDoScatter() { return doScatter; }
		void setDoScattert(bool _doScatter) { doScatter = true; }

		
	};

	typedef std::function<bool(TraceEvent* e)> TraceCallback;
	class RayTrace {
	private:
		Room room;
	public:
		RayTrace(Room& sourceRoom);
		void trace(Ray ray,TraceCallback func);
	};
}