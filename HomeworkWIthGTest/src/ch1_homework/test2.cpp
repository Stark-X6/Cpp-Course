#include <iostream>
#include "../include/ch1_homework/test2.h"

using namespace std;

void get_sum()
{
    int n;
    cout << "Please enter number of integers: " << endl;
    cin >> n;

    int sum = 0, value;
    cout << "Please enter " << n << " integers: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        sum += value;
    }

    cout << "Sum is: " << sum << endl;
}