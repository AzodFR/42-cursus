
#include <iostream>

using namespace std;

int adder(int a, int b)
{
    while (a & b)
    {
        // 0001
        // cout << "a & b >> " << (a & b) << endl;
        int tmp_a = a ^ b;
        // 1100
        int tmp_b = (a & b) << 1;
        // 0010
        // cout << "a ^ b >> " << tmp_a << endl;
        // cout << "((a & b) << 1) >> " << tmp_b << endl;
        // cout << "(a & b) >> " << (tmp_a & tmp_b) << endl;
        // cout << "================" << endl;
        a = tmp_a;
        b = tmp_b;
    }
    return a | b;
}

int multiplier(int a, int b)
{
    int c = 0;
    while(b)
    {
        if (b & 1)
            c = adder(c, a);
        b >>= 1;
        a <<= 1;
    }
    return c;
}

int gray_code(int a)
{
    return a ^ (a >> 1);
}

int main()
{
    int a = 5;
    int b = 9;
    cout << "5 + 9 = " << adder(a, b) << endl;
    cout << "5 * 9 = " << multiplier(a, b) << endl;
    cout << "gray_code(5) = " << gray_code(5) << endl;
    return 0;
}
