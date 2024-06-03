//
// Created by nazar on 03.06.2024.
//

#ifndef UNTITLED_ARRAYS_H
#define UNTITLED_ARRAYS_H


#include <cstdlib>
#include <ctime>
#include <iostream>

namespace ArrayUtils {

    void generateArray(int arr[], int size);

    void printArray(int arr[], int size);

    void sortArray(int arr[], int size);

    int* concatArrays(int arr1[], int arr2[], int size1, int size2);
}

#endif