
#ifndef OPERATOR_WRAPPER_WITH_OPERATOR_PASSED_TO_IT_INCLUDED
#define OPERATOR_WRAPPER_WITH_OPERATOR_PASSED_TO_IT_INCLUDED

namespace ops {

struct LessThanOp {};
struct GreaterThanOp {};
struct EqualToOp {};

template<typename Struct, typename T, typename Op>
struct OperatorWrapper
{
    typedef T (Struct::* const member_ptr);

    OperatorWrapper(T Struct::* const member_ptr)
        : member(member_ptr)
    {
    }

    bool operator()(const Struct& s1, const Struct& s2) const;

    const member_ptr member;
};

template<typename Struct, typename T>
struct OperatorWrapper<Struct, T, LessThanOp>
{
    typedef T (Struct::* const member_ptr);

    OperatorWrapper(T Struct::* const member_ptr)
        : member(member_ptr)
    {
    }

    bool operator()(const Struct& s1, const Struct& s2) const
    {
        return s1.*member < s2.*member;
    }

    const member_ptr member;
};

template<typename Struct, typename T>
struct OperatorWrapper<Struct, T, GreaterThanOp>
{
    typedef T (Struct::* const member_ptr);

    OperatorWrapper(T Struct::* const member_ptr)
        : member(member_ptr)
    {
    }

    bool operator()(const Struct& s1, const Struct& s2) const
    {
        return s1.*member > s2.*member;
    }

    const member_ptr member;
};

template<typename Struct, typename T>
struct OperatorWrapper<Struct, T, EqualToOp>
{
    typedef T (Struct::* const member_ptr);

    OperatorWrapper(T Struct::* const member_ptr)
        : member(member_ptr)
    {
    }

    bool operator()(const Struct& s1, const Struct& s2) const
    {
        return s1.*member == s2.*member;
    }

    const member_ptr member;
};

template< typename T >
void//OperatorWrapper<Struct, T>
inline less_than()
{
    //return false;//OperatorWrapper<Struct, T, LessThan>(member_ptr);
}

//template< typename T, typename Struct >
//OperatorWrapper<Struct, T>
//inline greater_than(T Struct::*member_ptr)
//{
//    return OperatorWrapper<Struct, T>(member_ptr, &do_greater_than<T>);
//}
//
//template< typename T typename Struct::*member_ptr >
//OperatorWrapper<Struct, T>
//inline equal_to(T Struct::*member_ptr)
//{
//    return OperatorWrapper<Struct, T>(member_ptr, &do_equal_to<T>);
//}

} /* ops */

template< typename T >
void sort_less_than(T& types)
{
    typedef typename T::value_type V;
    ops::less_than<&V::s>();
    //std::sort( types.begin(), types.end(), ops::less_than<&V::s>() );
}

template< typename T >
void sort_greater_than(T& types)
{
    typedef typename T::value_type V;
}

#endif /* OPERATOR_WRAPPER_WITH_OPERATOR_PASSED_TO_IT_INCLUDED */

