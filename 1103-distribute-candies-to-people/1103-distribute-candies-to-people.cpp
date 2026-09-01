class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> arr(num_people);
        int give = 1;
        int i = 0;

        while (candies > 0) {
            int x = min(give, candies);
            arr[i] += x;
            candies -= x;
            give++;
            i = (i + 1) % num_people;
        }

        return arr;
    }
};