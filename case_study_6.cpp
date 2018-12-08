#include "SwitchCase.h"
#include<string>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<typename T>
struct iterator_trait {
    typedef typename T::iterator iterator;
    static iterator begin(T& c) { return c.begin(); }
    static iterator end(T& c) { return c.end(); }
};

template<typename T, size_t N>
struct iterator_trait<T[N]> {
    typedef T* iterator;
    static iterator begin(T arr[N]) { return arr; }
    static iterator end(T arr[N]) { return arr + N; }
};

template<typename T, typename Trait = iterator_trait<T>>
// use reference to keep array from decaying to pointer
void print_each(T& container) {
    for (typename Trait::iterator i = Trait::begin(container);
        i != Trait::end(container); ++i)
        cout << *i << ' ';
    cout << endl;
}

#if SWITCH_CASE == 6
int main() {
    int arr_i[] = { 1, 2 };
    string arr_s[] = { "3", "4" };
    vector<float> vec_f = { 5.f, 6.f };
    list<double> lst_d = { 7., 8. };

    print_each(arr_i); // 1 2
    print_each(arr_s); // 3 4
    print_each(vec_f); // 5 6
    print_each(lst_d); // 7 8

    getchar();
}
#endif
