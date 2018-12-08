#pragma once

#if 0

class B {};
class D : public B {};

template <typename T, typename U, bool Enabled = std::is_base_of<T, U>::value> class Add;  // 模板的泛化形式（原型）

template <typename T, typename U>
struct Add<T, U, true>
{
    // Blah blah blah
};

template <typename T, typename U>
struct Add<T, U, false>
{
    // Blah blah blah
};

Add<B, D> a;       // 用上面那个特化
Add<int, float> b; // 用下面那个特化

/*--------------------*/

template <bool Enabled> class AddBase;  // 模板的泛化形式（原型）
template <bool Enabled> class AddBase<true> {};
template <bool Enabled> class AddBase<false> {};

template <typename T, typename U>
struct Add : public AddBase< std::is_base_of<T, U>::value >
{
    // Blah blah blah
};

Add<B, D> a;      // 继承自AddBase<true>
Add<int, float> b;    // 继承自AddBase<false>

/*--------------------------*/

template <typename T, typename U, typename BoolType = std::true_type> class Add;

template <typename T, typename U>
struct Add<T, U, std::integral_constant<bool, std::is_base_of<T, U>::value>>
{
};

template <typename T, typename U>
struct Add<T, U, std::integral_constant<bool, !std::is_base_of<T, U>::value> >
{
};

Add<B, D> a;      // ??
Add<int, float> b;    // ??

#endif
