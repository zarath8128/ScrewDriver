#pragma once 
#include <map>

namespace ScrewDriver{
	namespace Matrix{
		template<class T>
		struct IMatrix{
			virtual unsigned row() const = 0;
			virtual unsigned column() const = 0;

			virtual T &operator()(unsigned row, unsigned column) = 0;
			virtual const T &operator()(unsigned row, unsigned column) const = 0;
		};

		template<class T>
		class DenseMatrix : public IMatrix<T>{
			const unsigned Row, Column;
			T *buf;
		
		public:
			DenseMatrix(unsigned Size);
			DenseMatrix(unsigned Row, unsigned Column);
			template<class U>
			DenseMatrix(const IMatrix<U> &m);
			DenseMatrix(DenseMatrix &&m);

			~DenseMatrix();

			unsigned row() const;
			unsigned column() const;

			T &operator()(unsigned row, unsigned column);
			const T &operator()(unsigned row, unsigned column) const;
		};
		
		template<class T>
		class SparseMatrix : public IMatrix<T>{
			unsigned Row, Column;
			struct index{
				unsigned r, c;
				constexpr bool operator <(const index &i) const {return r < i.r || r == i.r && c < i.c;}
			};
			std::map<index, T> buf;

			T &set(unsigned row, unsigned column, const T &v);
		public:
			SparseMatrix();

			unsigned row() const;
			unsigned column() const;

			const T &operator()(unsigned row, unsigned column) const;	
		};
	}
}

#include "Matrix.hpp"
