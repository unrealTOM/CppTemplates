#include "SwitchCase.h"
#include<iostream>
#include<array>
using namespace std;
#include "case_study_8.hpp"

#if SWITCH_CASE == 8
int main()
{
    vec3 v1{ 1, 2, 3 };
    vec3 v2{ 4, 5, 6 };
    vec3 v3 = v1 + v2;
    cout << v3 << endl; // [ 5 7 9 ]

    vec3c vc1{ c{ 0, 1 }, c{ 1, 2 }, c{ 2, 3 } };
    vec3c vc2{ c{ 4, 5 }, c{ 5, 6 }, c{ 6, 7 } };
    vec3c vc3 = vc1 + vc2;
    cout << vc3 << endl; // [ 4+6i 6+8i 8+10i ]
    vc3 += vc1;
    cout << vc3 << endl; // [ 4+7i 7+10i 10+13i ]

    mat32 m1{
        vec3{ 1, 2, 3 },
        vec3{ 4, 5, 6 },
    };
    mat32 m2{
        vec3{ 4, 5, 6 },
        vec3{ 7, 8, 9 },
    };
    mat32 m3 = m2 + m1;
    cout << m3 << endl; // [ [ 5 7 9 ] [ 11 13 15 ] ]
}
#endif
