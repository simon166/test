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
    int allSum;
public:
    void numbers(TreeNode *p, int array[], int d){
        array[d] = p->val;
        if(p->left != NULL)
            numbers(p->left, array, d+1);
        if(p->right != NULL)
            numbers(p->right, array, d+1);
        if(p->left == NULL && p->right == NULL){
            int sum = 0;
            for(int i = 0; i <= d; i++)
                sum = sum*10 + array[i];
            allSum += sum;
        }
    }
    int sumNumbers(TreeNode *root) {
        if(root == NULL)
            return 0;
        int array[100];
        int d = 0;
        allSum = 0;
        numbers(root, array, d);
        cout << allSum << endl;
        return allSum;
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
   s.sumNumbers(&n4);
    //cout << s.numDecodings("12") << endl;
    return 0;
}
