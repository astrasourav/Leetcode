// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
         sort(arr, arr + n, [](Item a, Item b) {
            double r1 = (double)a.value / a.weight;
            double r2 = (double)b.value / b.weight;
            return r1 > r2;
        });

        double maxValue = 0.0; // Variable to store the maximum value we can get
        int currentWeight = 0; // Current weight in knapsack

        // Step 2: Iterate through the sorted items and add them to the knapsack
        for (int i = 0; i < n; i++) {
            // If adding the whole item does not exceed capacity, add it fully
            if (currentWeight + arr[i].weight <= w) {
                currentWeight += arr[i].weight;
                maxValue += arr[i].value;
            } 
            // Otherwise, add the fraction of the remaining capacity
            else {
                int remainingWeight = w - currentWeight;
                maxValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
                break; // Knapsack is full now
            }
        }

        return maxValue;

    }
};
