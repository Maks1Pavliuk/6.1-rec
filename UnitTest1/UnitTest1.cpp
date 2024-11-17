#include "pch.h" 
#include "CppUnitTest.h"
#include "../6.1 rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2 {
    TEST_CLASS(UnitTest2) {
public:

    TEST_METHOD(TestGenerateArrayRecursive) {
        int arr[SIZE];
        generateArray(arr, 0);

        for (int i = 0; i < SIZE; i++) {
            Assert::IsTrue(arr[i] >= LOWER_BOUND && arr[i] <= UPPER_BOUND);
        }
    }

    TEST_METHOD(TestCalculateAndReplaceRecursive) {
        int arr[SIZE] = { 15, 17, 19, 21, 18, 16, 20, 22, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49 };
        int count = 0, sum = 0, expected_count = 0, expected_sum = 0;

        for (int i = 0; i < SIZE; ++i) {
            if (arr[i] % 2 != 0 && i % 13 != 0) {
                expected_sum += arr[i];
                expected_count++;
            }
        }

        calculateAndReplace(arr, 0, count, sum);

        Assert::AreEqual(expected_count, count);
        Assert::AreEqual(expected_sum, sum);

        for (int i = 0; i < SIZE; ++i) {
            if (i % 13 != 0 && arr[i] % 2 != 0) {
                Assert::AreEqual(0, arr[i]);
            }
        }
    }
    };
}
