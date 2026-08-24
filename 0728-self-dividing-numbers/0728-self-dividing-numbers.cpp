class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> arr;

        for (int i = left; i <= right; i++) {
            int num = i;
            bool valid = true;

            while (num != 0) {
                int remainder = num % 10;

                if (remainder == 0 || i % remainder != 0) {
                    valid = false;
                    break;
                }

                num = num / 10;
            }

            if (valid) {
                arr.push_back(i);
            }
        }

        return arr;
    }
};