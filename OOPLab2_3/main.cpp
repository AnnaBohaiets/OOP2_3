#include <iostream>
#include "Money.h"
#include <Windows.h>
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Money a, b, c, d, e, f , o;

    cin >> a;
    cout << " a = " << a << endl;
    a.getSize();

    b.setFirst(1);
    b.setSecond(5);
    cout << "Створене кодом b = " << b << endl;

    f = Money(8, 9);
    cout << "Створене методом Money(x,y) f = " << f << endl;

    o = Money();
    cout << "Створене методом Money() o = " << o << endl;

    c = b + a;
    cout << "a+b = " << c << endl;

    d  = a / 2.5;
    cout << "a/2.5 = " << d << endl;

    e = a / b;
    cout << "a/b = " << e << endl;

    --a;
    cout << "--a = " << a << endl;

    ++b;
    cout << "++b = " << b << endl;

    a++;
    cout << "a++ = " << a << endl;

    b--;
    cout << "b-- = " << b << endl;

    return 0;
}