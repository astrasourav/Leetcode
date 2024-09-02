struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        // Step 1: Sort the jobs based on profit in descending order
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });

        // Step 2: Find the maximum deadline to define the number of slots
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > maxDeadline) {
                maxDeadline = arr[i].dead;
            }
        }

        // Step 3: Initialize a time slot array to keep track of free slots
        vector<int> slots(maxDeadline + 1, -1); // Using -1 to indicate a free slot

        int countJobs = 0;  // Number of jobs scheduled
        int maxProfit = 0;  // Total profit from scheduled jobs

        // Step 4: Iterate through sorted jobs and schedule them
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from the last possible slot)
            for (int j = arr[i].dead; j > 0; j--) {
                if (slots[j] == -1) {  // If the slot is free
                    slots[j] = arr[i].id; // Assign this job to the slot
                    countJobs++;          // Increment count of jobs
                    maxProfit += arr[i].profit; // Add profit
                    break; // Break the loop after assigning the job
                }
            }
        }

        // Step 5: Return the result
        return {countJobs, maxProfit};
        
    } 
};
