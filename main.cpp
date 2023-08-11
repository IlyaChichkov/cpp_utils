#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "redmath.hpp"

using namespace std;
using namespace math_op;

int main(int argc, char const *argv[])
{
    Vector2 v1(1, 1);
    Vector2 v2(Vector2::One);

    if(v1 == v2)
    {
        cout << "equal";
    }
    else
    {
        cout << "not equal";
    }
    return 0;
}
