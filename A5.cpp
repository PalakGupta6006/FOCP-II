//Reversing array by 90 degrees clockwise
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;

    cout<<"Original matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a = n*i + j + 1;
            cout<<left<<setw(5)<<a<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"90 degrees reversed matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a = n*(n - j - 1) +i+1;
            cout<<left<<setw(5)<<a<<" ";
        }
        cout<<endl;
    }

    return 0;
}