#include<iostream>
using namespace std;

class in_sort
{
    int n;
    public :
        in_sort()
        {
            cout << "Enter no of Element :- ";
            cin >> n;

            int arr[n];
            for(int i=0;i<n;i++)
            {
                cout << "Enter element :- ";
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
    in_sort s;
    return 0;
}