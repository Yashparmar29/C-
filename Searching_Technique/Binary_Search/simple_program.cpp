#include<iostream>
using namespace std;

class method
{
    int n;
    int arr[];

    public :
        method()
        {
            cout << "Enter no of element :- ";
            cin >> n;
            arr[n];
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
                cout << arr[i] << " , " ;
                cout << endl;
            }
        }
        void b_search()
        {
            cout << "value of search :- ";
            int s_value;
            cin >> s_value;

            int head = n-1;
            int lower = 0;

            while(lower <= head)
            {
                int middle = (lower+head)/2;
                if(arr[middle] == s_value)
                {
                    cout << "Value is in Array...";
                    cout << "index no :- " << middle;
                    break;
                }
                else if(arr[middle] < s_value)
                {
                    lower = middle;
                }
                else if(arr[middle] > s_value)
                {
                    head = middle;
                }
                else 
                {
                    cout << "value is not in Array..";
                }
            }
        }
};
int main()
{
    method m;
    m.b_search();
}