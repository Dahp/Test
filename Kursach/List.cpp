#include "Libr.h"

template <typename T>
class Node                                         //Узел который хранит в себе data и указатель на некст узел
{
public:
	T data;//T(любой тип данных) data;
	Node(T data = T(), Node* pnext = nullptr)
	{
		this->data = data;
		this->pnext = pnext;
	}
	Node* pnext;//указатель на следующий объект списка
	Node* pback;//указатель на предыдущий объект списка
};


template<typename T>
class List
{
private:
	friend class Node<T>;
	int size;
	Node<T>* head;//head - начало списка
public:
	List();
	~List();
	void push_back(T data);                             //Добавить в конец
	void push_front(T data);                            //Добавить в начало
	void pop_back();
	void pop_front();
	void clear();                                       //Очистить flist
	int GetSize() { return size; }
	bool IsEmpty();
	Node<T>* begin() { return head; }                 // Возращает указатель на начало списка (нужен для итератора)
	Node<T>* end();
};

template<typename T>
class myiterator                                              //итератор
{
public:
	friend class List<T>;
	friend class Node<T>;
	void operator=(Node<T>* other);
	void operator ++(int a) { current = current->pnext; }
	T operator*() { return current->data; }
private:
	Node<T>* current;                                       // итератор указывает на какой-то элемент списка
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
//	it = list.begin();                           //Итератор указывает на первый элемент списка
//	cout << "it begin - " << *it << endl;
//	it++; // Итератор указывает на второй элемент списка
//
//	cout << "it begin++ - " << *it << endl;      // *it возращает data из данного элемента
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
	if (head == nullptr)                         // Если наш лист пустой добавляем элемент в началло и выходим из метода
	{
		head = new Node<T>(data);
		this->size++;
		return;
	}
	while (cur->pnext != nullptr)                   // Если не пустой,то двигаемся в конец и добавляем там
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
	Node<T>* node = new Node<T>(data);                  //Создаем новый элемент и делаем его нашим head
	node->pnext = this->head;
	node->pback = nullptr;
	this->head = node;
	this->size++;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* cur;//объект класса узел
	Node<T>* cur2;
	cur = head;//указывает на начало
	while (cur->pnext != nullptr)// Если не пустой,то двигаемся в конец и добавляем там, двингаемся по списку до последнего элемента
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
	while (cur->pnext != nullptr)                //С помощью cur двигаемчя по списку, cur2- удаляем элементы
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
	Node<T>* cur;//объект класса узел
	cur = head;//указывает на начало
	while (cur->pnext != nullptr)// Если не пустой,то двигаемся в конец и добавляем там, двингаемся по списку до последнего элемента
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