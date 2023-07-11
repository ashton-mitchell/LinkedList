#pragma once
#include <iostream>

// templated node class usable in a singly, doubly, and circularly linked list
template <typename T>
class Node {

private:
	T data;
	Node<T>* next;
	Node<T>* previous;
public:
	Node();
	Node(T data_);
	Node(T data_, Node<T>* next_);
	Node(T data_, Node<T>* next_, Node<T>* previous_);
	T getData();
	void setData(T data_);
	Node<T>* getNext();
	void setNext(Node<T>* next_);
	Node<T>* getPrevious();
	void setPrevious(Node<T>* previous_);
};

// default Node constructor
template <typename T>
Node<T>::Node() {
	this->data = T();
	this->next = nullptr;
	this->previous = nullptr;
}

// Node constructor that takes the data to be stored in the Node as a parameter
template <typename T>
Node<T>::Node(T data_) {
	this->data = data_;
	this->next = nullptr;
	this->previous = nullptr;
}

// Node constructor that takes the data to be stored in the Node and the next Node in the linked list as a parameter
template <typename T>
Node<T>::Node(T data_, Node<T>* next_) {
	this->data = data_;
	this->next = next_;
	this->previous = nullptr;
}

// Node constructor that takes the data to be stored in the Node and the next and previous Node in the linked list as a parameter
template <typename T>
Node<T>::Node(T data_, Node<T>* next_, Node<T>* previous_) {
	this->data = data_;
	this->next = next_;
	this->previous = previous_;
}

// returns the data stored in a Node
template <typename T>
T Node<T>::getData() {
	return data;
}

// sets the data to be stored in a Node
template <typename T>
void Node<T>::setData(T data_) {
	data = data_;
}

// reutrns the next Node in the linked list 
template <typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

// sets what the next Node in the linked list will be
template <typename T>
void Node<T>::setNext(Node<T>* next_) {
	next = next_;
}

// returns the previous Node in the linked list
template <typename T>
Node<T>* Node<T>::getPrevious() {
	return previous;
}

// sets what the previous Node in the linked list will be
template <typename T>
void Node<T>::setPrevious(Node<T>* previous_) {
	previous = previous_;
}


// templated Singly Linked List class
template <typename T>
class SinglyLinkedList {

private:
	Node<T>* head;
public:
	SinglyLinkedList();
	SinglyLinkedList(Node<T>* head_);
	void addToFront(T data_);
	void addToEnd(T data_);
	void addAtIndex(T data_, int index_);
	void addBefore(Node<T>* node_, T data_);
	void addAfter(Node<T>* node_, T data_);
	T removeFromFront();
	T removeFromEnd();
	T removeAtIndex(int index_);
	T removeFirstInstanceOf(T data_);
	int removeAllInstancesOf(T data_);
	T removeBefore(Node<T>* node_);
	T removeAfter(Node<T>* node_);
	bool elementExists(T data_);
	Node<T>* find(T data_);
	int indexOf(T data_);
	T retrieveFront();
	T retrieveEnd();
	T retrieve(int index_);
	void printList();
	void empty();
	int length();
};

// default SinglyLinkedList constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
	this->head = nullptr;
}

// SinglyLinkedList constructor that takes a Node as a parameter and makes it the head of the list
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(Node<T>* head_) {
	this->head = head_;
}

// returns the length of the linked list
template <typename T>
int SinglyLinkedList<T>::length() {

	int size = 0;
	Node<T>* current = head;
	while (current != nullptr) { // iterates through every node in list and increases the value of size each iteration
		size++;
		current = current->getNext();
	}

	return size;
}

// prints out the linked list in a readable format
template <typename T>
void SinglyLinkedList<T>::printList() {

	Node<T>* current = head;

	if (head == nullptr) { // checks if there are no Nodes in the list
		std::cout << "empty" << std::endl;
	}

	while (current != nullptr) { // prints out the data contained within each node in the linked list in a clean format
		std::cout << "[" << current->getData() << "]";
		if (current->getNext() != nullptr) {
			std::cout << "==";
		}
		current = current->getNext();
	}
	std::cout << std::endl;
}

