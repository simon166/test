#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
     
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode *curLeft;
        bool isLeft;
        TreeLinkNode *preLeft = root;
        if(root->left != NULL){
            curLeft = root->left;
            isLeft = true;
        }
        else if(root->right != NULL){
            curLeft = root->right;
            isLeft = false;
        }
        else
            return;
        while(curLeft != NULL){
            TreeLinkNode *preP = preLeft;
            TreeLinkNode *curP = curLeft;
            TreeLinkNode *q = NULL;
            while(preP != NULL){
                q = NULL;
                if(isLeft){
                    q = preP->right;
                    if(q != NULL){
                        curP->next = q;
                        curP = curP->next;
                        isLeft = false;
                        continue;
                    }
                    preP = preP->next;
                }
                while(preP != NULL){
                    if(preP->next != NULL){
                        q = preP->next->left;
                        if(q != NULL)
                            break;
                    }
                    preP = preP->next;
                    q = preP->right;
                    if(q != NULL){
                        isLeft = false;
                        break;
                    }
                    
                }
                curP->next = q;
                curP = curP->next;
            }
            preLeft = curLeft;
            while(curLeft != NULL){
                if(curLeft->left != NULL){
                    curLeft = curLeft->left;
                    isLeft = true;
                    break;
                }
                else if(curLeft->right != NULL){
                    curLeft = curLeft->right;
                    isLeft = false;
                    break;
                }
                else
                    curLeft = curLeft->next;
            }
        }
    }
};

int main(){
    Solution s;
    struct TreeLinkNode n1(1);
    struct TreeLinkNode n2(2);
    struct TreeLinkNode n3(3);
    struct TreeLinkNode n4(4);
    struct TreeLinkNode n5(2);
    struct TreeLinkNode n6(3);
    struct TreeLinkNode n7(1);
//n1.left = &n2;
//n1.right = &n6;
//n2.left = &n3;
//n6.left = &n5;
    n2.left = &n1;
    n2.right = &n3;
    n4.left = &n2;
    n4.right = &n5;
    n5.left = &n6;
    n5.right = &n7;
    s.connect(&n4);
    //cout << s.numDecodings("12") << endl;
    return 0;
}
