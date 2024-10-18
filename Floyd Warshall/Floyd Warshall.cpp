class Solution {
  public:
    void shortestDistance(vector<vector<int>>& matrix) {
        // Code here
        // finding the num of nodes.
	    int n = matrix.size();
	    
	    
	   // replacing the matirx element -1 to inf ,so that it is easy in floyd warshal.
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	        }
	    }
	    
	    for(int k = 0 ; k < n ; k++){
	        for(int i = 0 ; i < n ; i++){
	            for(int j =0 ; j< n; j++){
	                
	               // if(matrix[i][k] == 1e9 || matrix[k][j] == 1e9 )
	               //     continue;       // skip updating dist .
	                    
	                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	   // replacing non rechale back to -1.
	     for(int i = 0 ; i < n ; i++){
	       for(int j = 0 ; j < n ; j++){
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
    }
};