//Tc - O(N)
//sc - O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);

        left[0] = 1;
        for (int i=1; i<n; i++) {
            left[i] = left[i -1] * nums[i -1];
        }

        right[n -1] = 1;
        for (int i=n-2; i>=0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }

        vector<int>ans(n);
        for (int i=0;i<n; i++) {
            ans[i] = left[i] * right[i];
        } 

        return ans;
    }
};
//--------------------------------------------------------------------------
//Tc - O(N)
//sc - O(1)
//Solution to the follow-up question which is asked in this question.

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return {};

        int n = nums.size();
        vector<int> ans(n, 1);

        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};

//-----------------------------------------------------------------------

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;
        

        for (int i=1; i <n; i++) {
            ans[i] = ans[i -1] * nums[i- 1];
        }

        int r = 1;
        for (int i= n-1; i>=0; i--) {
            ans[i] *= r;
            r *= nums[i];
        }

        return ans;
    }
};

