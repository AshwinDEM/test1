#include <iostream>
using namespace std;

template <typename T> 
int linsearch(T arr)
{
    T key;
    cout<<"Enter key to search for"<<endl;
    cin>>key;
    int index=-1;
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(key==arr[i])
        {
            index==i;
        }
    }
    return index;
}
template <typename T>
void init(T& Arr)
{
    T* Arr=new T[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Arr["<<i<<"] :"<<endl;
        cin>>Arr[i];
    }
}

int main()
{
    int n;
    int x;
    cout<<"Enter number of terms in array"<<endl;
    cin>>n;
    int Arr[n];
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Arr["<<i<<"] :"<<endl;
    //     cin>>Arr[i];
    // }
    cout<<"break";
    //int index=linsearch(Arr,9);

    while(true)
    {
        cout<<"Enter 1: Search through int array, 2:Search through character array, 3:Search through double array"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
                init<int>(Arr);
                int pos=linsearch<int>(Arr);
            case 2:
                init<char>(Arr);
                int pos=linsearch<char>(Arr);
            case 3:
                init<double>(Arr);
                int pos=linsearch<double>(Arr);
        };
    }


}
