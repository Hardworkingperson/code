#include<iostream>
#include<vector>
using namespace std;
#define eleType int //����һ���꣬����Ϊint����

/// �ҳ��νӴ����˳�����������һ�¸о����˳����е���̬�ڴ����

struct SequList {//����һ���ṹ������ΪSequList  
	eleType* elements; //����һ��eleType���͵�ָ������Ϊelements
	int size;//�����С
	int capacity;//����
};

void initList(SequList *list,int capacity){//����һ����̬�ڴ�ķ���
	list->elements =new eleType[capacity];//newһ����̬����
	list->size = 0;//���㿪ʼ
	list->capacity = capacity;//����ĳ���

}

void destList(SequList *list) {//ֱ������˳����ͷŶ�̬�ڴ�

	delete[]list->elements;
}

int Size(SequList* list) {//�������鳤��
	return list->size;
}

bool isEnpty(SequList* list) {//����Ƿ�Ϊ��
	return list->size == 0;
}

void insert(SequList* list,int index,eleType element) {//˳���������
	if (index<0 || index>list->size) {//�ж�index�Ƿ��0С�����ֵ��
		throw std::invalid_argument("error index");//�׳��쳣
	}
	if (list->size == list->capacity) {//��̬��̬�ﲻ���϶����ټ��ڴ��С��
		int newCapacity = list->capacity * 2;//ֱ�ӽ�ԭ���ĳ�2
		eleType* newElements = new eleType[newCapacity];//��������ȸ�ֵ���µĳ�������
		for (int i = 0; i < list->size; ++i) {
			newElements[i] = list ->elements[i];//�ٽ������ֵ��������
		}
		delete[] list->elements;//�������
		list->elements = newElements;//����ָ��ָ��������
		list->capacity = newCapacity;//��������
	}
	for (int i = list->size; i > index; i--) {
		list->elements[i] = list->elements[i - 1];//��������±���������Ϊ
	}
	list->elements[index] = element;//�ٽ��µ�ֵ�������λ��
	list->size++;//����Ԫ������

}

void deletElement(SequList* list, int index) {//ɾ��һ����ַ������Ȼ��ɾ������ǰ���
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
	cout << "Size:" << Size( &mylist) << endl;//֮ǰ������д����д����size
	//cout << "Size:" << mylist.size << endl;��������õķ���


	return 0;
}






//int main() {
//	vector<int> ret;
//	cout << ret.size() << endl;
//}
