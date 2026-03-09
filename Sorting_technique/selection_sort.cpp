#include<iostream>
using namespace std;

class sel_sort
{
    int n;
    public :
        sel_sort()
        {
            cout << "Enter no :- ";
            cin >> n;

            int arr[n];
            for(int i=0;i<n;i++)
            {
                cout << "Element :- ";
                cin >> arr[i];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(arr[i] > arr[j])
                    {
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
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
    sel_sort s;
    return 0;
}