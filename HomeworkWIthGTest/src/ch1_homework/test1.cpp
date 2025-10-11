#include <iostream>
#include "../include/ch1_homework/test1.h"
using namespace std;

void print_integers_between()
{
    int v1 = 0, v2 = 0;
    cout << "Please enter two numbers: " << endl;
    cin >> v1 >> v2;

    if (v1 > v2) swap(v1, v2);

    cout << "All integers between " << v1 << " and " << v2 << " are: " << endl;
    for (int i = v1; i <= v2; ++i)
        cout << i << " ";
    cout << endl;
}