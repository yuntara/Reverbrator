#pragma once
#include <fstream>
#include "combolution.h"
/*
F(w) = ��f(t) e^(-iwt) dt

��f(t-X) e^(-iwt) dt
=��f(t-X)e^(-iw(t-X))* e^(-iwX) dt
=e^(-iwX) * F(w)

*/
namespace hrtf {
	class Hrtf :public combolution::Filter{
	private:

	public:

	};
	class HrtfCollection {
	private:
		std::vector<Hrtf> hrtfs;
	public:

	};
}
