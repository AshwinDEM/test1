#include<iostream>
using namespace std;

#define MAX 100

template<typename T>
class queue{
	T a[100];
	int front;
	int rear;
	public:
		void choice();
		void insert();
		void dequeue();
		void display();
};

template<typename T>
void queue<T>::choice(){
	int ch;
	rear=-1;
	front=0;
	while(1){
		cout<<"Enter 1:insert 2:delete 3:display 4:quit\n";
		cin>>ch;
		switch(ch){
			case 1:insert();
					break;
			case 2:dequeue();
					break;
			case 3: display();
					break;
			default:return;
		}
	}
	
}

template<typename T>
void queue<T>::insert(){
	T ele;
	if(rear==MAX-1){
		cout<<"Queue Full\n";
	}	
	else{
		cout<<"Enter the element to be added\n";
		cin>>ele;
		rear++;
		a[rear]=ele;
	}
}

template<typename T>
void queue<T>::dequeue(){
	if (front>rear){
		cout<<"Queue empty";
	} else{
		cout<<"The deleted element is "<<a[front]<<"\n";
		front++;
	}
}

template<typename T>
void queue<T>::display(){
	if(front>rear){
		cout<<"Queue empty\n";
	} else{
		int i;
		for(i=front;i<=rear;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	queue<int> iq;
	queue<float> fq;
	queue<string> sq;
	int ch;
	while(1){
		cout<<"Enter 1:integer queue 2: string queue 3:float queue 4:exit\n";
		cin>>ch;
		switch(ch){
			case 1:iq.choice();
					break;
			case 2: sq.choice();
					break;
			case 3: fq.choice();
					break;
			default: return 0;
		}
	}
}
