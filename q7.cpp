#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <string>
using namespace std;

bool isdigit_for_str(string str)
{
	bool val=true;
	for(int i=0;i<str.size();i++)
	{
		if(!isdigit(str[i]))
		{
			val=false;
		}
	}
	return val;
}

void init(vector<int>& v1)
{
	string temp;
	cout<<"Enter number to be added to the vector"<<endl;
	cout<<"Enter a character to stop adding numbers"<<endl;
	while(true)
	{
		cin>>temp;
		if(!isdigit_for_str(temp))
		{
			break;
		}
		v1.push_back(stoi(temp));
	}
}

void bubbleSort(list <int>& l)
{
    cout<<"Size of l="<<l.size()<<endl;
    int i, j,temp;

    for (i = 0; i < l.size() - 1; i++)
    {
        for (j = 0; j < l.size() - i - 1; j++)
        {
       	    list<int>::iterator it=l.begin();
		    list<int>::iterator it2=l.begin();
       	    advance(it,j);
       	    advance(it2,j+1);
       	    if (*it>*it2)
         	{
         	    temp=*it;
         	    *it=*it2;
         	    *it2=temp;
         	}
         	    
	    }
    }
}
void copy(list<int>&l1,vector<int>&v2)
{
	int beg,end;
	cout<<"Enter index of the first and last element that you want to copy"<<endl;
	cin>>beg>>end;
	if(beg>l1.size()||end>l1.size()||beg<=0||end<=0)
	{
		cout<<"The indexes should be within the limit of the vector\n Exiting..."<<endl;
		exit(0);
	}
	for (int i=beg;i<=end;i++)
	{
		list<int>::iterator it=l1.begin();
		advance(it,i);
		v2.push_back(*it);
	}

}
void print(vector<int>& v)
{
    for(const auto&i:v)
    {
	    cout<<i<<endl;
	}
}

void print(list<int>& l)
{
    for(const auto&i:l)
	{
		cout<<i<<endl;
    }
}
int main()
{
	vector<int>v1,v2;
	list <int> l1,l2;
	init(v1);
    for (int i=0;i<v1.size();i++)
	{
	    	l1.push_back(v1[i]);
	}
	bubbleSort(l1);
    cout<<"List after sorting ="<<endl;
    print(l1);
	copy(l1,v2);
	cout<<"Copied list :"<<endl;
    print(v2);

}
//	cout<<"Break 1"<<endl;


//	cout<<"Break 2"<<endl;
	//l1.sort();

//	cout<<"Break 3"<<endl;
	
	

//	cout<<"Break 4"<<endl;
		




//void create_vec(vector<int> v1)
//{
//
//	int temp;
//	cout<<"Enter number to be added to the vector"<<endl;
	//cout<<"Enter a character to exit the loop"<<endl;
//	//for(int i=0;i<10;i++)
	//{
	//	cin>>temp;
		/*if(temp==0)
		{
			break;
		}*/
	//	v.push_back(temp);
//	}
	//v1.push_back(10);
	//v1.push_back(20);
	//v1.push_back(30);
	//v1.push_back(40);
	//v1.push_back(50);
	//v1.push_back(700);
	//v1.push_back(60);
	
//}
