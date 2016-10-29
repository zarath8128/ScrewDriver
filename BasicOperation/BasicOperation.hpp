#pragma once

namespace ScrewDriver{
	namespace BasicOperation{

		template<class T, class U>
		Vector::Vector<RET<T, U>> operator*(const Matrix::IMatrix<T> &m, const Vector::IVector<U> &v){
			Vector::Vector<RET<T, U>> ret(m.row());
			for(unsigned i = 0; i < ret.size(); ++i){
				ret[i] = 0;
				for(unsigned j = 0; j < m.column(); ++j)
					ret[i] += m(i, j)*v[j];
			}
			return ret;
		}

		template<class T, class U>
		Vector::Vector<RET<T, U>> operator+(const Vector::IVector<T> &v, const Vector::IVector<U> &w){
			Vector::Vector<RET<T, U>> ret(v.size());
			for(unsigned i = 0; i < v.size(); ++i)
				ret[i] = v[i] + w[i];
			return ret;
		}

		template<class T, class U>
		Vector::Vector<RET<T, U>> operator-(const Vector::IVector<T> &v, const Vector::IVector<U> &w){
			Vector::Vector<RET<T, U>> ret(v.size());
			for(unsigned i = 0; i < v.size(); ++i)
				ret[i] = v[i] - w[i];
			return ret;
		}

		template<class T, class U>
		Vector::Vector<RET<T, U>> operator*(const T &a, const Vector::IVector<U> &w){
			Vector::Vector<RET<T, U>> ret(w.size());
			for(unsigned i = 0; i < w.size(); ++i)
				ret[i] = a*w[i];
			return ret;
		}

		template<class T, class U>
		Vector::Vector<T> operator+=(const Vector::IVector<T> &v, const Vector::IVector<U> &w){
			Vector::Vector<RET<T, U>> ret(v.size());
			for(unsigned i = 0; i < v.size(); ++i)
				v[i] += w[i];
			return v;
		}

		template<class T, class U>
		Vector::Vector<T> operator-=(const Vector::IVector<T> &v, const Vector::IVector<U> &w){
			for(unsigned i = 0; i < v.size(); ++i)
				v[i] -= w[i];
			return v;
		}

		template<class T, class U>
		Vector::Vector<T> operator*=(const Vector::IVector<T> &v, const U &a){
			for(unsigned i = 0; i < v.size(); ++i)
				v[i] *= a;
			return v;
		}


		template<class T, class U>
		RET<T, U> dot(const Vector::IVector<T> &v, const Vector::IVector<U> &w){
			RET<T, U> ret = 0;
			for(unsigned i = 0; i < v.size(); ++i)
				ret += v[i]*w[i];
			return ret;
		}
	}
}
