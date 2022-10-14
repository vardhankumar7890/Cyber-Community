#include<iostream>
using namespace std;
void password(string pwd){
int length=pwd.length();
bool lower=false;
bool upper=false;
bool digit=false;
bool symbol=false;
string chars="abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "1234567890";
int i=0;
while(i<length)
{
    if(islower(pwd[i]))
    lower = true;
    if(isupper(pwd[i]))
    upper = true;
    if(isdigit(pwd[i]))
    digit = true;
    size_t specialchar = pwd.find_first_not_of(chars);
    if(specialchar != string::npos)
    symbol = true;
    i++;
}
cout << "Strength of password is ";
   if (lower && upper && digit && symbol && (length >= 8))
      cout << "Strong" << endl;
   else if ((lower || upper) && symbol && (length >= 6))
      cout << "Moderate" << endl;
   else
      cout << "Weak" << endl;

}
int main() {
   string pwd;
   cin>>pwd;
   password(pwd);
   return 0;
}

