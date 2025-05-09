#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int nums[], int n) {
        bool seen[n + 1];
        for (int i = 0; i <= n; ++i) {
            seen[i] = false;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                seen[nums[i]] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                return i;
            }
        }

        return n + 1;
    }
};

int main() {
    Solution sol;
    int test1[] = {1, 2, 0};
    int test2[] = {3, 4, -1, 1};
    int test3[] = {7, 8, 9, 11, 12};
    int* testCases[] = {test1, test2, test3};
    int sizes[] = {3, 4, 5};
    int numberOfTests = sizeof(sizes) / sizeof(sizes[0]);
    for (int i = 0; i < numberOfTests; ++i) {
        cout << "Input: ";
        cout << " => First Missing Positive: " << sol.firstMissingPositive(testCases[i], sizes[i]) << endl;
    }
    return 0;
}
