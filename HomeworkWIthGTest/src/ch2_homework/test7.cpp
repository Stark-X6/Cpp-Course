#include <iostream>
#include "ch2_homework/test7.h"

using namespace std;

void matrix(int size)
{
    int **arr = new int *[size];
    for (int i = 0; i < size; i++)
        arr[i] = new int[size - i]();

    for (int i = 0; i < size; i ++ )
    {
        for (int j = 0; j < size - i; j ++ )
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    for (int i = 0; i < size; i ++ )
        delete [] arr[i];
    delete [] arr;
}