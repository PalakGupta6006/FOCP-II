#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int array[n];
     
     for(int i=0;i<n;i++)
     {
        cout<<"Enter value of "<<i<<": ";
        cin>>array[i];
     }

     for(int i=0;i<n/2;i++)
     {
        int temp;
        temp = array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=temp;
     }

     for(int i=0;i<n;i++)
     {
        cout<<array[i]<<" ";
     }

     int max1 = array[0], max2 = array[0];

    // Find the first maximum
    for (int i = 1; i < n; i++) {
        if (array[i] > max1) {
            max1 = array[i];
        }
    }

    // Find the second maximum
    for (int i = 0; i < n; i++) {
        if (array[i] > max2 && array[i] < max1) {
            max2 = array[i];
        }
    }
        cout << "Second maximum is: " << max2 << endl;

        int min1 = array[0], min2 = array[0];

    // Find the first minimum
    for (int i = 1; i < n; i++) {
        if (array[i] < min1) {
            min1 = array[i];
        }
    }

    // Find the second minimum
    for (int i = 0; i < n; i++) {
        if (array[i] < min2 && array[i] > min1) {
            min2 = array[i];
        }
    }
        cout << "Second minimum is: " << min2 << endl;

     return 0;
}