#include<iostream>
using namespace std;

int main()
{
    string name;
    string newstr ="";
    int flag=0;
    //1.Accepting string
    cout<<"Enter a string: ";
    getline(cin,name);
    int length = name.length();
    //2.Checking if palindrome or not
    for(int i=0;i<length;i++)
    {
        if(name[i]!=' ')
        {
            newstr += tolower(name[i]);
        }
    }
    for(int i=0;i<(newstr.length())/2;i++)
    {
        if(newstr[i]!=newstr[newstr.length() - i - 1])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"String is not palindrome!!";
    }
    else
    {
        cout<<"String is palindrome!!";
    }
    //3.Frequency of each character
     int freq[26] = {0};  

    for (int i=0;i<(newstr.length());i++)
    {
        if (newstr[i] >= 'a' && newstr[i] <= 'z')  
        {
            freq[newstr[i] - 'a']++;  
        }
    }

    cout << endl<<"Character frequencies:" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            cout << char(i + 'a') << " : " << freq[i] << endl;
        }
    }
    //4.Replacing vowels with *
    for(int i=0;i<(newstr.length());i++)
    {
        if(newstr[i]=='a' || newstr[i]=='e' || newstr[i]=='i' || newstr[i]=='o' || newstr[i]=='u')
        {
            newstr[i]='*';
        }
    }

    for(int i=0;i<(newstr.length());i++)
    {
        cout<<newstr[i];
    }

    return 0;
}