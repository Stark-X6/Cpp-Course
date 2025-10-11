#include "../include/ch1_homework/test1.h"
#include "../include/ch1_homework/test2.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
int ch1_test()
{
    print_integers_between();
    get_sum();
    return 0;
}
//下面是基于gtest编写的测试
TEST(myarray_test_suit, test_case1)
{
    EXPECT_EQ(0, ch1_test());
}
// 也可以不用gtest，编写自己的main函数来启动程序
// int main()
// {
//     print_integers_between();
//     get_sum();
//     return 0;
// }