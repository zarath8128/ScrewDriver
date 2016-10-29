#include "Vector/Vector.h"
#include "Matrix/Matrix.h"
#include "BasicOperation/BasicOperation.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace ScrewDriver::Vector;
using namespace ScrewDriver::Matrix;
using namespace ScrewDriver::BasicOperation;

int main(){
	std::fstream file(f


	Vector<double> vmax(N), vmin(N), w(N);
	DenseMatrix<double> m(N);

	for(unsigned i = 0; i < N; ++i)
		vmax[i] = rand(), vmin[i] = rand(), w[i] = 1;

	for(unsigned r = 0; r < N; ++r)
		for(unsigned c = 0; c < N; ++c)
			m(r, c) = r == c ? -2 : r + 1 == c || r == c + 1 ? 1 : 0;

	m(0, 0) = -1;
	m(N - 1, N - 1) = -1;

	double eps = 1e-8;

	auto norm = [](const Vector<double>& v){return sqrt(dot(v, v));};
	auto normalize = [&](Vector<double> &v){double n = norm(v); v *= 1/n;};

	unsigned i = 0;
	double a = 1;
	double a2 = 1;
	double err = eps*10;
	while( err >= eps){
		w = m*vmax;
		a = dot(w, vmax)/dot(vmax, vmax);
		vmax = 1/norm(w)*w;
		w = m*vmin - a*vmin;
		a2 = dot(w, vmin)/dot(vmin, vmin);
		vmin = 1/norm(w)*w;
		err = norm(m*vmax - a*vmax) + norm(m*vmin - (a + a2)*vmin);
		++i;
		if(i % 10000 == 0)
			std::cout << err << "\n";
	}

	std::cout << "lambda1:" << a << "\n\n";
	//std::cout << vmax << "\n";
	std::cout << "error  :" << norm(a*vmax - m*vmax) << "\n";

	std::cout << "lambda2:" << a2 + a <<  "\n\n";
	//std::cout << vmin << "\n";
	std::cout << "error  :" << norm((a + a2)*vmin - m*vmin) << "\n";

	std::cout << "cond   : " << a/(a2 + a) << "\n";
	std::cout << "iterate: " << i << "\n";
}
