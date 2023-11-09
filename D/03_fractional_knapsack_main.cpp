#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>
#include<iomanip>

using namespace std;
using namespace std:: chrono;

bool compare(pair<int,int>p1, pair<int, int>p2)
{
    return (double)p1.first / p1.second > (double)p2.first / p2.second;
}

int main()
{
    int n;
    cout<<"\nEnter Number Of Objects : ";
    cin>>n;

    vector<pair<int, int>> item(n);
    cout<<"\nEnter Profit And Weight Of Weight (P W): \n";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>item[i].first >> item[i].second ;
    }

    int capacity;
    cout<<"\nEnter Capacity Of Knapsack Bag : ";
    cin>>capacity;

    auto start = high_resolution_clock::now();

    sort(item.begin(), item.end(), compare);

    vector<double> Solution(n,0.0);
    int totalprofit = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(capacity >= item[i].second)
        {
            totalprofit += item[i].first;
            capacity -= item[i].second;
            Solution[i] = 1.0;
        }
        else
        {
            double valueperweight = (double)item[i].first / item[i].second;
            totalprofit += valueperweight * capacity;
            Solution[i] = (double)capacity / item[i].second;
            break;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout<<fixed<<setprecision(2);

    cout<<"\nOptimal Solution Vector: ( ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<Solution[i]<<" ";
    }
    cout<< " )"<<endl;

    cout<<"Optimal Value : "<<totalprofit;
    cout<<"\nExecution Time: "<<duration<<" Milliseconds"<<endl;    
}