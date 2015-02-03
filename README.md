# Arithmetic

This is a simple C++ wrapper around [GNU MP](https://gmplib.org/) library.
Although it can be used with any bignum library, if you define an
appropriate traits class.

To use it 

    #include "integer.h"
    #include "mpz_integer_traits.h"
    #include <iostream>

    int main(int argc, char **argv)
    {
        integer a = 5, b = 8;
        integer c = a * b;
        std::cout << "c=" << c << '\n';
        return 0;
    }

and compile with 

    g++ -std=c++11 -Wall -I/path/to/arithmetic testint.cpp -o testint -L/path/to/gmplib -lgmp

An equally simple rational class allows working with (bignum) rational
numbers. It is parameterized by an int type, e.g. `int` or `integer`.

Here's a sort of "hello world" 

    #include "rational.h"
    #include <iostream>
    
    typedef basic_rational<int> rational;
    
    int main(int argc, char **argv)
    {
        rational r1(1, 5), r2(3, 8);
        rational r3 = r1 / r2;
        std::cout << "r3=" << r3 << '\n';
        return 0;
    }

and also compile with 

    g++ -std=c++11 -Wall -I/path/to/arithmetic testrat.cpp -o testrat

# License

BSD-3
