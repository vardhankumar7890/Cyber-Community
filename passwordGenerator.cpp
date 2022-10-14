#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    string password;
    int n,l;
    srand(time(NULL));
    char lower[]="abcdefghijklmnopqrstuvwxyz";
    char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char number[]="1234567890";
    char symbol[]="!@#$%^&*()_+=,./;[]}{:>?<-";
    int selector=0;
    l=rand() % 7;
    n=8+l;
    for(int i=0;i<n;i++)
    {
        if(i == 0 )
        {
            password[i]=upper[rand() % 26];
        }
        else if(i == 1)
        {
            password[i]=lower[rand() % 26];
        }
        else if( i== 2)
        {
            password[i]=number[rand() % 10];
        }
        else if(i == 3)
        {
            password[i]=symbol[rand() % 26];
        }
        else
        {
            selector= rand() % 4;
            switch(selector)
            {
                case 0:
                {
                    password[i]=upper[rand() % 26];
                    break;
                }
                case 1:
                {
                    password[i]=lower[rand() % 26];
                    break;
                }
                case 2:
                {
                    password[i]=number[rand() % 10];
                    break;
                }
                case 3:
                {
                    password[i]=symbol[rand() % 26];
                    break;
                }
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        cout<<password[j];
    }
    return 0;
}