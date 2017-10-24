#include<cstdio>
#include"vector_stack.h"
using namespace std;
int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	int *pa = new int[n+1];  //入口进入时火车
	int *pb = new int[n+1];  //出口时火车
	for(int i = 0; i < n; i++)
		cin>>pa[i];
	//scanf("%d", &pa[i]);
    Vector<int> vstk(0);   //中转的栈
    Vector<int> v1(0); Vector<char> v2(0); //储存要输出的数字和字符
    int flag = 0; //表示B中的车厢节数
    for(int i = 0; i < n; i++){
    	if(flag == 0 || pb[flag-1] == (pa[i] - 1) ){
    		// B中为空或者比A中当前元素少1，直接通过
    		pb[flag++] = pa[i];
    		v1.push_back(pa[i]);
    		v2.push_back('P');
    	}else if( (vstk.empty() || vstk.back() != (pb[flag-1] +1) ) && vstk.size() < m ){
    		//栈未满且已有栈顶元素与B中尾元素不能组成合题排序，A中当前元素入栈
    		vstk.push_back(pa[i]); 
    		v1.push_back(pa[i]);
    		v2.push_back('I');
    	}else if(vstk.back() == (pb[flag-1] + 1) ){
    		//栈顶元素可以和B中尾元素组成合题排序，出站
    		pb[flag++] = vstk.back();
    		v1.push_back( vstk.back() );
    		v2.push_back('O');
    		vstk.pop_back();
    		while(!vstk.empty() && vstk.back() == (pb[flag-1] + 1) ){
    			//栈顶元素持续出站
    			pb[flag++] = vstk.back();
    			v1.push_back( vstk.back() );
    		    v2.push_back('O');
    		    vstk.pop_back();
    		}
    		vstk.push_back(pa[i]);  //栈出空或者栈顶元素不再合题时A中当前元素进栈
    		v1.push_back(pa[i]);
    		v2.push_back('I');
    	}else{
    		printf("No"); //以上三种情况都不满足，输出结果并返回
    		return 0;
    	}
    }
	while(!vstk.empty() ){
		if(vstk.back() != (pb[flag-1] + 1)){
    		printf("No"); //以上三种情况都不满足，输出结果并返回
    		return 0;
		}else {
			pb[flag++] = vstk.back();
			v1.push_back( vstk.back() );
    		v2.push_back('O');
    		vstk.pop_back();
		}
	}
    for(int i = 0; i < v1.size(); i++ ) printf("%d %c\n", v1[i], v2[i]); //打印结果
	delete[] pa, pb;
    pa = NULL; pb = NULL;
    return 0;
}