// deletes all Nodes in the linked list
template <typename T>
void SinglyLinkedList<T>::empty() {

	if (head == nullptr) { // checks if the list is empty
		head = nullptr;
	}
	else {
		Node<T>* current = head;
		Node<T>* next;

		while (current != nullptr) { // iterates through each node in the linked list and deletes a node each iteration
			next = current->getNext();
			delete current;
			current = next;
		}

		head = nullptr;
	}
}

// returns the first instance of a specified Node in the linked list
template <typename T>
Node<T>* SinglyLinkedList<T>::find(T data_) {

	Node<T>* currentNode = head;
	Node<T>* node = nullptr;

	while (currentNode != nullptr) { // iterates through each node in the linked list until the desired node is found
		if (currentNode->getData() == data_) {
			node = currentNode;
			break;
		}
		currentNode = currentNode->getNext();
	}

	return node;

}

// adds a Node to the front of the linked list
template <typename T>
void SinglyLinkedList<T>::addToFront(T data_) {

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}
	else {
		newNode->setNext(head);
		head = newNode;
	}
}

// adds a Node to the end of the linked list
template <typename T>
void SinglyLinkedList<T>::addToEnd(T data_) {
	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}
	else {

		Node<T>* currentNode = head;

		while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the linked list 
			currentNode = currentNode->getNext();
		}

		currentNode->setNext(newNode);
	}
}

// adds a Node at a specified index in the linked list
template <typename T>
void SinglyLinkedList<T>::addAtIndex(T data_, int index_) {

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (index_ < 0 || index_ > length()) {
		addToEnd(data_);
	}

	if (index_ == 0) { // checks if the provided index is 0 so that the head can be properly assigned
		newNode->setNext(head);
		head = newNode;
	}
	else {

		Node<T>* currentNode = head;

		for (int i = 0; i < index_ - 1; i++) { // iterates through the linked list index_ number of times

			if (currentNode == nullptr || currentNode->getNext() == nullptr) {
				return;
			}
			currentNode = currentNode->getNext();
		}

		newNode->setNext(currentNode->getNext());
		currentNode->setNext(newNode);
	}
}

// adds a Node before a specified Node already in the list
template <typename T>
void SinglyLinkedList<T>::addBefore(Node<T>* node_, T data_) {

	if (node_ == nullptr) {
		return;
	}

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (newNode == nullptr) { // checks if the node we are trying to add is a nullptr
		return;
	}

	if (node_ == head) { // checks if the specified node is the head of the list so that a special case can be applied for adding the node to the list 
		newNode->setNext(head);
		head = newNode;
	}
	else {
		Node<T>* currentNode = head;

		while (currentNode->getNext() != node_) { // sets currentNode to the node before the specified node
			currentNode = currentNode->getNext();
		}
		currentNode->setNext(newNode);
		newNode->setNext(node_);

	}
}

// adds a Node after a specified Node already in the list 
template <typename T>
void SinglyLinkedList<T>::addAfter(Node<T>* node_, T data_) {

	if (node_ == nullptr) {
		return;
	}

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (newNode == nullptr) { // checks if the node we are trying to ass is a nullptr
		return;
	}

	if (node_->getNext() == nullptr) { // checks if the specified node is the last node in the list so that a special case can be applied for adding the node to the list
		node_->setNext(newNode);
	}
	else {
		Node<T>* neighbor = node_->getNext();

		node_->setNext(newNode);
		newNode->setNext(neighbor);
	}
}

// removes the head of the list and returns its contents
template <typename T>
T SinglyLinkedList<T>::removeFromFront() {

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	T contents = head->getData();

	Node<T>* node = head;
	head = head->getNext();

	if (head == nullptr) {
		head = nullptr;
	}
	delete node;

	return contents;
}

// remove the end of the list and return its contents
template <typename T>
T SinglyLinkedList<T>::removeFromEnd() {


	T contents;

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	if (head->getNext() == nullptr) { // case that there is only one node in the list
		contents = head->getData();
		delete head;
		head = nullptr;
	}
	else {

		Node<T>* previous = nullptr;
		Node<T>* currentNode = head;

		while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the list
			previous = currentNode;
			currentNode = currentNode->getNext();
		}

		contents = currentNode->getData();

		if (head == nullptr) {
			head = nullptr;
		}

		previous->setNext(nullptr);
		delete currentNode;
	}

	return contents;

}

