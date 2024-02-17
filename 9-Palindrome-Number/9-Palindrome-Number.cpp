//First method is by converting the interer data into string and then using two pointer pproach to solve this.

class Solution {
public:
    bool isPalindrome(int x) {
        string data = to_string(x);

        int i=0, j=data.size()-1;

        while (i<=j) {
            if (data[i] != data[j]) {
                return false;
            } 
            i++;j--;
        }

        return true;
    }
};


//Second solution is by just directly reversing the entire digit .
//Just makae sure to use long long instead of int because we have to take extra care for nrgative values.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed=0;
        long long temp=x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};
