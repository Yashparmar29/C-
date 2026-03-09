#include<iostream>
using namespace std;

class method
{
    int n;
   // int arr[];

    public :
        method()
        {
            cout << "Enter no of element :- ";
            cin >> n;
            int arr[n];
            for(int i=0;i<n;i++)
            {
                cout << "Enter Element :-  ";
                cin >> arr[i];

                for(int j=0;j<=i;j++)
                {
                    if(arr[i] < arr[j])
                    {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
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
}