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
    vector<int> table;
    int distance;
    TreeNode* currNode;
    int no;
    int length;
    int count;

    void mark(TreeNode* node) {
        if (node->left == nullptr && node->right == nullptr) {
            no++;
            length++;
            if (currNode == nullptr) {
                length = 0;
            }
            table.push_back(length);
            length = 0;
            currNode = node;
            if (table.size() > 1) {
                int sum = 0;
                for (int i = no - 1; i >= 0; i--) {
                    sum += table[i];
                    if (sum <= distance) {
                        count++;
                        break;
                    }
                }
            }
            return;
        } else {
            if (currNode && (node->left || node->right)) {
                length++;
            }
        }

        if (node->left) {
            mark(node->left);
            if (currNode && (node->left || node->right)) {
                length++;
            }
        }
        if (node->right) {
            mark(node->right);
            if (currNode && (node->left || node->right)) {
                length++;
            }
        }
    }

    vector<int> travel(TreeNode* node) {
        vector<int> cv;
        if (node->left == nullptr && node->right == nullptr) {
            cv.push_back(0);
            return cv;
        }

        vector<int> clq;
        vector<int> crq;
        if (node->left) {
            vector<int> v = travel(node->left);
            for (int i = 0; i < v.size(); i++) {
                clq.push_back(v[i] + 1);
                cv.push_back(v[i] + 1);
            }
        }
        if (node->right) {
            vector<int> v = travel(node->right);
            for (int i = 0; i < v.size(); i++) {
                crq.push_back(v[i] + 1);
                cv.push_back(v[i] + 1);
            }
            
        }

        if (node->left && node->right) {
            for (int i = 0; i < clq.size(); i++) {
                int v1 = clq[i];
                if (v1 > distance) continue;
                for (int j = 0; j < crq.size(); j++) {
                    int v2 = crq[j];
                    int path = v1 + v2;
                    if (path > distance)
                        continue;
                    count++;
                }
            }
        }

        return cv;
    }

    int countPairs(TreeNode* root, int distance) {
        this->table = vector<int>();
        this->distance = distance;
        this->currNode = nullptr;
        this->no = 0;
        this->length = 0;
        this->count = 0;
        travel(root);
        return this->count;
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
            78,
            new TreeNode {
                15,
                new TreeNode {
                    73,
                    new TreeNode {
                        30, nullptr, nullptr
                    },
                    nullptr
                },
                new TreeNode {
                    98,
                    new TreeNode {
                        63, nullptr, nullptr
                    },
                    new TreeNode {
                        32, nullptr, nullptr
                    }
                }
            },
            new TreeNode {
                81,
                new TreeNode {
                    36, nullptr, nullptr
                },
                nullptr
            }
        };
        int num = s.countPairs(root, 6);
        cout << num << endl;
    }
    {
        TreeNode* root = new TreeNode {
            1,
            new TreeNode {
                2,
                nullptr,
                new TreeNode {
                    4,
                    nullptr,
                    nullptr
                }
            },
            new TreeNode {
                3,
                nullptr,
                nullptr
            }
        };
        int num = s.countPairs(root, 3);
        cout << num << endl;
    }
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
                    5,
                    nullptr,
                    nullptr
                }
            },
            new TreeNode {
                3,
                new TreeNode {
                    6,
                    nullptr,
                    nullptr
                },
                new TreeNode {
                    7,
                    nullptr,
                    nullptr
                }
            }
        };
        int num = s.countPairs(root, 3);
        cout << num << endl;
    }
    {
        TreeNode* root = new TreeNode {
            7,
            new TreeNode {
                1,
                new TreeNode {
                    6,
                    nullptr,
                    nullptr
                },
                nullptr
            },
            new TreeNode {
                4,
                new TreeNode {
                    5,
                    nullptr,
                    nullptr
                },
                new TreeNode {
                    3,
                    nullptr,
                    new TreeNode {
                        2,
                        nullptr,
                        nullptr
                    }
                }
            }
        };
        int num = s.countPairs(root, 3);
        cout << num << endl;
    }
    {
        TreeNode* root = new TreeNode {
            15,
            new TreeNode {
                66,
                new TreeNode {
                    97,
                    nullptr,
                    new TreeNode {
                        54,
                        nullptr,
                        nullptr
                    }
                },
                new TreeNode {
                    60,
                    nullptr,
                    new TreeNode {
                        49,
                        nullptr,
                        new TreeNode {
                            90,
                            nullptr,
                            nullptr
                        }
                    },
                }
            },
            new TreeNode {
                55,
                new TreeNode {
                    12,
                    nullptr,
                    new TreeNode {
                        9,
                        nullptr,
                        nullptr
                    }
                },
                new TreeNode {
                    56,
                    nullptr,
                    nullptr
                }
            }
        };
        int num = s.countPairs(root, 5);
        cout << num << endl;
    }

    
    
    printf("\n");
    return 0;
}
