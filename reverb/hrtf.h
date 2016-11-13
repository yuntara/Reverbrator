#pragma once
#include <fstream>
#include "combolution.h"

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