// removes a node at a specified index in the list and returns its contents
template <typename T>
T SinglyLinkedList<T>::removeAtIndex(int index_) {

	T contents;
	Node<T>* previous = nullptr;
	Node<T>* currentNode = head;

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	if (index_ < 0 || index_ > length() - 1) { // checks if the provided index to remove a node at is within the bounds of the list
		return T();
	}
	else if (index_ == 0) { // case for removing the first node
		Node<T>* node = head;
		contents = head->getData();
		head = head->getNext();
		delete node;
	}
	else {

		for (int i = 0; i < index_; i++) { // sets currentNode to the node at the specified index and keeps track of the previous node in the list
			previous = currentNode;
			currentNode = currentNode->getNext();
		}

		contents = currentNode->getData();

		if (currentNode != nullptr) {
			if (currentNode->getNext() == nullptr) {
				previous->setNext(nullptr);
			}
			else {
				previous->setNext(currentNode->getNext());
			}
			delete currentNode;
		}
	}

	return contents;
}

// removes the first instance of a node containing specified data and returns its contents
template <typename T>
T SinglyLinkedList<T>::removeFirstInstanceOf(T data_) {
	T contents = T();

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	// Check the first node separately
	if (currentNode->getData() == data_) {
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		head = currentNode->getNext();
		delete node;
		return contents;
	}

	// Traverse the remaining nodes until the second-to-last node
	while (currentNode->getNext() != nullptr && currentNode->getNext()->getNext() != nullptr) {
		previous = currentNode;
		currentNode = currentNode->getNext();

		if (currentNode->getData() == data_) {
			contents = currentNode->getData();
			previous->setNext(currentNode->getNext());
			delete currentNode;
			return contents;
		}
	}

	// Check the last node separately
	if (currentNode->getNext() == nullptr && currentNode->getData() == data_) {
		contents = currentNode->getData();
		previous->setNext(nullptr);
		delete currentNode;
	}

	return contents;
}

// removes all instances of nodes containing specified data and returns the number of nodes removed
template <typename T>
int SinglyLinkedList<T>::removeAllInstancesOf(T data_) {

	int nodesRemoved = 0;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	while (currentNode != nullptr) {

		if (currentNode->getData() == data_) { // checks if the node contains the specified data
			Node<T>* node = currentNode;
			if (previous != nullptr) { // checks for if the node is the head of the list
				previous->setNext(currentNode->getNext());
			}
			else {
				head = currentNode->getNext();
			}
			currentNode = currentNode->getNext();
			delete node;
			nodesRemoved++;
		}
		else {
			previous = currentNode;
			currentNode = currentNode->getNext();
		}
	}

	return nodesRemoved;
}

