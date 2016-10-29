#pragma once

#include <ostream>

namespace ScrewDriver{
	namespace Vector{

		template<class T>
		struct IVector{
			virtual unsigned size() const = 0;
			virtual T &operator[](unsigned index) = 0;
			virtual const T &operator[](unsigned index) const = 0;
		};

		template<class T>
		class Vector : public IVector<T>{
			const unsigned N;
			T *buf = nullptr;
			
		public:
			Vector(unsigned N);
			~Vector();
			template<class U>
			Vector(const IVector<U>& v);
			Vector(Vector &&v);

			T &operator[](unsigned index);
			const T &operator[](unsigned index) const;

			template<class U> Vector& operator=(const IVector<U> &v);
			Vector& operator=(const Vector &v);
			Vector& operator=(Vector &&v);
			template<class U> Vector& operator+=(const Vector<U>& v);
			template<class U> Vector& operator-=(const Vector<U>& v);
			template<class U> Vector& operator*=(const U& a);


			unsigned size() const;

		};

		template<class T>
		std::ostream &operator<<(std::ostream &dest , const IVector<T> &src);

	}
}

#include "Vector.hpp"
