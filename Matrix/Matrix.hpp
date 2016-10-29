#pragma once

namespace ScrewDriver{
	namespace Matrix{
		template<class T> DenseMatrix<T>::DenseMatrix(unsigned s):DenseMatrix(s, s){}
		template<class T> DenseMatrix<T>::DenseMatrix(unsigned r, unsigned c):Row(r), Column(c), buf(new T[r*c]){}
		template<class T> template<class U> DenseMatrix<T>::DenseMatrix(const IMatrix<U> &m):DenseMatrix(m.row(), m.column()){ for(unsigned r = 0; r < Row; ++r) for(unsigned c = 0; c < Column; ++c) buf[r*Column + c] = m(r, c);}
		template<class T> DenseMatrix<T>::DenseMatrix(DenseMatrix &&m):Row(m.Row), Column(m.Column), buf(m.buf){ m.buf = nullptr; }

		template<class T> DenseMatrix<T>::~DenseMatrix(){ delete [] buf;}	

		template<class T> unsigned DenseMatrix<T>::row() const {return Row;}
		template<class T> unsigned DenseMatrix<T>::column() const {return Column;}

		template<class T> T &DenseMatrix<T>::operator()(unsigned r, unsigned c) {return buf[r*Column + c];}
		template<class T> const T &DenseMatrix<T>::operator()(unsigned r, unsigned c) const {return buf[r*Column + c];}


		template<class T> unsigned SparseMatrix<T>::row() const {return Row;}
		template<class T> unsigned SparseMatrix<T>::column() const {return Column;}
		
		template<class T> T &SparseMatrix<T>::set(unsigned row, unsigned column, const T &val){
			Row = std::max(Row, row);
			Column = std::max(Column, column);
			buf[index{row,column}] = val;
			return val;
		}

		template<class T> const T &SparseMatrix<T>::operator()(unsigned row, unsigned column) const{
			return buf[index{row, column}];
		}
	}
}
