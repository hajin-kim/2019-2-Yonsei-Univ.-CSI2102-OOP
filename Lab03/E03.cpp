//
//  E03.cpp
//  9.17-3-P
//
//  Created by 김하진 on 19.9. 18.
//  Copyright © 2019 김하진. All rights reserved.
//

#include <iostream>

class Complex
{
private:
    int a, b;
    
public:
    Complex();
    Complex(int x, int y);
    void getAB(int&, int&) const;
    int getA() const;
    int getB() const;
    Complex add(Complex) const;
    Complex sub(Complex) const;
    Complex mult(Complex) const;
};

Complex::Complex()
{
    a = 0;
    b = 0;
}

Complex::Complex(int x, int y)
{
    a = x;
    b = y;
}

int Complex::getA() const
{
    return a;
}

int Complex::getB() const
{
    return b;
}

Complex Complex::add(Complex other) const
{
    int t1 = a + other.getA(), t2 = b + other.getB();
    return Complex(t1, t2);
}

Complex Complex::sub(Complex other) const
{
    int t1 = a - other.getA(), t2 = b - other.getB();
    return Complex(t1, t2);
}

Complex Complex::mult(Complex other) const
{
    int t1 = a * other.getA() - b * other.getB();
    int t2 = a * other.getB() + b * other.getA();
    return Complex(t1, t2);
}

int E03()
{
    int a, b, c, d;
    
    std::cin >> a >> b >> c >> d;
    
    Complex c1(a, b), c2(c, d);
    
    Complex result_add = c1.add(c2);
    std::cout << result_add.getA() << ' ' << result_add.getB() << std::endl;
    
    Complex result_sub = c1.sub(c2);
    std::cout << result_sub.getA() << ' ' << result_sub.getB() << std::endl;
    
    Complex result_mult = c1.mult(c2);
    std::cout << result_mult.getA() << ' ' << result_mult.getB() << std::endl;
    
    return 0;
}
