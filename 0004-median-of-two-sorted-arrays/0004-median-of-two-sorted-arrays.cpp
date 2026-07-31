class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();

        vector<int> merge;
        for(int i = 0 ; i < a ; i++){
            merge.push_back(nums1[i]);
        }
        for(int i = 0 ; i < b ; i++){
            merge.push_back(nums2[i]);
        }
        sort(merge.begin(), merge.end());

        if (merge.size() % 2 == 0){
            int m1 = merge[merge.size() / 2];
            int m2 = merge[merge.size() / 2 - 1];

            return (float)(m1 + m2) / 2;
        }
        else{
            return (float)merge[merge.size() /2 ];
        }
    }
};