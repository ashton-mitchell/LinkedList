#include <iostream>
#include "LinkedList.hpp"

int main()
{
    srand(time(0));
    /*SinglyLinkedList<int>* integerList = new SinglyLinkedList<int>;

    integerList->empty();
    
    for (int i = 0; i < 10; i++) {
        integerList->addToFront(i);
        integerList->printList();
    }

    for (int i = 0; i < 5; i++) {
        integerList->addToEnd(5);
        integerList->printList();
    }

    for (int i = 0; i < 1000; i++) {
        
        integerList->removeAfter(integerList->find(rand() % 10));
        integerList->removeBefore(integerList->find(rand() % 10));
        integerList->removeAllInstancesOf(rand() % 10);
        integerList->removeFirstInstanceOf(rand() % 10);
        integerList->addToEnd(rand() % 10);
        integerList->addAfter(integerList->find(5), rand() % 10);
        integerList->addBefore(integerList->find(7), rand() % 10);
        integerList->addAtIndex(rand() % 10, rand() % (10));
        integerList->addToFront(rand() % 10);
        integerList->removeFromEnd();
        integerList->removeFromFront();
        integerList->removeAtIndex(rand() % (10));
        integerList->elementExists(rand() % 10);
        integerList->indexOf(rand() % 10);
        integerList->retrieveFront();
        integerList->retrieveEnd();
        integerList->retrieve(rand() % 10);
        integerList->length();
        integerList->printList();
    }
    integerList->empty();
    integerList->printList();
    delete integerList;*/

    DoublyLinkedList<int>* integerList = new DoublyLinkedList<int>;

    integerList->empty();

    for (int i = 0; i < 10; i++) {
        integerList->addToFront(i);
        integerList->printList();
    }

    for (int i = 0; i < 5; i++) {
        integerList->addToEnd(5);
        integerList->printList();
    }

    for (int i = 0; i < 10000; i++) {
        integerList->addToFront(rand() % 10);
        integerList->addToEnd(rand() % 10);
        integerList->addAtIndex(rand() % 10, rand() % (10));
        integerList->addAfter(integerList->find(5), rand() % 10);
        integerList->addBefore(integerList->find(7), rand() % 10);
        integerList->removeFromFront();
        integerList->removeFromEnd();
        integerList->removeAtIndex(rand() % (10));
        integerList->removeFirstInstanceOf(rand() % 10);
        integerList->removeAllInstancesOf(rand() % 10);
        integerList->removeAfter(integerList->find(rand() % 10));
        integerList->removeBefore(integerList->find(rand() % 10));
        integerList->elementExists(rand() % 10);
        integerList->indexOf(rand() % 10);
        integerList->retrieveFront();
        integerList->retrieveEnd();
        integerList->retrieve(rand() % 10);
        integerList->length();
        integerList->printList();
    }

    integerList->empty();
    integerList->printList();

    delete integerList;
    return 0;
}


