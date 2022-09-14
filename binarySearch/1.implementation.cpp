#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int targetValue) {
    int left = 0, right = nums.size() - 1;
    int idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == targetValue) {
            idx = mid;
            break;
        } else if (nums[mid] > targetValue)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return idx;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << binarySearch(nums, k);

    return 0;
}