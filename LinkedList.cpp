#include<iostream>
#include"LinkedList.h"

using namespace std;

int main()
{
	LList<char> H;    //Initial the LinkedList

	char e[] = { 'a','b','c','d','e' };

	//Append "a" "b" "c" "d" "e" and print the LinkedList
	for (int i = 0; i < 5; i++)
	{
		H.append(e[i]);
	}
	H.getLinkedList();

	//Get the length of the LinkedList
	cout << "The length is " << H.length() << endl;

	//Know whether the LinkedList is empty
	if (H.isEmpty())
		cout << "The LinkedList is empty" << endl;
	else
		cout << "The LinkedList is not empty" << endl;

	//Get the third element
	cout << "The third element is " << H.getElement(2) << endl;

	//Return the position of "a"
	H.findPos(e[0]);
	cout << endl;

	//Insert "f" at the position of the fourth element
	H.moveToPos(3);
	H.insert('f');

	//Print the LinkedList
	H.getLinkedList();

	//Remove the third element and print the LinkedList
	H.moveToPos(2);
	H.remove();
	H.getLinkedList();

	system("pause");
	return 0;
}
