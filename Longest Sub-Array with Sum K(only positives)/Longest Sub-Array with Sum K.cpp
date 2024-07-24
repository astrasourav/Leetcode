//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int left = 0;
        int right = 0;
        int sum = A[0];
        int len = 0;
        
        while (right < N) {
            while  (left <= right && sum > K) {
                sum -= A[left];
                left++;
            }
            if (sum == K) {
                len = max(len, right - left +1);
            }
            
            right++;
            if  (right < N) {
                sum+= A[right];
            }
        }
        
        return len;
    } 

};


