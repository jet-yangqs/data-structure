#define posi(T) Listnode<T>*  //宏定义
template<typename T> struct Listnode{   //节点类  
	T data;  //数据
	posi(T) pred;  //前驱
	posi(T) succ;  //后继
	Listnode(){}  //针对header和trailer的构造
	Listnode(T e, posi(T) p = NULL, posi(T) s = NULL): data(e), pred(p), succ(s){} //构造函数
	posi(T) insertAspred(T const & e){   //前插入
		posi(T) x = new Listnode(e, pred, this);
		pred->succ = x; pred = x;
	}
	posi(T) insertAssucc(T const & e){    //后插入
		posi(T) x = new Listnode(e, this, succ);
		succ->pred = x; succ = x;
	}
}

template<typename T> class List{   //列表类
	private: 
		int _size;   //规模
		posi(T) header, trailer;  //头、尾哨兵
	public:
		init(){   //初始化，创建列表对象时候统一调用
			hearder = new Listnode<T>;
			trailer = new Listnode<T>;
			header->pred = NULL; header->succ = trailer;  //互联
			trailer->pred = hearder; trailer->succ = NULL;   //互联
		}
		T
		List(){

		}

}
