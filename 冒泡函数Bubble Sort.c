#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> // 包含<stdlib.h>头文件以使用malloc和free函数
#include <string.h>

void swap(void* a, void* b, size_t size) {
    char* temp = (char*)malloc(size); // 使用malloc动态分配内存，并将返回的指针转换为char *
    if (temp == NULL) {
        printf("内存分配失败\n");
        return;
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp); // 释放动态分配的内存
}

void bubble_sort(void* arr, size_t arr_size, size_t elem_size, int (*cmp_func)(void*, void*)) {
    char* array = (char*)arr;
    for (size_t i = 0; i < arr_size - 1; i++) {
        for (size_t j = 0; j < arr_size - i - 1; j++) {
            char* curr = array + j * elem_size;
            char* next = array + (j + 1) * elem_size;
            if (cmp_func(curr, next) > 0) {
                swap(curr, next, elem_size);
            }
        }
    }
}

int compare_int(void* a, void* b) {
    int* int_a = (int*)a;
    int* int_b = (int*)b;
    return (*int_a - *int_b);
}

int compare_float(void* a, void* b) {
    float* float_a = (float*)a;
    float* float_b = (float*)b;
    if (*float_a > *float_b) return 1;
    else if (*float_a < *float_b) return -1;
    else return 0;
}

int main() {
    int int_arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    float float_arr[] = { 64.5, 34.1, 25, 12.9, 22.3, 11.2, 90.4 };
    size_t int_arr_size = sizeof(int_arr) / sizeof(int_arr[0]);
    size_t float_arr_size = sizeof(float_arr) / sizeof(float_arr[0]);

    // 对整型数组进行排序
    bubble_sort(int_arr, int_arr_size, sizeof(int), compare_int);
    printf("排序后的整型数组: ");
    for (size_t i = 0; i < int_arr_size; i++) {
        printf("%d ", int_arr[i]);
    }
    printf("\n");

    // 对浮点型数组进行排序
    bubble_sort(float_arr, float_arr_size, sizeof(float), compare_float);
    printf("排序后的浮点型数组: ");
    for (size_t i = 0; i < float_arr_size; i++) {
        printf("%.2f ", float_arr[i]);
    }
    printf("\n");

    return 0;
}
