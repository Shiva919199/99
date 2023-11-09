#include<iostream>
#include<vector>
#include<chrono>

using namespace std;
using namespace std :: chrono;

int knapsack(vector<int>& values, vector<int>& weights, int capacity, vector<int>& solution)
{
    int n = values.size();

    vector<vector<int>> dp( n+1 , vector<int>(capacity + 1, 0));

    for(int i = 0; i <= n; ++i)
    {
        for(int w = 0; w <= capacity; ++w)
        {
            if( i ==0 || w == 0)
            {
                dp[i][w] = 0;
            }

            else if(weights[i-1] <= w)
            {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            }

            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    int i = n , w = capacity;

    while(i>0 && w>0)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            solution[i-1]=1;
            w -= weights[i-1];
        }
        i--;
    }

    return dp[n][capacity];
}

int main()
{
    int n,capacity ;

    cout<<"\nEnter Number Of Items : ";
    cin>>n;

    vector<int> values(n);
    vector<int> weights(n);

    cout<<"\nEnter Values Of Items : \n";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>values[i];
    }

    cout<<"\nEnter Weights Of Items : \n";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>weights[i];
    }

    cout<<"\nEnetr Capacity Of Knapsack Bag : ";
    cin>>capacity;

    vector<int> solution(n,0);

    auto start = high_resolution_clock::now();
    int max_value = knapsack(values, weights, capacity, solution);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout<<"\nMaximum Value : "<< max_value;
    cout<<"\nOptimal Solution Vector : ";
    for(int item : solution)
    {
        cout<<item<<" ";
    }

    cout<<"\nExecution Time : "<<duration<<" milliseconds";
}