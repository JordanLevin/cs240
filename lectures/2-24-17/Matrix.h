#ifndef MATRIX_H
#define MATRIX_H

#define MAX_ROWS 10
#define MAX_COLUMNS 10
template <class U>
class Matrix<U>;

//friend classes
//helpful for lab stuff
template <class U> //u could be t
class Foo{
	U x;
	Matrix<u> m;

	U bar(){
		m.rows;
	}
};

template <class T>
class Matrix{
	friend class Foo<T>; //foo can access private variables of matrix
	private:
		T doubleArray[MAX_ROWS][MAX_COLUMNS];
		int rows;
		int cols;
	public:
		Matrix(){
			rows = MAX_ROWS;
			cols = MAX_COLUMNS;
		}
		void printMatrix();
		void setMatrix(T [][MAX_COLUMNS]){ //c++ doesnt need size of first dimension because array is passed by reference, needs all other dimension sizes
			doubleArray = arr;
		}
};

template <class T>
void Matrix<T>::printMatrix(){
	for(int i =0;i<rows;i++){
		for(int j = 0;j<cols;j++){
			std::cout<< doubleArray[i][j];
		}
		std::cout<<std::endl;
	}
}
template <class T>
void Matrix<T>::setMatrix(T arr[][MAX_COLUMNS]){
	doubleArray = arr;
}

#endif