// removes the node before another specified node in the list
template <typename T>
T SinglyLinkedList<T>::removeBefore(Node<T>* node_) {

	T contents;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	if (node_ == nullptr) { // checks if the specified node exists
		return T();
	}

	if (node_ == head) { // checks if the specified node is the head of the list
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	while (currentNode->getNext() != node_) { // iterates through the list and sets the currentNode to the node before the specified node in the list
		previous = currentNode;
		currentNode = currentNode->getNext();
	}

	if (currentNode == head) { // if that node is the head of the list, handle the case where it is
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		head = currentNode->getNext();
		delete node;
		return contents;
	}
	else { // otherwise remove the node with this code
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		previous->setNext(currentNode->getNext());
		delete node;
		return contents;
	}
}
// removes the node after a specified node in the list
template <typename T>
T SinglyLinkedList<T>::removeAfter(Node<T>* node_) {

	T contents;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	if (node_ == nullptr) { // chekcs if the specified node exists
		return T();
	}

	if (node_->getNext() == nullptr) { // checks if the node is the last node in the list
		return T();
	}
	if (node_->getNext()->getNext() == nullptr) { // checks and handles the case where the specified node would become the last node in the list 
		Node<T>* node = node_->getNext();
		contents = node->getData();
		node_->setNext(nullptr);
		delete node;
		return contents;
	}
	else { // handles everything else

		Node<T>* node = node_->getNext();
		contents = node->getData();
		node_->setNext(node_->getNext()->getNext());
		delete node;
		return contents;
	}
}

// checks if a node in the list contains a specific element
template <typename T>
bool SinglyLinkedList<T>::elementExists(T data_) {

	bool exists = false;
	Node<T>* currentNode = head;

	while (currentNode != nullptr) { // checks each node in the list for the specified data
		if (currentNode->getData() == data_) {
			exists = true;
			return exists;
		}
		else {
			exists = false;
			currentNode = currentNode->getNext();
		}
	}

	return exists;

}

// returns the index of a specified piece of data
template <typename T>
int SinglyLinkedList<T>::indexOf(T data_) {

	int index = 0;
	Node<T>* currentNode = head;

	while (currentNode != nullptr) { // checks each node in the list for the specified data
		if (currentNode->getData() == data_) {
			return index;
		}
		else {
			index++;
			currentNode = currentNode->getNext();
		}
	}

	return index;

}

// returns the contents of the head node in the list
template <typename T>
T SinglyLinkedList<T>::retrieveFront() {

	if (head == nullptr) { // checks if the list is empty
		return T();
	}
	else {
		return head->getData();
	}
}

// returns the contents of the last node in the list
template <typename T>
T SinglyLinkedList<T>::retrieveEnd() {

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;

	while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the list
		currentNode = currentNode->getNext();
	}

	return currentNode->getData();

}

// returns the contents of a node at a specified index
template <typename T>
T SinglyLinkedList<T>::retrieve(int index_) {

	if (head == nullptr || index_ < 0) {
		return T(); // return a default value for invalid index or empty list
	}

	Node<T>* currentNode = head;
	int currentIndex = 0;

	while (currentNode != nullptr) {
		if (currentIndex == index_) {
			return currentNode->getData(); // return data at the specified index
		}
		currentNode = currentNode->getNext();
		currentIndex++;
	}

	return T(); // return a default value if the index is out of bounds
}

// templated Doubly Linked List class
template <typename T>
class DoublyLinkedList {

private:
	Node<T>* head;
public:
	DoublyLinkedList();
	DoublyLinkedList(Node<T>* head_);
	void addToFront(T data_);
	void addToEnd(T data_);
	void addAtIndex(T data_, int index_);
	void addBefore(Node<T>* node_, T data_);
	void addAfter(Node<T>* node_, T data_);
	T removeFromFront();
	T removeFromEnd();
	T removeAtIndex(int index_);
	T removeFirstInstanceOf(T data_);
	int removeAllInstancesOf(T data_);
	T removeBefore(Node<T>* node_);
	T removeAfter(Node<T>* node_);
	bool elementExists(T data_);
	Node<T>* find(T data_);
	int indexOf(T data_);
	T retrieveFront();
	T retrieveEnd();
	T retrieve(int index_);
	void printList();
	void empty();
	int length();
};

// default DoublyLinkedList constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	this->head = nullptr;
}

// DoublyLinkedList constructor that takes a Node as a parameter and makes it the head of the list
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(Node<T>* head_) {
	this->head = head_;
}

// returns the length of the linked list
template <typename T>
int DoublyLinkedList<T>::length() {

	int size = 0;
	Node<T>* current = head;
	while (current != nullptr) { // iterates through every node in list and increases the value of size each iteration
		size++;
		current = current->getNext();
	}

	return size;
}

// prints out the linked list in a readable format
template <typename T>
void DoublyLinkedList<T>::printList() {

	Node<T>* current = head;

	if (head == nullptr) { // checks if there are no Nodes in the list
		std::cout << "empty" << std::endl;
	}

	while (current != nullptr) { // prints out the data contained within each node in the linked list in a clean format
		std::cout << "[" << current->getData() << "]";
		if (current->getNext() != nullptr) {
			std::cout << "==";
		}
		current = current->getNext();
	}
	std::cout << std::endl;
}

