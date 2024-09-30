//
// Created by au9u5t on 24-9-29.
//

#include "Confusion.h"
const int ARRAY_SIZE = 100;
namespace Array {
    std::vector<int> array = {
            1, 2, 3, 4, 5,
            6, 7, 8, 9, 10,
            11, 12, 13, 14, 15,
            16, 17, 18, 19, 20,
            21, 22, 23, 24, 25,
            26, 27, 28, 29, 30,
            31, 32, 33, 34, 35,
            36, 37, 38, 39, 40,
            41, 42, 43, 44, 45,
            46, 47, 48, 49, 50,
    };
}

void Confusion::generateAndSortArray() {

    std::srand(std::time(nullptr));
    std::vector<int> huaarr(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        huaarr[i] = std::rand() % 1000;
    }
    std::sort(huaarr.begin(), huaarr.end(),
              [](int a, int b) { return a < b; });

    for (int i = 0; i < ARRAY_SIZE; i++) {
    }
    for (const auto &i: huaarr) {
    }
}

void Confusion::generateAndTransformArray() {

    std::srand(std::time(nullptr));
    std::vector<int> data(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        data[i] = std::rand() % 1000;
    }

    int sum = 0;
    for (const auto &value: data) {
        sum += value * value;
    }

    double average = static_cast<double>(sum) / ARRAY_SIZE;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (data[i] > average) {
            data[i] = 0;
        }
    }

    std::vector<int> transformed(data.size());
    std::transform(data.begin(), data.end(), transformed.begin(),
                   [](int x) { return x * 3 + 7; });

}

void Confusion::performComplexOperations(const std::vector<int> &arr) {
    int sum = 0, product = 1, min = INT_MAX, max = INT_MIN;
    bool flag = false;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (i % 2 == 0) {
            sum += arr[i];
            if (arr[i] < min) {
                min = arr[i];
            }
        } else {
            product *= arr[i];
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // 复杂的条件逻辑
        if (sum > 500 && product < 100000) {
            flag = !flag;
        }

        // 更多无用的计算
        for (int j = 0; j < 10; ++j) {
            sum += (i * j) % 10;
            product *= (i + j) % 10;
        }
    }

    // 最终结果并没有被使用
    (void) sum;
    (void) product;
    (void) min;
    (void) max;
    (void) flag;

}

