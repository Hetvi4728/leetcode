
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long gcdVal = 0;
            long long lcmVal = 1;

            for (int j = i; j < n; j++) {
                gcdVal = gcd(gcdVal, (long long)nums[j]);

                lcmVal = lcm(lcmVal, (long long)nums[j]);

                // Prevent product overflow
                if (product > (lcmVal * gcdVal) / nums[j]) {
                    break;
                }

                product *= nums[j];

                if (product == lcmVal * gcdVal) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
