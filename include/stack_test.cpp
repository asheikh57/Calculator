#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Stack.h"

TEST_CASE("Testing Stack Class") {
    Stack<int> st = Stack<int>();
    
    SUBCASE("Testing Stack Initialization") {
        CHECK(st.isEmpty() == true);
        CHECK(st.size() == static_cast<std::size_t>(0));
        CHECK_THROWS_AS(st.pop(), std::out_of_range);
        CHECK_THROWS_WITH(st.pop(), "Stack.h : pop() : Empty, stack underflow");
    };

    st.push(1);
    SUBCASE("Testing Single Push/Pops") {
        CHECK(st.isEmpty() == false);
        CHECK(st.size() == static_cast<std::size_t>(1));
        CHECK(st.pop() == 1);
        
        CHECK(st.isEmpty() == true);
        CHECK(st.size() == static_cast<std::size_t>(0));
        CHECK_THROWS_AS(st.pop(), std::out_of_range);
        CHECK_THROWS_WITH(st.pop(), "Stack.h : pop() : Empty, stack underflow");
    };

    st.push(2);
    st.push(3);
    SUBCASE("Testing Multiple Pushes/Pops") {
        CHECK(st.isEmpty() == false);
        CHECK(st.size() == static_cast<std::size_t>(3));
        CHECK(st.pop() == 3);
        
        CHECK(st.isEmpty() == false);
        CHECK(st.size() == static_cast<std::size_t>(2));
        CHECK(st.pop() == 2);
        
        CHECK(st.isEmpty() == false);
        CHECK(st.size() == static_cast<std::size_t>(1));
        CHECK(st.pop() == 1);
        
        CHECK(st.isEmpty() == true);
        CHECK(st.size() == static_cast<std::size_t>(0));
        CHECK_THROWS_AS(st.pop(), std::out_of_range);
        CHECK_THROWS_WITH(st.pop(), "Stack.h : pop() : Empty, stack underflow");
    };
}