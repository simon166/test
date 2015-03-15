#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s, int start) {
        int len = s.length();
        if(len- start <= 1)
            return 1;
        int gewei , shiwei;
        for(int i = start; (i < len-1); i++){
            shiwei= s[i] - '0';
            gewei = s[i + 1] - '0';
            if(shiwei * 10 + gewei <= 26)
                break;
        }
        if(shiwei * 10 + gewei > 26)
            return 1;
        else
            return numDecodings(s, start + 2) + numDecodings(s, start + 1);
    }

    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        else
            return numDecodings(s, 0);
    }
};

int main(){
    Solution s;
    cout << s.numDecodings("12") << endl;
    return 0;
}
