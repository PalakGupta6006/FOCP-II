#include<iostream>
using namespace std;

int main()
{   
    int n,flag;
    cout<<"Enter a positive number: ";
    cin>>n;
    if (n <= 1) 
    {
        cout<<n<<" is not prime."<<endl;
    }
    else
    {
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        } 
    }
    if(flag==1)
    {
        cout<<n<<" is not prime.";
        cout<<endl<<"Factors: "<<endl;
        for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            cout<<i<<endl;
        } 
    }
    cout<<n;
    }
    else 
    {
        cout<<n<<" is prime.";
        int next=n+1;
        while(true)
        {
            flag=0;
           for(int j=2;j<=next/2;j++)
    {
        if(next%j==0)
        {
            flag=1;
            break;
        } 
    }
        
    if(flag==0)
    {
        cout<<endl<<"Next prime greater than "<<n<<" : "<<next;
        break;
    }
        next++;
        }
    }
    }
    return 0;
}