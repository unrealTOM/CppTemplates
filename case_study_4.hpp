#pragma once

#if 0

class B {};
class D : public B {};

template <typename T, typename U, bool Enabled = std::is_base_of<T, U>::value> class Add;  // ģ��ķ�����ʽ��ԭ�ͣ�

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

Add<B, D> a;       // �������Ǹ��ػ�
Add<int, float> b; // �������Ǹ��ػ�

/*--------------------*/

template <bool Enabled> class AddBase;  // ģ��ķ�����ʽ��ԭ�ͣ�
template <bool Enabled> class AddBase<true> {};
template <bool Enabled> class AddBase<false> {};

template <typename T, typename U>
struct Add : public AddBase< std::is_base_of<T, U>::value >
{
    // Blah blah blah
};

Add<B, D> a;      // �̳���AddBase<true>
Add<int, float> b;    // �̳���AddBase<false>

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
