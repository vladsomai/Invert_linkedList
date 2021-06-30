#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Node
{
private:
	T data;
	shared_ptr<Node<T>> next;
public:
	Node() { this->data = {}; this->next = nullptr; }
	~Node() = default;

	void setData(T dataParam) { this->data = dataParam; }
	T getData() { return this->data; }

	shared_ptr<Node<T>> getNext() { return this->next; }
	void setNext(shared_ptr<Node<T>> nextParam) { this->next = nextParam; }
};


template<typename T>
void printList(const shared_ptr<Node<T>>& head)
{
	shared_ptr<Node<T>> actual = head;
	while (actual != nullptr)
	{
		cout << actual->getData()<<'\t';
		actual = actual->getNext();
	}
	cout << endl;
}

template<typename T>
shared_ptr<Node<T>> createList()
{
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> actual;
	for (int i = 0; i < 5; i++)
	{
		actual = head;

		shared_ptr<Node<T>> newNode = make_shared<Node<T>>();
		newNode->setData(static_cast<T>(i));

		if (i == 0)
		{
			head = newNode;
		}
		else
		{
			while (actual->getNext() != nullptr)
			{
				actual = actual->getNext();
			}
			actual->setNext(newNode);
		}
	}
	return head;
}


template<typename T>
shared_ptr<Node<T>> InvertLinkedList(const shared_ptr<Node<T>>& HEAD)
{
	shared_ptr<Node<T>> old_HEAD = HEAD;
	shared_ptr<Node<T>> new_HEAD = HEAD;
	shared_ptr<Node<T>> temp = nullptr;
	
	while (old_HEAD != nullptr)
	{
		if (old_HEAD == HEAD && new_HEAD == HEAD)
		{

			old_HEAD = old_HEAD->getNext();
		}
		else if(old_HEAD != HEAD && new_HEAD == HEAD )
		{
			temp = old_HEAD;
			old_HEAD = old_HEAD->getNext();

			temp->setNext(new_HEAD);
			new_HEAD->setNext(nullptr);

			new_HEAD = temp;
		}
		else
		{
			temp = old_HEAD;
			old_HEAD = old_HEAD->getNext();

			temp->setNext(new_HEAD);

			new_HEAD = temp;
		}
	}
	return new_HEAD;
}


int main()
{
	   shared_ptr<Node<int>> head = nullptr;
	   printList<int>(head);
	   head = createList<int>();
	   printList(head);
	   
	   head = InvertLinkedList(head);
	   printList(head);
}