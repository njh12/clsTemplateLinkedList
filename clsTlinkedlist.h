#pragma once
#include "clslstnodes.h"
#include <iostream>

template<class T>
class clslinkedlst 
{

private:
	int int_lstsize;
	clslstnodes<T> * newNode(T inval);
	clslstnodes<T> * ptr_headnode;
	clslstnodes<T> *ptr_tailnode;
	void setTail();
	

public:
	clslinkedlst();
	~clslinkedlst();
	void insertEnd(T inval);
	void insValByPos(T inval);
	void lstprint();
	void delval(T inval);
	
};

//Consructor
template<class T>
clslinkedlst<T>::clslinkedlst()
{
	this->ptr_headnode = NULL;
	this->ptr_tailnode = NULL;
	this->int_lstsize = 0;
};

//Destructor
template<class T>
clslinkedlst<T>::~clslinkedlst()
{
	clslstnodes<T> *ptr_cur = this->ptr_headnode;
	clslstnodes<T> *ptr_next = ptr_cur;
	while (ptr_cur != NULL) {
		ptr_next = ptr_cur->ptr_nextNode;
		delete ptr_cur;
		ptr_cur = ptr_next;
	};
	this->ptr_headnode = NULL;
	this->ptr_tailnode = NULL;
	int_lstsize = 0;
};

//Creates a new node and sets its data to int_inval.
template<class T>
clslstnodes<T>* clslinkedlst<T>::newNode(T inval)
{
	clslstnodes<T> *ptr_newNode = new clslstnodes<T>;
	ptr_newNode->set_t_val(inval);
	ptr_newNode->ptr_nextNode = NULL;
	return(ptr_newNode);
};

/*Inserts nodes into the end of linked list and increment the size of the list by one.
If the ptr_headnode is NULL insert int_inval into ptr_headnode and set the tailnode equal to ptr_headnode.
else...Create a new node and set ptr_tailnode equal to the new node.*/

template<class T>
void clslinkedlst<T>::insertEnd(T inval)
{
	
	if (this->ptr_headnode == NULL) {
		cout << " List is empty inserting at the head.\n";
		this->ptr_headnode = newNode(inval);
		this->ptr_tailnode = this->ptr_headnode;		
	}
	else {
		this->ptr_tailnode->ptr_nextNode = newNode(inval);
		this->ptr_tailnode = this->ptr_tailnode->ptr_nextNode;
	};

	this->int_lstsize++;
};


/* Deletes items from linked list and decrements the size of list.
If the ptr_current nodes value in the list does NOT equal int_inval
traverse to the next node...else the value was found in the ptr_cur node.
If the lst nodes position with the value is in the front of the list
move the ptr_headnode to the next node...else if he value eqauls the value in the ptr_tailnode
set the ptr_tailnode to NULL and reset the tails location...else the value is in the middle of the list
so shorten the list by removing the ptr_cur node from the list.*/

template<class T>
void clslinkedlst<T>::delval(T inval)
{
	clslstnodes<T> *ptr_cur = this->ptr_headnode;
	clslstnodes<T> *ptr_prev = ptr_cur;
	cout << "Searching for the value to delete: " << inval << "\n";

	while (ptr_cur != NULL) {
		if (ptr_cur->int_val != inval) {
			ptr_prev = ptr_cur;
			ptr_cur = ptr_cur->ptr_nextNode;
		}
		else {
			cout << " Value: " << inval << " found.\n";
			if (ptr_cur == this->ptr_headnode)
				this->ptr_headnode = this->ptr_headnode->ptr_nextNode;
			else if (ptr_cur == this->ptr_tailnode) {
				this->ptr_tailnode = ptr_prev;
				this->ptr_tailnode->ptr_nextNode = NULL;
			}
			else
				ptr_prev->ptr_nextNode = ptr_cur->ptr_nextNode;

			cout << " Value deleted\n";
			this->int_lstsize--;
			delete ptr_cur;
			ptr_cur = NULL;
		};
	};
};

/*	Inserts int_inval into the linked list by position.
If the list is empty insert int_inval at head/tail of list.
While the list is NOT empty traverse to determine where to insert new node.
If the int_inval is less then the ptr_cur-> val and ptr_cur = this->ptr_headnode
the int_inval needs to become the head...else the int_inval needs to be inserted
somewhere in the middle of the list. If the ptr_cur is at the end of the list and greater then the ptr_tailnode
int_inval needs to be inserted at the end of the list.
If the int_inval is greater then ptr_cur val continue traversing the list.*/

template<class T>
void clslinkedlst<T>::insValByPos(T inval)
{
	cout << "Searching for the correct position to insert the value: " << inval << "\n";
	clslstnodes<T> *ptr_cur = this->ptr_headnode;
	clslstnodes<T> *prev = ptr_cur;

	if (ptr_cur == NULL)
		insertEnd(inval);
	while (ptr_cur != NULL) {
		if (inval < ptr_cur->get_t_val()) {

			clslstnodes<T> *ptr_temp = newNode(inval);

			if (ptr_cur == this->ptr_headnode) {
				ptr_temp->ptr_nextNode = ptr_cur;
				this->ptr_headnode = ptr_temp;
			}
			else {
				prev->ptr_nextNode = ptr_temp;
				ptr_temp->ptr_nextNode = ptr_cur;
			};

			ptr_cur = this->ptr_tailnode->ptr_nextNode;
			this->int_lstsize++;

		}
		else if (inval > ptr_cur->get_t_val()) {
			if (ptr_cur == this->ptr_tailnode) {
				insertEnd(inval);
				ptr_cur = this->ptr_tailnode->ptr_nextNode;
			}
			else {
				prev = ptr_cur;
				ptr_cur = ptr_cur->ptr_nextNode;
			}
		}
		else {
			cout << "Value already present.\n";
			ptr_cur = this->ptr_tailnode->ptr_nextNode;

		};
	};
};

template<class T>
void clslinkedlst<T>::setTail()
{
	clslstnodes<T> *ptr_cur;
	ptr_cur = this->ptr_headnode;
	while (ptr_cur->ptr_nextNode != NULL)
		ptr_cur = ptr_cur->ptr_nextNode;
	this->ptr_tailnode = ptr_cur;
};

//Prints all items in linked list.
template<class T>
void clslinkedlst<T>::lstprint()
{
	clslstnodes<T> *ptr_cur;
	ptr_cur = this->ptr_headnode;
	cout << "Printing the values within the linked list.\n";
	while (ptr_cur != NULL) {
		cout << "Value in the Node is:" << ptr_cur->get_t_val() << '\n';
		ptr_cur = ptr_cur->ptr_nextNode;
	};
	cout << "\n The head value is:" << this->ptr_headnode->get_t_val()
		<< "\n The tail value is:" << this->ptr_tailnode->get_t_val()
		<< "\n The list holds " << this->int_lstsize << " elements.\n";

	delete ptr_cur;
	ptr_cur = NULL;
};



