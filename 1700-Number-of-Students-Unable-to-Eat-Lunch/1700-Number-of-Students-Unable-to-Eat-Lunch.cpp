#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int arr[2] = {0};
        //arr[0] = count of student who like circular
        //arr[1] = count of student who like square
          
        for(int &x : students)
            arr[x]++;
        
        for(int i = 0; i<n; i++) {
            if(arr[sandwiches[i]] == 0) return n-i;
            arr[sandwiches[i]]--;
        }
        
        return 0;
    }
};
