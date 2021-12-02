#include<iostream>
using namespace std;

class Node{
	private:
		int object;
		Node *nextNode;
	public:
		int get()
		{
			return object;
		}
		
		void set(int object)
		{
			this->object=object;
		}
		
		Node *getNext()
		{
			return nextNode;
		}
		
		void setNext(Node *nextNode)
		{
			this->nextNode=nextNode;
		}
};


class List{
	private:
		int size;
		Node *headNode;
		Node *currentNode, *lastCurrentNode;
	public:
		List()
		{
			currentNode=NULL;
			size = 0;
		}
		
		void add(int addObject)
		{
			Node *newNode = new Node();
			newNode->set(addObject);
			if(currentNode!=NULL)
			{
				newNode->setNext(currentNode->getNext());
				currentNode->setNext(newNode);
				lastCurrentNode = currentNode;
				currentNode=newNode;
			}
			
			else
			{
				newNode->setNext(NULL);
				headNode=newNode;
				lastCurrentNode=NULL;
				currentNode=newNode;
			}
			size++;
		}
			
		int get()
		{
			if(currentNode!=NULL)
			{
				return currentNode->get();
			}
		}
			
		bool next()
		{
			if(currentNode==NULL)
			{
				return false;
			}
			lastCurrentNode=currentNode;
			currentNode=currentNode->getNext();
			
			if(currentNode==NULL||size==0)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
			
		void start()
		{
			lastCurrentNode=headNode;
			currentNode=headNode;
		}
			
		void remove()
		{
			if(currentNode!=NULL)
			{
				lastCurrentNode->setNext(currentNode->getNext());
				delete currentNode;
				currentNode=lastCurrentNode->getNext();
				size--;
			}
		}
			
		int length()
		{
			return size;
		}
				
		void print()
		{
			start();
			cout<<"List Element : "<<currentNode->get()<<endl;
			while(next())
			{
				cout<<"List element : "<<currentNode->get()<<endl;
			}
		}
		void bubbleSort()
		{
			start();
			int swapped=1;
			int temp;
			while(swapped>0)
			{
				swapped=0;
				while(currentNode->getNext()!=NULL)
				{
					if(currentNode->get()>currentNode->getNext()->get())
					{
						temp=currentNode->get();
						currentNode->set(currentNode->getNext()->get());
						currentNode->getNext()->set(temp);
						swapped=1;
					}
					currentNode=currentNode->getNext();
				}
			}
		}
		void insertionSort()
		{
			start();
			int val; 
			while(currentNode->getNext()!=NULL)
			{
				Node *temp=headNode;
				val=currentNode->get();
				while(temp->getNext()!=currentNode)
				{
					next();
				}
				if(temp->get()>val)
				{
					temp->getNext()->set(temp->get());
				}
				else
				{
					break;
				}
				temp->getNext()->set(val);
			}
		}
};

int main()
{
	int menuChoice;
	int contChoice;
	List l;
	do
	{
		cout<<"1.	Add Node"<<endl;
		cout<<"2.	Delete Node"<<endl;
		cout<<"3.	Print Node"<<endl;
		cout<<"4.	Bubble Sort"<<endl;
		cout<<"5.	Insertion Sort"<<endl;
		cout<<"Enter your choice. ";
		cin>>menuChoice;
		if(menuChoice==1)
		{
			int n;
			cout<<"Enter the number you want to add. ";
			cin>>n;
			l.add(n);
		}	
		else if(menuChoice==2)
		{
			l.remove();
		}
		else if(menuChoice==3)
		{
			l.print();
		}
		else if(menuChoice==4)
		{
			l.bubbleSort();
			cout<<"Your list has been sorted."<<endl;
			l.print();
		}
		else if(menuChoice==5)
		{
			l.insertionSort();
			cout<<"The list has been sorted."<<endl;
			l.print();
		}
		cout<<"Press 1 to return to the menu or press any other number to exit. ";
		cin>>contChoice;
		
		
	}while(contChoice==1);
}


