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
	void copyList(const OrderedLinkedList<Type>& other);

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
	head = NULL;
	copyList(other);
}

template <class Type>
void OrderedLinkedList<Type>::copyList(const OrderedLinkedList<Type>& other)
{
	Node<Type> *newNode = NULL;
	Node<Type> *current = NULL;

	//Clear current list
	if (head != NULL) {
		this->clear();
	}

	//Other is empty
	if (other.head == NULL) {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	else {
		current = other.head;
		count = other.count;

		//First node
		head = new Node<Type>;
		head->info = current->info;
		head->next = NULL;
		tail = head;
		current = current->next;

		//Rest of the list
		while (current != NULL) {
			newNode = new Node<Type>;
			newNode->info = current->info;
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			current = current->next;
		}

	}
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
	if (this != &other)
	{
		copyList(other);
	}
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

	//Return key
	if (location == dest) {
		return &tmp->info;
	}
	//Not found
	else return NULL;

}

template <class Type>
int OrderedLinkedList<Type>::remove(int key)
{

//Modified find implementation
	Node<Type> *tmp = NULL;
	Node<Type> *remove = NULL;
	Node<Type> *trailTmp = NULL;
	tmp = head;

	//Empty List check
	if (tmp == NULL) {
		return -1;
	}

	int location = head->info.getKey();

	//Check head for key
	if (location == key) {
		remove = tmp;
	}

	//Traverse list to find key
	while (location != key) {
		trailTmp = tmp;
		tmp = tmp->next;

		//End of list check
		if (tmp == NULL) {
			break;
		}

		location = tmp->info.getKey();
	}

	//Return key
	if (location == key) {
		remove = tmp;
	}
	//Not found
	else return -1;
//End find implementation

	//Delete from head
	if (remove == head) {
		head = remove->next;
		delete remove;
	}
	//Delete remove tail
	else if (remove == tail) {
		tail = trailTmp;
		tail->next = NULL;
		delete remove;
	}
	//Delete from middle
	else {
		trailTmp->next = tmp->next;
		tmp->next = NULL;
		delete remove;
	}

	count--;

return key;
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
