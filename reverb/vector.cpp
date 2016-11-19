#include "vector.h"

namespace mymath {
	template<typename T>
	Vector3D<T>::Vector3D()
	{
	}
	template<typename T>
	Vector3D<T>::Vector3D(T ax, T ay, T az) :fx(ax), fy(ay), fz(az) {

	}
	template<typename T>
	Vector3D<T>::~Vector3D(){
	}
	template<typename T>
	inline Vector3D<T> Vector3D<T>::operator+(T b){
		return Vector3D<T>(fx + b.fx, fy + b.fy, fz + b.fz, );
	}

	template<typename T>
	Vector3D<T> Vector3D<T>::operator-(T b){
		return Vector3D<T>(fx - b.fx, fy - b.fy, fz - b.fz, );
	}

	template<typename T>
	Vector3D<T>& Vector3D<T>::operator+=(Vector3D<T> b)
	{
		fx += b.fx;
		fy += b.fy;
		fz += b.fz;

		return this;
	}

	template<typename T>
	Vector3D<T>& Vector3D<T>::operator-=(Vector3D<T> b)
	{
		fx -= b.fx;
		fy -= b.fy;
		fz -= b.fz;

		return this;
	}

	template<typename T>
	T& Vector3D<T>::operator[](int index)
	{
		return (index == 0 ? fx :
			   (index == 1 ? fy :
			   (index == 2 ? fz : nullptr
					)));
				

	}

	template<typename T>
	T Vector3D<T>::operator|(Vector3D<T> b)
	{
		return T(fx*b.fx + fy*b.fy + fz*b.fz);
	}

	template<typename T>
	Vector3D<T> Vector3D<T>::operator*(Vector3D<T> b)
	{
		return Vector3D<T>(fy*b.fz - fz*b.fy,
						   fz*b.fx - fx*b.fz,
						   fx*b.fy - fy*b.fx);
	}


	template<typename T>
	T Dot(Vector3D<T> a, Vector3D<T> b) {
		return a | b;
	}
	template<typename T>
	Vector3D<T> Cross(Vector3D<T> a, Vector3D<T> b) {
		return a * b;
	}
}
