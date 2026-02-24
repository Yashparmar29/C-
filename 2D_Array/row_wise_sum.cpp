#include<iostream>
using namespace std;

class method
{
    int n;
    int m;
    int **arr;
public :
    void getvalue() // get n and m vaue
    {
        cout << "Enter n :- ";
        cin >> n;
        cout << "Enter m :- ";
        cin >> m;
        arr = new int*[n];
    }
    void getarray()
    {
        for(int i=0;i<n;i++)
        {
            arr[i] = new int[m];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << "Enter no :- ";
                cin >> arr[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    void row_sum()
    {
        int sum[n];
        for(int i=0;i<n;i++)
        {
            sum[i] = 0;
            for(int j=0;j<m;j++)
            {
                sum[i] += arr[i][j];    
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << "sum of row " << i+1 << " :- " << sum[i] << endl;
        }
    }
    
};
int main()
{
    method m;
    m.getvalue();
    m.getarray();
    m.row_sum();
    return 0;
}