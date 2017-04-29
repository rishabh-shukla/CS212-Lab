#include<iostream>
#include<stdio.h>

using namespace std;
int SIZE;

// Stack definition

class Stack{
	int *A;
	int size;
	public:
		Stack(int);
		void push(int);
		void pop(void);
		int peep(void);
		void traversal(void);
};

Stack:: Stack(int N){									// Constructor
	SIZE = N;
	A = new int[N];
	size = 0;
}

void Stack:: push(int element){							// Push function
 	if(size>=SIZE){
		cout<<"\tNo space available\n";
		return;
	}
	A[size] = element;
	size++;
	cout<<"\tSuccess !\n";
}

void Stack:: pop(void){									// Pop function
	if(size<=0)
		cout<<"\t Stack is already empty\n";
	else{
		size--;
		cout<<"\tSuccess\n";
		}
	return;
}

int Stack:: peep(void){									// Peep function	
	if(size==0)
		cout<<"\t No element found\n";
	else
		return A[size-1];
}

void Stack:: traversal(void){							// Traversal function
	int i=0;
	if(size==0){
		cout<<"\t Empty stack\n";
		return;
	}
	cout<<"Stack Elements :\n";						//Print elements
	for(i=0;i<size;i++)
		cout<<A[i]<<"\n";
	return;
}
// main function
int main(){
	int n,i,j;
	cout<<"Enter the size of Stack to be created : ";
	cin>>n;
	Stack stack(n);
	while(1){
		cout<<"1. Push an item\n2. Pop an item\n3. Peep into the stack\n4. Show the elements\n5. EXIT\n";
		cin>>n;
		if(n==1){
			int elem;
			cout<<"Enter the element-  ";
			cin>>elem;
			stack.push(elem);
		}
		else if(n==2)
			stack.pop();
		else if(n==3)
			cout<<"\t"<<stack.peep()<<endl;
		else if(n==4)
			stack.traversal();
		else break;
	}
return 0;
}
