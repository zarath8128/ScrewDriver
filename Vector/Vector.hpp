#pragma once

namespace ScrewDriver{
	namespace Vector{
	
		template<class T> Vector<T>::Vector(unsigned N):N(N), buf(new T[N]){}
		template<class T> template<class U> Vector<T>::Vector(const IVector<U> &v):N(v.size()), buf(new T[N]){for(unsigned i = 0; i < N; ++i) buf[i] = v[i];}
		template<class T> Vector<T>::Vector(Vector &&v):N(v.N), buf(v.buf){v.buf = nullptr;}

		template<class T> Vector<T>::~Vector(){delete [] buf;}

		template<class T> T &Vector<T>::operator[](unsigned i){return buf[i];}
		template<class T> const T &Vector<T>::operator[](unsigned i) const {return buf[i];}

		template<class T> template<class U> Vector<T> &Vector<T>::operator=(const IVector<U> &v){ for(unsigned i = 0; i < N; ++i) buf[i] = v[i]; return *this;}
		template<class T> Vector<T> &Vector<T>::operator=(const Vector<T> &v){ for(unsigned i = 0; i < N; ++i) buf[i] = v[i]; return *this;}
		template<class T> Vector<T> &Vector<T>::operator=(Vector<T> &&v){ delete [] buf; buf = v.buf; v.buf = nullptr; return *this;}
		template<class T> template<class U> Vector<T> &Vector<T>::operator+=(const Vector<U> &v){ for(unsigned i = 0; i < N; ++i) buf[i] += v[i]; return *this;}
		template<class T> template<class U> Vector<T> &Vector<T>::operator-=(const Vector<U> &v){ for(unsigned i = 0; i < N; ++i) buf[i] -= v[i]; return *this;}
		template<class T> template<class U> Vector<T> &Vector<T>::operator*=(const U &a){ for(unsigned i = 0; i < N; ++i) buf[i] *= a; return *this;}

		template<class T> unsigned Vector<T>::size() const{return N;}

		template<class T>
		std::ostream &operator<<(std::ostream &dest , const IVector<T> &src){
			for(unsigned i = 0; i < src.size(); ++i)
				dest << src[i] << "\n";
			return dest;
		}
	}
}
