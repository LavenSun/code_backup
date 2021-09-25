#include "ListOnMyOwn.h"
#include <cstddef>
#include<iostream>
using namespace std;
ListOnMyOwn::ListOnMyOwn()
{
	head = new Node;
	head->next = NULL;
}
ListOnMyOwn::~ListOnMyOwn()
{
	Node* t = head;
	while (head)
	{
		head = head->next;
		delete t;
		t = head;
	}
}
void ListOnMyOwn::insertList(int d)
{
	Node* cur = new Node;
	cur->data = d;
	cur->next = head->next;
	head->next = cur;
}
void ListOnMyOwn::traverseList()
{
	Node* ph = head->next;
	while (ph)
	{
		cout << ph->data << endl;
		ph = ph->next;
	}
}