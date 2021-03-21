#include "Libr.h"

template <typename T>
class Node                                         //���� ������� ������ � ���� data � ��������� �� ����� ����
{
public:
	T data;//T(����� ��� ������) data;
	Node(T data = T(), Node* pnext = nullptr)
	{
		this->data = data;
		this->pnext = pnext;
	}
	Node* pnext;//��������� �� ��������� ������ ������
	Node* pback;//��������� �� ���������� ������ ������
};


template<typename T>
class List
{
private:
	friend class Node<T>;
	int size;
	Node<T>* head;//head - ������ ������
public:
	List();
	~List();
	void push_back(T data);                             //�������� � �����
	void push_front(T data);                            //�������� � ������
	void pop_back();
	void pop_front();
	void clear();                                       //�������� flist
	int GetSize() { return size; }
	bool IsEmpty();
	Node<T>* begin() { return head; }                 // ��������� ��������� �� ������ ������ (����� ��� ���������)
	Node<T>* end();
};

template<typename T>
class myiterator                                              //��������
{
public:
	friend class List<T>;
	friend class Node<T>;
	void operator=(Node<T>* other);
	void operator ++(int a) { current = current->pnext; }
	T operator*() { return current->data; }
private:
	Node<T>* current;                                       // �������� ��������� �� �����-�� ������� ������
};


//int main()
//{
//	int a = 0;
//	a++;
//	List<int> list;
//	cout << "IsEmpty - " << list.IsEmpty() << endl;
//	cout << "Add elements" << endl;
//	list.push_front(5);
//	list.push_back(8);
//	list.push_front(7);
//	list.push_front(9);
//	list.push_back(4);  //97584
//	list.pop_back();
//	list.pop_front(); // 758
//	cout << "IsEmpty - " << list.IsEmpty() << endl;
//	cout << "GetSize - " << list.GetSize() << endl;
//	myiterator<int> it;
//	it = list.begin();                           //�������� ��������� �� ������ ������� ������
//	cout << "it begin - " << *it << endl;
//	it++; // �������� ��������� �� ������ ������� ������
//
//	cout << "it begin++ - " << *it << endl;      // *it ��������� data �� ������� ��������
//	list.clear();
//	cout << "list.clear()" << endl;
//	cout << "IsEmpty - " << list.IsEmpty() << endl;
//
//	/*Flist<Patient> plist;
//	plist.push_front(Patient(42, "Egor", "some", 35, 10, "none", 5));
//	plist.push_front(Patient(22, "Igor", "some", 35, 1, "second"));
//	plist.push_front(Patient(32, "Timur", "some", 25, 2, "average"));
//	cout << "IsEmpty - " << plist.IsEmpty() << endl;
//	cout << "GetSize - " << plist.GetSize() << endl;
//	myiterator<Patient> pit;
//	pit = plist.begin();
//	cout << "it begin - " << *pit << endl;
//	it++;
//	cout << "it begin++ - " << *pit << endl;*/
//}

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* cur;
	Node<T>* cur2;
	cur = head;
	if (head == nullptr)                         // ���� ��� ���� ������ ��������� ������� � ������� � ������� �� ������
	{
		head = new Node<T>(data);
		this->size++;
		return;
	}
	while (cur->pnext != nullptr)                   // ���� �� ������,�� ��������� � ����� � ��������� ���
	{
		cur = cur->pnext;
	}
	cur->pnext = new Node<T>(data);
	cur2 = cur->pnext;
	cur2->pnext = nullptr;
	cur2->pback = cur;
	this->size++;
}

template<typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		this->size++;
		return;
	}
	Node<T>* node = new Node<T>(data);                  //������� ����� ������� � ������ ��� ����� head
	node->pnext = this->head;
	node->pback = nullptr;
	this->head = node;
	this->size++;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* cur;//������ ������ ����
	Node<T>* cur2;
	cur = head;//��������� �� ������
	while (cur->pnext != nullptr)// ���� �� ������,�� ��������� � ����� � ��������� ���, ���������� �� ������ �� ���������� ��������
	{
		cur = cur->pnext;
	}
	cur2 = cur;
	cur = cur->pback;
	cur->pnext = nullptr;
	delete cur2;
	this->size--;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* cur;
	cur = head;
	head = head->pnext;
	delete cur;
	head->pback = nullptr;
	this->size--;
}

template<typename T>
void List<T>::clear()
{
	Node<T>* cur;
	Node<T>* cur2;
	cur = this->head;
	while (cur->pnext != nullptr)                //� ������� cur ��������� �� ������, cur2- ������� ��������
	{
		cur2 = cur;
		cur = cur->pnext;
		delete cur2;
		size--;
	}
	delete cur;
	size--;
}

template<typename T>
bool List<T>::IsEmpty()
{
	return !(this->size);
}

template<typename T>
Node<T>* List<T>::end()
{
	Node<T>* cur;//������ ������ ����
	cur = head;//��������� �� ������
	while (cur->pnext != nullptr)// ���� �� ������,�� ��������� � ����� � ��������� ���, ���������� �� ������ �� ���������� ��������
	{
		cur = cur->pnext;
	}
	return cur;
}

template<typename T>
void myiterator<T>::operator=(Node<T>* other)
{
	this->current = other;
}