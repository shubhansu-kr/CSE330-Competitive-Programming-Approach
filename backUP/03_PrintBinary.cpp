// Print Binary tree levels in sorted form

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public: 
    void traverse(TreeNode *root, vector<vector<int>> &tree, int level) {
        if (!root) return;

        if (level >= tree.size()) {
            tree.push_back(vector<int>(1, root->val));
        }
        else {
            tree[level].emplace_back(root->val);
        }

        traverse(root->left, tree, level+1);
        traverse(root->right, tree, level+1);
    }

    void printSortedLeve(TreeNode *root) {
        vector<vector<int>> tree;
        traverse(root, tree, 0);

        int n = tree.size();
        for(int i = 0; i < n; ++i) {
            sort(tree[i].begin(), tree[i].end());
            for(int j = 0; j < tree[i].size(); ++j) {
                cout << tree[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main () {
    
    return 0;
}