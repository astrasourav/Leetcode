class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftPara, astrix;

        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(') {
                leftPara.push(i);
            } else if (s[i] == '*') {
                astrix.push(i);
            } else {
                if (!leftPara.empty()) {
                    leftPara.pop();
                } else if (!astrix.empty()){
                    astrix.pop(); 
                } else {
                    return false;
                }
            }
        }
        
        while (!leftPara.empty()) {
            if (astrix.empty()) {
                return false;
            }

            if (astrix.top() > leftPara.top()) {
                leftPara.pop();
                astrix.pop();
            } else {
                return false;
            }
        }

        return true;
    }
};
