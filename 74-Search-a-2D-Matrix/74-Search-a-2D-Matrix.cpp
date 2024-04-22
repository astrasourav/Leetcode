class Solution {
public:
    int findrow(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (matrix[mid][0] <= target && target <= matrix[mid][matrix[0].size() -1]){
                return mid;
            } else if (matrix[mid][0] < target) {
                low = mid+1;
            } else {
                high = mid -1;
            }
        }
        return -1;
    }

    bool findElement(int rowId, vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix[rowId].size() -1;

        while (low <= high) {
            int mid = low +(high - low)/2;

            if (matrix[rowId][mid] == target) {
                return true;
            } else if (matrix[rowId][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowid = findrow(matrix, target);
        if (rowid != -1) {
            return findElement(rowid, matrix, target);
        }
        return false;
    }
};
