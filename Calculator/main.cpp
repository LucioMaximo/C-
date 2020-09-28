#include <iostream>

using namespace std;

double calc_interpreter(double a, char op, double b)
{
    switch(op)
    {
    case '/':
        return a/b;
    case '*':
        return a*b;
    case '+':
        return a+b;
    case '-':
        return a-b;
    }
}

int main()
{
    double a;
    double b;
    char op;
    while(true){
    cout << "Please enter some numbers to calculate. Format: a/b a*b a+b a-b: " << endl;
    cin >> a >> op >> b;
    cout << "Calculation: " << calc_interpreter(a,op,b)<< endl;
    }
}