// deletes all Nodes in the linked list
template <typename T>
void DoublyLinkedList<T>::empty() {

	if (head == nullptr) { // checks if the list is empty
		head = nullptr;
	}
	else {
		Node<T>* current = head;
		Node<T>* next;

		while (current != nullptr) { // iterates through each node in the linked list and deletes a node each iteration
			next = current->getNext();
			delete current;
			current = next;
		}

		head = nullptr;
	}
}

// returns the first instance of a specified Node in the linked list
template <typename T>
Node<T>* DoublyLinkedList<T>::find(T data_) {

	Node<T>* currentNode = head;
	Node<T>* node = nullptr;

	while (currentNode != nullptr) { // iterates through each node in the linked list until the desired node is found
		if (currentNode->getData() == data_) {
			node = currentNode;
			break;
		}
		currentNode = currentNode->getNext();
	}

	return node;

}

// adds a Node to the front of the linked list
template <typename T>
void DoublyLinkedList<T>::addToFront(T data_) {

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}
	else {
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = newNode;
	}
}

// adds a Node to the end of the linked list
template <typename T>
void DoublyLinkedList<T>::addToEnd(T data_) {
	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}
	else {

		Node<T>* currentNode = head;

		while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the linked list 
			currentNode = currentNode->getNext();
		}

		currentNode->setNext(newNode);
		newNode->setPrevious(currentNode);
	}
}

// adds a Node at a specified index in the linked list
template <typename T>
void DoublyLinkedList<T>::addAtIndex(T data_, int index_) {

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (index_ < 0 || index_ > length()) {
		addToEnd(data_);
	}

	if (index_ == 0) { // checks if the provided index is 0 so that the head can be properly assigned
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = newNode;
	}
	else {

		Node<T>* currentNode = head;

		for (int i = 0; i < index_ - 1; i++) { // iterates through the linked list index_ number of times

			if (currentNode == nullptr || currentNode->getNext() == nullptr) {
				return;
			}
			currentNode = currentNode->getNext();
		}

		newNode->setNext(currentNode->getNext());
		if (currentNode->getNext() != nullptr) {
			currentNode->getNext()->setPrevious(newNode);
		}
		currentNode->setNext(newNode);
		if (currentNode->getNext() != nullptr) {
			newNode->setPrevious(currentNode);
		}
		
	}
}

// adds a Node before a specified Node already in the list
template <typename T>
void DoublyLinkedList<T>::addBefore(Node<T>* node_, T data_) {

	if (node_ == nullptr) {
		return;
	}

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (newNode == nullptr) { // checks if the node we are trying to add is a nullptr
		return;
	}

	if (node_ == head) { // checks if the specified node is the head of the list so that a special case can be applied for adding the node to the list 
		newNode->setNext(head);
		head->setPrevious(newNode);
		head = newNode;
	}
	else {
		Node<T>* currentNode = head;

		while (currentNode->getNext() != node_) { // sets currentNode to the node before the specified node
			currentNode = currentNode->getNext();
		}
		currentNode->setNext(newNode);
		newNode->setPrevious(currentNode);
		newNode->setNext(node_);
		node_->setPrevious(newNode);

	}
}

// adds a Node after a specified Node already in the list 
template <typename T>
void DoublyLinkedList<T>::addAfter(Node<T>* node_, T data_) {

	if (node_ == nullptr) {
		return;
	}

	Node<T>* newNode = new Node<T>(data_);

	if (head == nullptr) { // checks if the list is empty
		head = newNode;
	}

	if (newNode == nullptr) { // checks if the node we are trying to add is a nullptr
		return;
	}

	if (node_->getNext() == nullptr) { // checks if the specified node is the last node in the list so that a special case can be applied for adding the node to the list
		node_->setNext(newNode);
		newNode->setPrevious(node_);
	}
	else {
		Node<T>* neighbor = node_->getNext();

		node_->setNext(newNode);
		newNode->setPrevious(node_);
		newNode->setNext(neighbor);
		neighbor->setPrevious(newNode);
	}
}

