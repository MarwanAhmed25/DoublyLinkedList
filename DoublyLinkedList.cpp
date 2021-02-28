//doubly LinkedList with next and previos and head, tail ;
#include <iostream>
#include<cmath>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
//class of nodes;
class Node
{
public:
	//constractor of class make initial of next and previous Node;
	Node(int data, Node* next = nullptr, Node* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	//setting data of calling Node;
	void setData(int data)
	{
		this->data = data;
	}
	//returning data of calling Node;
	int getData()
	{
		return data;
	}
	//setting next pointer of calling Node;
	void setNext(Node* next)
	{
		this->next = next;
	}
	//returning next pointer of calling Node;
	Node* getNext()
	{
		return next;
	}
	//setting previous pointer of calling Node;
	void setPrev(Node* prev)
	{
		this->prev = prev;
	}
	//returning previous pointer of calling Node;
	Node* getPrev()
	{
		return prev;
	}
private:
	int data;
	Node* next;
	Node* prev;
};
//class of linkedlist whitch consist of list of nodes;
class LinkedList
{
public:
	//constractor of class whitch initialize first node of list;
	LinkedList(int data)
	{
		if (head == NULL)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			while (head)
			{
				tail = new Node(data);
				head->setNext(tail);
				tail->setPrev(head);
			}
		}
	}
	//destractor of the class whitch call the ClearAll() memeber function and delete all node in list;
	~LinkedList()
	{
		ClearAll();
	}
	//member function for deleting all nodes in the list;
	void ClearAll()
	{
		while (head != NULL)
		{
			node = head;

			head = head->getNext();

			delete node;

		}
		delete tail;

	}

	//member function for inserting a node at the end of list;
	void Append(int data)
	{
		node = new Node(data);
		node->setPrev(tail);
		tail->setNext(node);
		tail = node;
	}
	//member function for show Nodes data from the front by using next pointer;
	void DisplayFromFront()
	{
		node = head;
		while (node)
		{
			cout << node->getData() << "   ";
			node = node->getNext();
		}
		cout << endl;
	}
	//member function for show Nodes data from the back by using prev pointer;
	void DisplayFromBack()
	{
		node = tail;
		while (node != NULL)
		{
			cout << node->getData() << "   ";
			node = node->getPrev();
		}
		cout << endl;
	}
	//member function for inserting a Node to the list with value and position;
	void insertAt(int data, int index)
	{
		int numbersOfList = Counter();
		Node* temp;
		index -= 1;
		if (index > numbersOfList)
			cout << "\nout of range index\n";
		else if (index == numbersOfList)
			Append(data);
		else if (index == 0)
		{
			node = new Node(data);
			node->setNext(head);
			head->setPrev(node);
			head = node;
		}
		else
		{
			node = new Node(data);
			temp = head;
			while ((index - 1) > 0)
			{
				temp = temp->getNext();
				index--;
			}
			node->setPrev(temp);
			temp->getNext()->setPrev(node);
			node->setNext(temp->getNext());
			temp->setNext(node);
		}
	}
	//member function for returning numbers of nodes in list;
	int Counter()
	{
		count = 0;
		node = head;
		while (node)
		{
			count++;
			node = node->getNext();
		}
		return count;
	}
private:
	Node* head;
	Node* tail;
	Node* node;
	int count;
};
int main()
{
	LinkedList* list = new LinkedList(1);
	list->Append(2);
	list->Append(3);
	list->Append(4);
	list->Append(5);
	list->DisplayFromBack();

}