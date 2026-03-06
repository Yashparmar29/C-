#include<iostream>
#include<string>

using namespace std;

class method
{
    char name[10];
    public :
        method()
        {
            int top = -1;
            int rear = -1;

            if(rear == 10)
            {
                cout << "Stack is overflow.....";
            }
            else
            {
                top++;
                for(int i=0;i<10;i++)
                {
                    cout << "Enter infix stmt :- ";
                    cin >> name[i];
                    rear ++;
                }
            }

            for(int i=0;i<10;i++)
            {
                cout << name[i];
            }
        }
        //infix solution
        int infix()
        {
            for(int i=0;i<10;i++)
            {
                
            }
        }
};
int main()
{
    method m;

}