#include <iostream>

using namespace std;

string string_reverser(string str){

    string temp_str = str;
    int x = 0;

    for (int i=str.length()-1; i >= 0; i--)
    {
        str[x] = temp_str[i];
        x++;
    }
    return str;
}




int main()
{
    string x;
    cout << "Please enter something to be reversed: ";
    getline(cin,x);
    cout << "Reversed String: " << string_reverser(x);

}
