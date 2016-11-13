#pragma once
#include <vector>
#include <complex>



namespace fft {
	typedef std::complex<float> complexf;
	typedef std::vector<complexf> cdata;
	class Data {
	private:
		cdata data;
	public:
		Data(size_t size);
		~Data();
		complexf& operator[](int index);
		void dofft();
		void doifft();
		cdata fft();
		cdata ifft();
		
	};
}