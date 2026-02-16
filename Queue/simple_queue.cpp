#include<iostream>
using namespace std;

int main()
{
    int size = 10;
    int arr[size];

    int front = -1;
    int rear = -1;

    if(rear == size-1)
    {
        cout << "Queue is overflow....";
    }
    else
    {
        front +=1;
        rear +=1;
        for(;rear<size;rear++)
        {
            cout << "Enter no :-";
            cin >> arr[rear];
        }
    }
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << endl;
    }
}