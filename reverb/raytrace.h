#pragma once
#include <vector>
#include <list>
#include <functional>
#include <stack>

#include "vector.h"

using namespace mymath;

namespace raytrace {
	struct Ray;
	struct Reflectance {
		float val;
		operator float() {
			return val;
		}
	};
	struct Reflection {
		bool isValid;
		vector3Df intersection;
		vector3Df reflection;
		Reflectance* reflectance;
		Reflection():isValid(true) {}
	};
	class Object {
	private:
		Reflectance reflectance;
		float scatSpreading;
		float scatIntensity;
	public:
		virtual Reflectance* getReflectance() { return &reflectance;  };
		virtual float getScatSpreading() { return scatSpreading; };
		virtual float getScatIntensity() { return scatIntensity;  };
		//virtual Reflection getReflection(Ray* ray) = 0;
		Object() {};
		~Object() {};
	};
	class Plane: public Object {
	private:
		
	public:
		vector3Df c;//center point
		vector3Df v;//normal vector
		Plane();
		~Plane();

	};

	
	class Room {
	private:
		std::vector<Plane> planes;
		Reflection InvalidReflection;
	public:
		Plane* addPlane();
		Reflection getReflection(Ray* ray);
		Room();
		~Room();

	};

	struct Ray {
	public:
		float intensity;
		vector3Df origin;
		vector3Df direction;
		std::vector<Reflection> reflectionChain;

	};
	class TraceEvent {
	private:
		Ray* ray;
		bool doReflect;
		bool doScatter;
	public:

		TraceEvent() :doReflect(true),doScatter(true) {}
		Ray* getRay() { return ray; }
		void setRay(Ray* _ray) { ray = _ray; }

		bool getDoReflect() { return doReflect; }
		void setDoReflect(bool _doReflect) { doReflect = true; }

		bool getDoScatter() { return doScatter; }
		void setDoScattert(bool _doScatter) { doScatter = true; }

		
	};

	typedef std::function<bool(TraceEvent* e)> TraceCallback;
	class RayTracer {
	private:
		Room room;
	public:
		RayTracer(Room& sourceRoom);
		void trace(Ray ray,TraceCallback func);
	};
}