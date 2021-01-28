// 堆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


//小顶堆为例子
class Heap {

public:
	Heap(int length, int source[]) {//要建立多少个节点的堆 堆中赋值应该是多少  注意 可以有一部分不赋值 而且是从下标为1开始赋值的 
	//我这里默认是按照传入数组的两倍或者直接+10建立的堆 以后节点不够了再重新开 
		value_length = length;
		if (length < 10)
		{
			size = length + 20;
		}
		else {
			size = length * 2;
		}
		p = (int*)malloc(size);
		value_length = length;
		for (int i = 1; i <= length; i++) {
			p[i] = source[i-1];
		}
	}
	void Print_heap() {
		int row_num = 1;
		int num = 0;
		for (int i = 1; i <= value_length; i++) {
			cout << " " << p[i];
			num++;
			if (row_num == num)
			{
				num = 0;
				row_num = row_num * 2;
				cout << endl;
			}
		}
		cout << endl;
	}
	int length() {
		return value_length;
	}
	bool compare_value(int x, int y) {
		return p[x] < p[y];
	}
	void changeOver(int x, int y) {
		int temp = p[x];
		p[x] = p[y];
		p[y] = temp;
	}
	void sink(int x) {
		//x的节点值<2*x的节点值 那 就不用管
		//否则要交换
		//Print_heap();

		if (x*2 > value_length)//越界了 不能交换 到此为止
			return;
		if (!compare_value(x, 2 * x)) {
			changeOver(x, 2 * x);
			sink(2 * x);

		}
		else if (!compare_value(x, 2 * x+1)) {
			changeOver(x, 2 * x+1);
			sink(2 * x+1);
		}
	}
	void HeapUP(int x) {//这里输入的是下标
		if (x == 1)
		{
			return;
		}
		if (compare_value(x, x / 2)) {
			changeOver(x, x / 2);
			HeapUP(x / 2);
		}

	}

	void insert_value(int value) {
		value_length++;
		p[value_length] = value;
		HeapUP(value_length);
	}
	
	void replace_value(int x) { //移除堆顶 替换为新值
		p[1] = x;
		sink(1);
	}

	void delete_smallest() {//删了你别忘了维护这个堆
		//输出堆顶
		cout << "堆顶为 "<<p[1] << endl;
		p[1] = p[value_length--];//把屁股上的那个拿过来当堆顶 然后调整堆
		sink(1);
	}
private:
	int *p;
	int value_length;//有效数据的节点数
	int size;  //总长度
};
int main()
{	
	int x[] = { 1,2,3,4,5,6,7,8,9 };
	Heap heap(9,x);
	//cout << heap.length() << endl;
	heap.Print_heap();
	//heap.insert_value(2);
	//heap.Print_heap();

	//heap.replace_value(10);
	//heap.Print_heap();

	heap.delete_smallest();
	heap.Print_heap();

	return 0;
	//    std::cout << "Hello World!\n"; 
}
