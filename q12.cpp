/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#define Node TreeNode
int sum =0;
    pair<pair<int,int>,int> check(Node* root){
        if(root==NULL) return {{INT_MAX,INT_MIN},0};
        //minNode,maxNode,maxSum
        
        pair<pair<int,int>,int> l = check(root->left);
        pair<pair<int,int>,int> r = check(root->right);
    
        
        if(l.first.second<root->val && r.first.first>root->val){
        sum = max(sum,l.second+r.second+root->val);
        //sum can reduces because of negative root value
        return {{min(l.first.first,root->val),max(root->val,r.first.second)},l.second+r.second+root->val};
        }

        return {{INT_MIN,INT_MAX},max(r.second,l.second)};
    }
    int maxSumBST(TreeNode* root) {
        pair<pair<int,int>,int> ans  = check(root);
        if(sum<0) return 0;
        return sum;
    }
};