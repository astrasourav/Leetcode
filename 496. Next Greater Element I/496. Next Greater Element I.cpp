//Brute force code when 2 vectors are given
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int k = nums2.size();

        vector<int> ans(n, -1);

        for (int i = 0; i<n; i++) {
            int val = nums1[i];
            for (int j=0; j<k; j++) {
                if (val == nums2[j]) {
                    for (int b = j+1; b<k; b++) {
                        if (nums2[b] > val) {
                            ans[i] = nums2[b];
                            break;
                        }
                    }break;
                }
            }
        }
        return ans;
    }
};

//optimal code when 2 vectors are given
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int k = nums2.size();

        // Map to store the next greater element for each element in nums2
        unordered_map<int, int> nextGreaterMap;
        stack<int> s; // Stack to store elements for which we haven't found the next greater

        // Iterate over nums2 to find the next greater element for each
        for (int i = 0; i < k; i++) {
            while (!s.empty() && s.top() < nums2[i]) {
                nextGreaterMap[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        // Elements left in the stack do not have a next greater element
        while (!s.empty()) {
            nextGreaterMap[s.top()] = -1;
            s.pop();
        }

        // Prepare the answer for nums1 using the nextGreaterMap
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nextGreaterMap[nums1[i]];
        }

        return ans;
    }
};

//optimal soluton  when 1 vector is given
#include <bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	// Write your code here
	if (arr.empty()){
		return {};
	}

	vector<int> ans(n, -1);
	stack<int> st;

	for (int i=n-1; i>=0; i--) {

		while (!st.empty() && st.top() <= arr[i]) {
			st.pop();
		}

		if (!st.empty())  {
			ans[i] = st.top();
		}

		st.push(arr[i]);
	}

	return ans;
}
