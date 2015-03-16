#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(s.length() == 0)
            return 0;
        int times[len+1];
        times[len] = 1;
        if(s[len-1] == '0')
            times[len-1] = 0;
        else 
            times[len-1] = 1;
        int shiwei, gewei;
        for(int i = len - 2; i >= 0; i--){
            shiwei = s[i] - '0';
            gewei = s[i+1] - '0';
            if(shiwei == 0)
                times[i] = 0;
            else if((shiwei * 10 + gewei == 10) ||( shiwei * 10 + gewei == 20))
                times[i] = times[i+2];
            else if(shiwei * 10 + gewei > 26)
                times[i] = times[i+1];
            else
                times[i] = times[i+2] + times[i+1];
        }
        return times[0];
    }
};

int main(){
    Solution s;
    cout << s.numDecodings("10") << endl;
    return 0;
}
