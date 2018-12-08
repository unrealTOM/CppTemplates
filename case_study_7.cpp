#include "SwitchCase.h"
#include<iostream>
using namespace std;

template<typename T,
    typename enable_if<is_integral<T>::value, int>::type n = 0>
    void what_am_i(T) {
    cout << "Integral number." << endl;
}

template<typename T,
    typename enable_if<is_floating_point<T>::value, int>::type n = 0>
    void what_am_i(T) {
    cout << "Floating point number." << endl;
}

template<typename T,
    typename enable_if<is_pointer<T>::value, int>::type n = 0>
    void what_am_i(T) {
    cout << "Pointer." << endl;
}

#if SWITCH_CASE == 7
int main()
{
    what_am_i(123);
    what_am_i(123.0);
    what_am_i("123");

    getchar();
}
#endif
