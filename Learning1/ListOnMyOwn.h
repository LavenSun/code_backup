#pragma once
struct Node
{
	int data;
	struct Node* next;
};
class ListOnMyOwn
{
public:
	ListOnMyOwn();//������
	~ListOnMyOwn();
	void insertList(int d);
	void traverseList();
private:
	Node* head; 
};

