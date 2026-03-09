#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of element :- ";
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout << "Enter Element :- ";
        cin >> arr[i];
    }

    int f_no;
    cout << "Find Element :- ";
    cin >>  f_no;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == f_no)
        {
            cout << "Element is in array" << endl; 
            cout << "index no :- " << i; 
        }
        else
        {
            cout << "Element is not in Array";
        }
    }

}