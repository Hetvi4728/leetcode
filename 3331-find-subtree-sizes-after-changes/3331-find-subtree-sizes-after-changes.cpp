class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> last[26];

        function<void(int, int)> dfs = [&](int node, int par) {
            int ch = s[node] - 'a';

            last[ch].push_back(node);

            for (int child : tree[node]) {
                dfs(child, node);
            }

            int newParent = par;

            if (last[ch].size() > 1) {
                newParent = last[ch][last[ch].size() - 2];
            }

            if (newParent != -1) {
                ans[newParent] += ans[node];
            }

            last[ch].pop_back();
        };

        dfs(0, -1);

        return ans;
    }
};