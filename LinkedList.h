#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<malloc.h>
#define defaultSize 100

using namespace std;

template <typename E> class Link {
public:
	E element;                  //Value for this node
	Link *next;                 //Pointer to next node in list
	Link(const E& elemval, Link* nextval = NULL)      //Constructor
	{
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL) { next = nextval; }
};

template <typename E> 
class LList
{
private:
	Link<E>* head;          //Pointer to list header
	Link<E>* tail;          //Pointer to last element
	Link<E>* curr;          //Access to current element
	int cnt;                //Size of list

	void init() {             //Intialization helper method
		curr = tail = head = new Link<E>;
		cnt = 0;
	}

	void removeall() {       //Return link nodes to free store
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList(int size = defaultSize) { init(); }  //Constructor
	~LList() { removeall(); }                  //Destructor
	void clear() { removeall(); init(); }      //Clear list

	void insert(const E& it) {      //Insert "it" at current position
		curr->next = new Link<E>(it, curr->next);
		if (tail == curr) tail = curr->next;   //New tail
		cnt++;
	}

	void append(const E& it) {            //Append "it" to list
		tail = tail->next = new Link<E>(it, NULL);
		cnt++;
	}

	void remove() {            //Remove current element
		if (curr->next == NULL)
			cout << "No element" << endl;
		Link<E>* ltemp = curr->next;             //Remember link node
		if (tail == curr->next) tail = curr;     //Reset tail
		curr->next = curr->next->next;           //Remove from list
		delete ltemp;           //Reclaim space
		cnt--;                  //Decrement the count
	}

	int length() const { return cnt; }   //Return length

	int currPos() const {                //Return the position of current link
		Link<E>* temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
		return i;
	}

	void moveToPos(int pos) {           //Move down list to "pos" position
		if (pos<0 || pos>=cnt)
			cout << "Position out of range" << endl;
		curr = head;
		for (int i = 0; i < pos; i++) curr = curr->next;
	}

	const E& getElement(int pos) {         //Get the element in the position
		if (pos<0 || pos>=cnt)
			cout << "Position out of range" << endl;
		else
		{
			moveToPos(pos);
			return curr->next->element;
		}
	}

	void findPos(E& a) {           //Find the position of the element
		curr = head;
		for (int i = 0; i < cnt; i++) {
			if ((curr->next->element) == a)
				cout << "Pos of " << a << " is " << currPos();
			curr = curr->next;
		}
	}

	bool isEmpty() {              //Judge the ArrayList is empty or not
		return(cnt == 0);
	}

	void getLinkedList() {           //Print the LinkedList
		curr = head;
		for (int i = 0; i < cnt; i++)
		{
			if (curr->next->next==NULL)
				cout << curr->next->element << endl;
			else
				cout << curr->next->element << " ";
			curr = curr->next;
		}
	}
};

#endif