// removes the head of the list and returns its contents
template <typename T>
T DoublyLinkedList<T>::removeFromFront() {

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	T contents = head->getData();
	Node<T>* node = head;

	if (head->getNext() == nullptr) {
		head = head->getNext();
	}
	else {
		head = head->getNext();
		head->setPrevious(nullptr);
	}

	if (head == nullptr) {
		head = nullptr;
	}
	delete node;

	return contents;
}

// remove the end of the list and return its contents
template <typename T>
T DoublyLinkedList<T>::removeFromEnd() {


	T contents;

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	if (head->getNext() == nullptr) { // case that there is only one node in the list
		contents = head->getData();
		delete head;
		head = nullptr;
	}
	else {

		Node<T>* previous = nullptr;
		Node<T>* currentNode = head;

		while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the list
			previous = currentNode;
			currentNode = currentNode->getNext();
		}

		contents = currentNode->getData();

		if (head == nullptr) {
			head = nullptr;
		}

		previous->setNext(nullptr);
		delete currentNode;
	}

	return contents;

}

// removes a node at a specified index in the list and returns its contents
template <typename T>
T DoublyLinkedList<T>::removeAtIndex(int index_) {

	T contents;
	Node<T>* previous = nullptr;
	Node<T>* currentNode = head;

	if (head == nullptr) { // checks if list is empty
		return T();
	}

	if (index_ < 0 || index_ > length() - 1) { // checks if the provided index to remove a node at is within the bounds of the list
		return T();
	}
	else if (index_ == 0) { // case for removing the first node
		Node<T>* node = head;
		contents = head->getData();
		head = head->getNext();
		if (head != nullptr) {
			head->setPrevious(nullptr);
		}
		
		delete node;
	}
	else {

		for (int i = 0; i < index_; i++) { // sets currentNode to the node at the specified index and keeps track of the previous node in the list
			previous = currentNode;
			currentNode = currentNode->getNext();
		}

		contents = currentNode->getData();

		if (currentNode != nullptr) {
			if (currentNode->getNext() == nullptr) {
				previous->setNext(nullptr);
			}
			else {
				previous->setNext(currentNode->getNext());
				currentNode->getNext()->setPrevious(previous);
			}
			delete currentNode;
		}
	}

	return contents;
}

// removes the first instance of a node containing specified data and returns its contents
template <typename T>
T DoublyLinkedList<T>::removeFirstInstanceOf(T data_) {
	T contents = T();

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	// Check the first node separately
	if (currentNode->getData() == data_) {
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		head = currentNode->getNext();
		if (head != nullptr) {
			head->setPrevious(nullptr);
		}
		
		delete node;
		return contents;
	}

	// Traverse the remaining nodes until the second-to-last node
	while (currentNode->getNext() != nullptr && currentNode->getNext()->getNext() != nullptr) {
		previous = currentNode;
		currentNode = currentNode->getNext();

		if (currentNode->getData() == data_) {
			contents = currentNode->getData();
			previous->setNext(currentNode->getNext());
			currentNode->getNext()->setPrevious(previous);
			delete currentNode;
			return contents;
		}
	}

	// Check the last node separately
	if (currentNode->getNext() == nullptr && currentNode->getData() == data_) {
		contents = currentNode->getData();
		previous->setNext(nullptr);
		delete currentNode;
	}

	return contents;
}

// removes all instances of nodes containing specified data and returns the number of nodes removed
template <typename T>
int DoublyLinkedList<T>::removeAllInstancesOf(T data_) {

	int nodesRemoved = 0;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	while (currentNode != nullptr) {

		if (currentNode->getData() == data_) { // checks if the node contains the specified data
			Node<T>* node = currentNode;
			if (previous != nullptr) { // checks for if the node is the head of the list
				previous->setNext(currentNode->getNext());
				if (currentNode->getNext() != nullptr) {
					currentNode->getNext()->setPrevious(previous);
				}
				
			}
			else {
				head = currentNode->getNext();
				if (head != nullptr) {
					head->setPrevious(nullptr);
				}
				
			}
			currentNode = currentNode->getNext();
			delete node;
			nodesRemoved++;
		}
		else {
			previous = currentNode;
			currentNode = currentNode->getNext();
		}
	}

	return nodesRemoved;
}

