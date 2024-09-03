#include <bits/stdc++.h>
using namespace std;

void sortedStack(stack<int>& st, int x) {
	if (st.empty() || x > st.top()) {
		st.push(x);
	} else  {
		int tmp = st.top();
		st.pop();
// 		st.push(x);
        sortedStack(st, x);
		st.push(tmp);
	}
}


void stackSort(stack<int>&  st) {
	if (st.empty()) {
		return;
	}

	int x = st.top();
	st.pop();
	stackSort(st);
	sortedStack(st, x);
}


void printStack(stack<int> st) {
	while (!st.empty()) {
		cout<<st.top()<<" ";
		st.pop();
	}

}
int main()
{
	stack<int> st;
	st.push(5);
	st.push(-2);
	st.push(9);
	st.push(-7);
	st.push(3);

	cout<<"original stack"<<endl;
	printStack(st);
    cout<<endl;
	stackSort(st);
    cout<<endl;
	cout<<"sorted stack"<<endl;
	printStack(st);
}
