#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int isteps = 0;
int rsteps = 0;

int recursiveFibonacci(int n)
{
    if(n < 0)
    {
        return 0;
    }

    if(n == 0 || n == 1)
    {
        return 1;
    }
    return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

int iterativeFibonacci(int n)
{
    vector<int> f(n);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i < n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    
    cout<<"\nIteratively Fibonacci Series: ";
    for(int i = 0; i < n ; i++)
    {
        cout<<f[i]<<" ";
    }
    return 0;
}

int recursiveFibonaccl(int n)
{
    cout<<"Recursively Sibonacci Series: ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<recursiveFibonacci(i)<<" ";
    }
    return 0; 
}

int main()
{
    int choice, n;
    clock_t start,end;

    while(true)
    {
        cout<<"\nFibonacci Menu: ";
        cout<<"\n1. Iterative Fibonacci Series: ";
        cout<<"\n2. Recursive Fibonacci Series: ";
        cout<<"\n3. Quit ";
        cout<<"\n\nEnter Your Choice: ";
        cin>>choice;

        if(choice == 1 || choice == 2)
        {
            cout<<"\nEnter Number Whose Fibonacci Series You Want To Generate: ";
            cin>>n;

            if(n < 0)
            {
                cout<<"\nInvalid Input!!! Enter Positive Number. "<<endl;
                continue;
            }

            if(choice == 1)
            {
                isteps=0;
                start = clock();
                iterativeFibonacci(n);
                end = clock();
            }

            if(choice == 2)
            {
                rsteps = 0;
                start = clock();
                recursiveFibonaccl(n);
                end = clock();
            }

            double elapsed = double(end-start) / CLOCKS_PER_SEC*1000;
            cout<<"\nExecution Time: "<<elapsed<<" Milliseconds"<<endl<<endl;
        }

        else if (choice == 3)
        {
            cout<<"\nSuccessfully Exited ";
            break;
        }

        else
        {
            cout<<"\nInvalid Choice!!! Enter Valid Choice "<<endl;
        }
    }
}
