#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool searchArray(vector<vector<int>> array, int target) {
        
        vector<int> col;
        for (auto E : array) col.push_back(E.front());

        int n = col.size();

        auto binary_search = [&](int l, int r, int x) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (col[mid] <= x) l = mid + 1;
                else r = mid;
            }
            if (l == n || col[l] > x) l -- ;
            return l;
        };

        auto ed = binary_search(0, n, target);
        for (int i = 0; i <= ed; i ++ ) { auto &E = array[i];
            auto p = lower_bound(E.begin(), E.end(), target);
            if (p != E.end() && *p == target) return true;
        }
        return false;
    }
};