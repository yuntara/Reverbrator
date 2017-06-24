#pragma once

namespace mymath {
	
	template<typename T> class Vector3D {
	private:
		T fx, fy, fz;
	public:
		Vector3D() {}
		Vector3D(T ax, T ay, T az) :fx(ax), fy(ay), fz(az) {}
		virtual ~Vector3D() {}
		Vector3D<T> operator +(Vector3D<T> b) {
			return Vector3D<T>(fx + b.fx, fy + b.fy, fz + b.fz);
		}
		Vector3D<T> operator -(Vector3D<T> b){
			return Vector3D<T>(fx - b.fx, fy - b.fy, fz - b.fz );
		}
		Vector3D<T>& operator +=(Vector3D<T> b)
		{
			fx += b.fx;
			fy += b.fy;
			fz += b.fz;

			return this;
		}
		Vector3D<T>& operator -=(Vector3D<T> b)
		{
			fx -= b.fx;
			fy -= b.fy;
			fz -= b.fz;

			return this;
		}
		T& operator [](int index) {
			return (index == 0 ? fx :
					(index == 1 ? fy :fz 
					));


		}
		T operator |(Vector3D<T> b) {
			return T(fx*b.fx + fy*b.fy + fz*b.fz);
		}
		Vector3D<T> operator *(Vector3D<T> b) {
			return Vector3D<T>(
				fy*b.fz - fz*b.fy,
				fz*b.fx - fx*b.fz,
				fx*b.fy - fy*b.fx
				);
		}

	};
	template<typename T> T Dot(Vector3D<T> a, Vector3D<T> b) {
		return a | b;
	}
	template<typename T> Vector3D<T> Cross(Vector3D<T> a, Vector3D<T> b) {
		return a * b;
	}
	template<typename T> Vector3D<T> operator *(Vector3D<T> a, T b) {
		return Vector3D<T>(a[0] * b, a[1] * b, a[2] * b);
	}
	template<typename T> Vector3D<T> operator *(T a, Vector3D<T> b) {
		return b*a;
	}
	//typedef Vector3D<float> vector3Df;
	//typedef Vector3D<double> vector3Dd;
	//typedef Vector3D<int> vector3Di;
	
	using vector3Df = Vector3D<float>;
	
}