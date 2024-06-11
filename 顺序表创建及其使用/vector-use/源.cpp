#include<iostream>
#include<vector>
using namespace std;
#define eleType int //定义一个宏，类型为int类型

/// 我初次接触这个顺序表让我评价一下感觉这个顺序表有点像动态内存分配

struct SequList {//定义一个结构体命名为SequList  
	eleType* elements; //定义一个eleType类型的指针命名为elements
	int size;//定义大小
	int capacity;//扩容
};

void initList(SequList *list,int capacity){//创建一个动态内存的方法
	list->elements =new eleType[capacity];//new一个动态数组
	list->size = 0;//从零开始
	list->capacity = capacity;//数组的长度

}

void destList(SequList *list) {//直接销毁顺序表释放动态内存

	delete[]list->elements;
}

int Size(SequList* list) {//返回数组长度
	return list->size;
}

bool isEnpty(SequList* list) {//检查是否为空
	return list->size == 0;
}

void insert(SequList* list,int index,eleType element) {//顺序表插入操作
	if (index<0 || index>list->size) {//判断index是否比0小比最大值大
		throw std::invalid_argument("error index");//抛出异常
	}
	if (list->size == list->capacity) {//动态动态嘛不够肯定是再加内存大小噻
		int newCapacity = list->capacity * 2;//直接将原本的乘2
		eleType* newElements = new eleType[newCapacity];//将这个长度赋值给新的长度数组
		for (int i = 0; i < list->size; ++i) {
			newElements[i] = list ->elements[i];//再将这个赋值给新数组
		}
		delete[] list->elements;//清空数组
		list->elements = newElements;//更新指针指向新数组
		list->capacity = newCapacity;//更新容量
	}
	for (int i = list->size; i > index; i--) {
		list->elements[i] = list->elements[i - 1];//将插入的下标后面向后移为
	}
	list->elements[index] = element;//再将新的值插入这个位置
	list->size++;//更新元素数量

}

void deletElement(SequList* list, int index) {//删除一个地址的数据然后将删除的往前面填补
	if (index<0 || index>=list->size) {
		throw std::invalid_argument("error index");
	}
	for (int i = index; i < list->size - 1; ++i) {
		list->elements[i] = list->elements[i + 1];
	}
	list->size--;
}

int findElement(SequList* list, eleType element) {
	for (int i = 0; i < list->size; i++) {
		if (list->elements[i] == element) {
			return i;
		}
	}
	return -1;
}

eleType getElement(SequList* list, int index) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("error index");
	}
	return list->elements[index];
}
void updateElement(SequList* list, int index, eleType value) {
	list->elements[index] = value;
}

int main() {
	SequList mylist;
	initList(&mylist, 10);
	for (int i = 0; i < 10; i++) {
		insert(&mylist, i, i * 10);
		
	}
	for (int i = 0; i < 10; i++) {
		cout << mylist.elements[i]<< " ";
	}
	cout << "Size:" << Size( &mylist) << endl;//之前方法名写错了写成了size
	//cout << "Size:" << mylist.size << endl;这个是内置的方法


	return 0;
}






//int main() {
//	vector<int> ret;
//	cout << ret.size() << endl;
//}
