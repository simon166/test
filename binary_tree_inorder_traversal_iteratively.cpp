#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<struct TreeNode*> nodes;
        struct TreeNode *p = root;
        while(p != NULL || !nodes.empty()){
            while(p != NULL){
                nodes.push(p);
                p = p->left;
            }
            if(!nodes.empty()){
                p = nodes.top();
                nodes.pop();
                result.push_back(p->val);
                cout << p->val <<" ";
                p = p->right;
            }
        } 
    }
};

int main(){
    Solution s;
    struct TreeNode n1(1);
    struct TreeNode n2(2);
    struct TreeNode n3(3);
    struct TreeNode n4(4);
    struct TreeNode n5(5);
    n2.left = &n1;
    n2.right = &n3;
    n4.left = &n2;
    n4.right = &n5;
   s.inorderTraversal(&n4);
    //cout << s.numDecodings("12") << endl;
    return 0;
}
