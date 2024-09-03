vector<int> Solution::prevSmaller(vector<int> &A) {
    if (A.empty()) {
        return {};
    }

    int n = A.size();
    vector<int> ans(n, -1); // Initialize result array with -1
    stack<int> st; // Stack to store potential previous smaller elements

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack that are greater than or equal to the current element
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the previous smaller element
        if (!st.empty()) {
            ans[i] = st.top();
        }

        // Push the current element to the stack
        st.push(A[i]);
    }

    return ans;
}

