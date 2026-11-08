
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long first = root->val, second = LLONG_MAX;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;

            if (node->val > first)
                second = min(second, (long long)node->val);

            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return second == LLONG_MAX ? -1 : second;
    }
};