// removes the node before another specified node in the list
template <typename T>
T DoublyLinkedList<T>::removeBefore(Node<T>* node_) {

	T contents;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	if (node_ == nullptr) { // checks if the specified node exists
		return T();
	}

	if (node_ == head) { // checks if the specified node is the head of the list
		return T();
	}

	Node<T>* currentNode = head;
	Node<T>* previous = nullptr;

	while (currentNode->getNext() != node_) { // iterates through the list and sets the currentNode to the node before the specified node in the list
		previous = currentNode;
		currentNode = currentNode->getNext();
	}

	if (currentNode == head) { // if that node is the head of the list, handle the case where it is
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		head = currentNode->getNext();
		if (head != nullptr) {
			head->setPrevious(nullptr);
		}
		delete node;
		return contents;
	}
	else { // otherwise remove the node with this code
		contents = currentNode->getData();
		Node<T>* node = currentNode;
		previous->setNext(currentNode->getNext());
		if (currentNode->getNext() != nullptr) {
			currentNode->getNext()->setPrevious(previous);
		}
		delete node;
		return contents;
	}
}
// removes the node after a specified node in the list
template <typename T>
T DoublyLinkedList<T>::removeAfter(Node<T>* node_) {

	T contents;

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	if (node_ == nullptr) { // chekcs if the specified node exists
		return T();
	}

	if (node_->getNext() == nullptr) { // checks if the node is the last node in the list
		return T();
	}
	if (node_->getNext()->getNext() == nullptr) { // checks and handles the case where the specified node would become the last node in the list 
		Node<T>* node = node_->getNext();
		contents = node->getData();
		node_->setNext(nullptr);
		delete node;
		return contents;
	}
	else { // handles everything else

		Node<T>* node = node_->getNext();
		contents = node->getData();
		node_->setNext(node_->getNext()->getNext());
		if (node_->getNext()->getNext() != nullptr) {
			node_->getNext()->getNext()->setPrevious(node_);
		}
		delete node;
		return contents;
	}
}

// checks if a node in the list contains a specific element
template <typename T>
bool DoublyLinkedList<T>::elementExists(T data_) {

	bool exists = false;
	Node<T>* currentNode = head;

	while (currentNode != nullptr) { // checks each node in the list for the specified data
		if (currentNode->getData() == data_) {
			exists = true;
			return exists;
		}
		else {
			exists = false;
			currentNode = currentNode->getNext();
		}
	}

	return exists;

}

// returns the index of a specified piece of data
template <typename T>
int DoublyLinkedList<T>::indexOf(T data_) {

	int index = 0;
	Node<T>* currentNode = head;

	while (currentNode != nullptr) { // checks each node in the list for the specified data
		if (currentNode->getData() == data_) {
			return index;
		}
		else {
			index++;
			currentNode = currentNode->getNext();
		}
	}

	return index;

}

// returns the contents of the head node in the list
template <typename T>
T DoublyLinkedList<T>::retrieveFront() {

	if (head == nullptr) { // checks if the list is empty
		return T();
	}
	else {
		return head->getData();
	}
}

// returns the contents of the last node in the list
template <typename T>
T DoublyLinkedList<T>::retrieveEnd() {

	if (head == nullptr) { // checks if the list is empty
		return T();
	}

	Node<T>* currentNode = head;

	while (currentNode->getNext() != nullptr) { // sets currentNode to the last node in the list
		currentNode = currentNode->getNext();
	}

	return currentNode->getData();

}

// returns the contents of a node at a specified index
template <typename T>
T DoublyLinkedList<T>::retrieve(int index_) {

	if (head == nullptr || index_ < 0) {
		return T(); // return a default value for invalid index or empty list
	}

	Node<T>* currentNode = head;
	int currentIndex = 0;

	while (currentNode != nullptr) {
		if (currentIndex == index_) {
			return currentNode->getData(); // return data at the specified index
		}
		currentNode = currentNode->getNext();
		currentIndex++;
	}

	return T(); // return a default value if the index is out of bounds
}