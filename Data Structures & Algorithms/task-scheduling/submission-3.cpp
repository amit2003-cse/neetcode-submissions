class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        // Step 1: Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Step 2: Find max frequency task
        int max_count = *max_element(freq.begin(), freq.end());
        
        // Step 3: Count number of tasks with max frequency
        int number_of_max = 0;
        for (int f : freq) {
            if (f == max_count) {
                number_of_max++;
            }
        }
        
        // Step 4: Calculate CPU cycles using formula
        int part1 = (max_count - 1) * (n + 1) + number_of_max;
        int part2 = tasks.size();
        
        return max(part1, part2);
    }
        
    
};
