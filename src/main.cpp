
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/timer/timer.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/utility/enable_if.hpp>

#if defined(TYPE1) || defined(TYPE2)
#  include "hard_coded_functions.hpp"
#elif defined(TYPE3)
#  include "hard_coded_function_objects.hpp"
#elif defined(TYPE4)
#  include "templated_function_objects_with_hard_coded_member_name.hpp"
#elif defined(TYPE5)
#  include "bind_expressions_returned_as_boost_functions_from_hard_coded_functions.hpp"
#elif defined(TYPE6)
#  include "bind_expressions_returned_as_boost_functions.hpp"
#elif defined(TYPE7)
#  include "bind_expressions_inline.hpp"
#elif defined(TYPE8)
#  include "operator_wrapper_with_operator_passed_to_it.hpp"
#elif defined(TYPE9)
#  include "operator_wrapper_with_operator_templated_on_op_type_enable_if.hpp"
#elif defined(TYPE10)
#  include "operator_wrapper_with_operator_templated_on_op_type_full_specialization.hpp"
#elif defined(TYPE11) || defined(TYPE12) || defined(TYPE13)
#  include "operator_wrapper_with_operator_selected_using_enum.hpp"
#elif defined(TYPE14)
#  include "operator_wrapper_clever_lookup.hpp"
#endif

#include "types.hpp"

using namespace boost::assign;
using namespace std;

template< typename T, typename V > 
void print( vector<T>& stuff, V (T::* member_ptr) )
{
    for(size_t i=0; i < stuff.size(); ++i)
    {   
        if (i) cout<< ", ";
        cout<< stuff[i].*member_ptr;
    }   
    cout<< endl;
}

#ifndef MAX_ITERS
#  define MAX_ITERS 5000000
#endif

int main(int, char**)
{
    vector< Type > types = list_of
        ( Type("one", 1) )
        ( Type("two", 2 ) )
        ( Type("three", 3 ) )
        ( Type("four", 4 ) )
        ( Type("five", 5 ) )
        ( Type("six", 6 ) )
        ( Type("seven", 7 ) )
        ( Type("eight", 8 ) )
        ( Type("nine", 9 ) )
        ( Type("ten", 10 ) )
        ( Type("eleven", 11 ) )
        ( Type("twelve", 12 ) )
        ( Type("thirteen", 13 ) )
        ( Type("fourteen", 14 ) )
        ( Type("fifteen", 15 ) )
        ( Type("sixteen", 16 ) )
        ( Type("seventeen", 17 ) )
        ( Type("eighteen", 18 ) )
        ( Type("nineteen", 19 ) )
        ( Type("twenty", 20 ) );

    boost::timer::auto_cpu_timer timer;
    for( int i=0; i < MAX_ITERS; ++i )
    {
#if defined(LESS_THAN)
        sort_less_than( types );
#endif
#if defined(GREATER_THAN)
        sort_greater_than( types );
#endif
#if defined(EQUAL_TO)
        sort_equal_to( types );
#endif
    }

    print( types, &Type::s );

    return 0;
}
