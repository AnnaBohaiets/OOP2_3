#include "Money.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>


Money::Money() : first(0), second(0) {}

Money::Money(long x, char y) : first(x), second(y) {}

Money::Money(const Money& other) : first(other.first), second(other.second) {}

long Money::getFirst() const { return first; }

char Money::getSecond() const { return second; }

void Money::setFirst(long value) { first = value; }

void Money::setSecond(char value) {second = value;}

void Money::getSize() const {
    std::cout << "Size without pragma pack(1): " << sizeof(Money) << " bytes" << std::endl;
#pragma pack(1)
    std::cout << "Size with pragma pack(1): " << sizeof(Money) << " bytes" << std::endl;
#pragma pack()
}

bool Money::init(long x, char y)
{

    if (x >= 0 && y <= '9' && y >= '0')
    {
        if (y <= '9' && y >= '0')
            second = static_cast<int>(y) - 48;
        first = x;
        return true;
    }
    else
        return false;
}

void Money::read()
{
    long x;
    char y;
    do {
        std::cout << "Input information: " << std::endl;
        std::cout << "Money = "; std::cin >> x;
        std::cout << "Coin = "; std::cin >> y;
    } while (!init(x, y));
}

void Money::display() const
{
    std::cout << "Money = " << first << "," << static_cast<int>(second) << std::endl;
}

Money::operator string() const
{
    std::stringstream ss;
    ss << first << "," << static_cast<int>(second);
    return ss.str();
}

Money& Money::operator=(const Money& other)
{
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Money Money::operator+(const Money& other) const
{
    if ((second + other.second) <= 9 ) return Money(first + other.first, second + other.second);
    else return Money(first + other.first + 1, second + other.second - 10);
}

Money Money::operator/(double divisor) const
{
    int coin;
    coin = static_cast<int>(second);
    double result = (first + (coin / 10.0))/divisor;
    int resultint = static_cast<int>(result*10);
    double f = (resultint % 10);
    return Money(result - f/10, f);
}

Money Money::operator/(const Money& other) const
{
    int coin;
    coin = static_cast<int>(second);
    double result = (first + (coin / 10.0));
    int xcoin;
    xcoin = static_cast<int>(other.second);
    double xresult = (other.first + (xcoin / 10.0));
    double res = result / xresult;
    int resint = static_cast<int>(res * 10);
    double f = (resint % 10);
    return Money(res - f / 10, f);
}

Money& Money::operator++()
{
    if (second == 9) {
        second = 0;
        ++first;
    }
    else {
        ++second;
    }
    return *this;
}

Money Money::operator++(int)
{
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--()
{
    if (second == '\0'){ 
        --first;
        second = 9;
    }
    else {
        
        --second;
    }
    return *this;
}

Money Money::operator--(int)
{
    Money temp(*this);
    --(*this);
    return temp;
}

ostream& operator <<(ostream& out, const Money& a)
{
    out << string(a) << endl;
    return out;
}
istream& operator >>(istream& in, Money& a)
{
    cout << "Input information: " << endl;
    cout << "Money = "; in >> a.first;
    cout << "Coin = "; in >> a.second;
    return in;
}
