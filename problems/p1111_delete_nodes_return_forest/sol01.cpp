/*
*
*/

#include <iostream>
#include <string>
#include <SimpleTest.h>
#include <map>
#include <stack>
#include <cassert>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    void delNode(TreeNode* node, int to_delete) {
        if (node == nullptr)
            return;
        if (node->val == to_delete) {
            node->val = 0;
            return;
        } else {
            delNode(node->left, to_delete);
            delNode(node->right, to_delete);
        }
    }

    void backTravel(TreeNode* node, TreeNode* parent, int branch, vector<TreeNode*>& sub_roots) {
        if (node == nullptr)
            return;
        backTravel(node->left, node, 0, sub_roots);
        backTravel(node->right, node, 1, sub_roots);

        if (node->val == 0) {
            if (node->left != nullptr)
                sub_roots.push_back(node->left);
            if (node->right != nullptr)
                sub_roots.push_back(node->right);

            if (parent && branch == 0)
                parent->left = nullptr;
            if (parent && branch == 1)
                parent->right = nullptr;
            node->left = nullptr;
            node->right = nullptr;
            delete node;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        for (int i = 0; i < to_delete.size(); i++) {
            delNode(root, to_delete[i]);
        }
        if (root->val != 0)
            forest.push_back(root);

        backTravel(root, nullptr, 0, forest);
        return forest;
    }
};

void printTree(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        cout << q.front()->val << ", ";
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
}

void printForest(vector<TreeNode*> forest) {
    cout << "[";
    for (TreeNode* root: forest) {
        cout << "[";
        printTree(root);
        cout << "]";
    }
    cout << "]";
}

int main()
{
    Solution s;
    {
        TreeNode* root = new TreeNode {
            1,
            new TreeNode {
                2,
                new TreeNode {
                    4,
                    nullptr,
                    nullptr
                },
                new TreeNode {
                    3,
                    nullptr,
                    nullptr
                }
            },
            nullptr
        };
        vector<TreeNode*> forest = s.delNodes(root, vector<int> {2, 3});
        printForest(forest);
    }
    
    
    printf("\n");
    return 0;
}
