#include<iostream>
#include<cstdio>
using namespace std;
template<typename T> class Vector{   //向量模板类
	private:
		int _size, _capacity; T* _elem;
	public:
		Vector(int c = 3){ _elem = new T[_capacity = c + 1 ]; _size = 0; }  //构造函数
		void expand(){   //扩容
			if(_size < _capacity) return;
			_capacity = 3 < _capacity ? _capacity : 3 ;   //不低于最小容量
			T* oldelem = _elem; _elem = new T[_capacity << 1];  //重新申请新的动态内存
			for(int i = 0; i < _size; i++) _elem[i] = oldelem[i];  //复制元素
			delete [] oldelem;  //释放原空间
		}
		void shrink(){    //缩容
			if(_capacity/2 < _size) return;
			_capacity = 3 < _capacity >> 1 ? _capacity : 3 ;   //缩减容量，但不低于最小容量
			T* oldelem = _elem; _elem = new T[_capacity];  //重新申请新的动态内存
			for(int i = 0; i < _size; i++) _elem[i] = oldelem[i];  //复制元素
			delete [] oldelem;  //释放原空间
		}
		int size(){ return _size;}  //查询size
		void push_back( T a){ expand(); _elem[ _size++ ] = a; } //从尾部插入
		T pop_back(){ return _elem[--_size]; }   //删除尾部元素
		T back(){  return _size == 0 ? 0 : _elem[_size - 1]; }   //查看尾部元素
		T operator[](int i){ return _elem[i]; }
		bool empty(){return _size == 0; }
		~Vector(){ delete[] _elem; }   //析构函数
};

template<typename T> 
class Stack: public Vector<T>{  //栈类
	public:
		void push(T const & e){ this->push_back(e); }  //压入,(模板继承时候用this来调用父类的成员函数和数据)
		T top(){return this->back(); }  //查看顶元素
		T pop(){return this->pop_back(); }  //剔除顶元素
		Stack(int a):Vector<T>(a){}
		~Stack(){}
};

