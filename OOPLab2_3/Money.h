#pragma once
#include <string>
#include <iostream>

using namespace std;

class Money
{
private:
    long first;
    char second;

public:
    Money(); 
    Money(long x, char y); 
    Money(const Money& other); 

    long getFirst() const; 
    char getSecond() const; 
    void setFirst(long value);
    void setSecond(char value); 

    bool init(long x, char y); 
    void read(); 
    void display() const; 
    operator string() const;
    void getSize() const;

    Money& operator=(const Money& other); 
    Money operator+(const Money& other) const; 
    Money operator/(double divisor) const; 
    Money operator/(const Money& other) const;

    Money& operator++(); 
    Money operator++(int);
    Money& operator--(); 
    Money operator--(int); 

    friend ostream& operator <<(ostream&, const Money&);
    friend istream& operator >>(istream&, Money&);

};