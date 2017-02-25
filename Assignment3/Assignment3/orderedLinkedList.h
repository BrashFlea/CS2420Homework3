#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

template <class Type>
struct Node
{
	Type info;
	Node *next;
};


template <class Type>
class OrderedLinkedList
{
public:
	OrderedLinkedList();
	OrderedLinkedList(const OrderedLinkedList& other);
	~OrderedLinkedList();
	
	OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);
	
	int insert(const Type&);
	Type* find(int) const;
	Type* get(int) const;
	int remove(int);
        void clear();
        int size() const;
	void print() const;

private:
	Node<Type>* head;
	Node<Type>* tail;
	int count;
};

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other)
{
}

template <class Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{
	Node<Type> *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}

	tail = NULL;
	count = 0;
}

template <class Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)
{
return *this;
}

template <class Type>
int OrderedLinkedList<Type>::insert(const Type& item)
{
	Node<Type> *current = NULL;
	Node<Type> *trail = NULL;
	Node<Type> *newNode = NULL;
	bool found = false;

	newNode = new Node<Type>;
	newNode->info.setKey(item.getKey());
	newNode->info.setLastName(item.getLastName());
	newNode->info.setFirstInitial(item.getFirstInitial());
	newNode->info.setDues(item.getDues());
	newNode->next = NULL;

	//Empty list insert
	if (head == NULL) {
		int keyValue = newNode->info.getKey();
		head = newNode;
		tail = newNode;
		count++;
		newNode = NULL;
		return keyValue;
	}
	//Sorted item insert
	else {
		current = head;
		int keyValue = newNode->info.getKey();
		while (current != NULL && found != true) {
			if (current->info.getKey() >= item.getKey()) {
				found = true;
			}
			else {
				trail = current;
				current = current->next;
			}
		}//end search while loop
		if (current == head) {
			newNode->next = head;
			head = newNode;
			count++;
			return keyValue;
		}
		else {
			trail->next = newNode;
			newNode->next = current;

			if (current == NULL) {
				tail = newNode;
			}
			count++;
			return keyValue;
		}
	}
}

template <class Type>
Type* OrderedLinkedList<Type>::get(int dest) const
{
	Node<Type> *tmp = NULL;
	tmp = head;
	int location = 0;

	//Bounds check
	if (dest < 0 || dest > count) {
		return NULL;
	}

	while (location <= dest) {
		//Bounds check
		if (tmp == NULL){
			break;
		}
		//Equality check
		if (location == dest) {			
			return &tmp->info;
		}
		tmp = tmp->next;
		location++;
	}
	return NULL;
	
}

template <class Type>
Type* OrderedLinkedList<Type>::find(int dest) const
{
	Node<Type> *tmp = NULL;
	tmp = head;

	//Empty List check
	if (tmp == NULL) {
		return NULL;
	}

	int location = head->info.getKey();

	//Check head for key
	if (location == dest) {
		return &tmp->info;
	}

	//Traverse list to find key
	while (location != dest) {
			tmp = tmp->next;

			//End of list check
			if (tmp == NULL) {
				break;
			}

			location = tmp->info.getKey();
	}

	//return key
	if (location == dest) {
		return &tmp->info;
	}
	//not found
	else return NULL;

}

template <class Type>
int OrderedLinkedList<Type>::remove(int key)
{
return 0;
}

template <class Type>
void OrderedLinkedList<Type>::clear()
{
	Node<Type> *tmp;

	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}

	tail = NULL;
	count = 0;
}

template <class Type>
int OrderedLinkedList<Type>::size() const
{
	return count;
}

template <class Type>
void OrderedLinkedList<Type>::print() const
{
}
#endif
