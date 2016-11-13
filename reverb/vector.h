#pragma once

namespace mymath {
	template<typename T> class Vector3D {
	private:
		T fx, fy, fz;
	public:
		Vector3D(T ax, T ay, T az);
		virtual ~Vector3D();
		Vector3D<T> operator +(T b);
		Vector3D<T> operator -(T b);
		Vector3D<T>& operator +=(Vector3D<T> b);
		Vector3D<T>& operator -=(Vector3D<T> b);
		T& operator [](int index);
		T operator |(Vector3D<T> b);
		Vector3D<T> operator *(Vector3D<T> b);

	};
	template<typename T> T Dot(Vector3D<T> a, Vector3D<T> b);
	template<typename T> Vector3D<T> Cross(Vector3D<T> a, Vector3D<T> b);

	typedef Vector3D<float> vector3Df;
	typedef Vector3D<double> vector3Dd;
	typedef Vector3D<int> vector3Di;

}