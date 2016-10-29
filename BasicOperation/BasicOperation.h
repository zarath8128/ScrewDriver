#pragma once

#include <Vector/Vector.h>
#include <Matrix/Matrix.h>

namespace ScrewDriver{
	namespace BasicOperation{

		template<class T, class U>
		using RET = decltype(T() + U());

		template<class T, class U>
		Vector::Vector<RET<T, U>> operator*(const Matrix::IMatrix<T> &m, const Vector::IVector<U> &v);
		template<class T, class U>
		Vector::Vector<RET<T, U>> operator+(const Vector::IVector<T> &m, const Vector::IVector<U> &v);
		template<class T, class U>
		Vector::Vector<RET<T, U>> operator-(const Vector::IVector<T> &m, const Vector::IVector<U> &v);
		template<class T, class U>
		Vector::Vector<RET<T, U>> operator*(const T &a, const Vector::IVector<U> &v);

		template<class T, class U>
		RET<T, U> dot(const Vector::IVector<T> &v, const Vector::IVector<U> &w);
	}
}

#include "BasicOperation.hpp"
