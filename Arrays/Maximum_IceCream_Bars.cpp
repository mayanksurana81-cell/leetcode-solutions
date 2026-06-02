 /*
Category: Arrays, Greedy, Counting Sort

Approach:
- Count the frequency of each ice cream cost using a frequency array.
- Traverse costs in increasing order of price.
- For each cost:
  - Buy as many ice creams as possible while sufficient coins remain.
  - Decrease the frequency and available coins accordingly.
- Processing costs from smallest to largest ensures the maximum number of ice creams can be purchased.

Time Complexity: O(n + m)
Space Complexity: O(m)

Where m is the maximum cost value in the array.
 */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int maxelement = *max_element(costs.begin() , costs.end());
        vector<int> freq(maxelement+1);
        for(int ele : costs) freq[ele]++;
        int count = 0;
        for(int i = 0 ; i<freq.size() ; i++){
            while(freq[i] > 0 && coins >= i){
                freq[i]--;
                count++;
                coins -= i;
            }
        }
        return count;
    }
};