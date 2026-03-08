// in bubble sort eevry ement compare on every element n number of time. 
//so time complexity on bubble sort is log(n)
#include<iostream>
using namespace std;

class method
{
    int n;
    public :
        method()
        {
            cout << "Enter number of element :- ";
            cin >> n;

            int arr[n];
            for(int i=0;i<n;i++)
            {
                cout << "Enter element :- ";
                cin >> arr[i];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int temp;
                    if(j==n)
                    {
                        arr[j] == arr[j];
                    }
                    else
                    {
                        if(arr[j] > arr[j+1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                cout << arr[i] << " , ";
            }
        }
};
int main()
{
    method m;
    return 0;
}
/*
    Enter number of element :- 5
    Enter element :- 3
    Enter element :- 1
    Enter element :- 2
    Enter element :- 5
    Enter element :- 4
    1 , 2 , 3 , 4 , 5 ,
*/