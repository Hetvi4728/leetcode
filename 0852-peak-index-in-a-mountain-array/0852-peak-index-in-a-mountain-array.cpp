class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // We are in the increasing part
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            // We are in the decreasing part or at the peak
            else {
                right = mid;
            }
        }

        return left;   // left == right, which is the peak index
    }
};