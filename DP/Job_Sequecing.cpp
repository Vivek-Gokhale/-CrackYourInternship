// #include <bits/stdc++.h>
// using namespace std;
// class Solution 
// {
//     public:
//     int maxProfit, count;
//     unordered_map<string, pair<int, int>> memo;

//     // Helper function for finding the maximum profit with memoization
//     pair<int, int> Helper(Job arr[], int idx, int n, vector<bool>& slots, int profit, int cnt)
//     {
//         if (idx >= n)
//         {
//             return {cnt, profit};
//         }
        
//         string key = to_string(idx) + "-" + to_string(profit) + "-" + to_string(cnt) + "-" + to_string(slots.size());
//         if (memo.find(key) != memo.end())
//         {
//             return memo[key];
//         }

//         pair<int, int> best = {cnt, profit};

//         // Try to schedule the job in its slot or before
//         for (int t = min(n, arr[idx].dead) - 1; t >= 0; t--)
//         {
//             if (!slots[t])
//             {
//                 slots[t] = true;
//                 pair<int, int> result = Helper(arr, idx + 1, n, slots, profit + arr[idx].profit, cnt + 1);
//                 if (result.second > best.second)
//                 {
//                     best = result;
//                 }
//                 slots[t] = false; // backtrack
//             }
//         }

//         // Skip the current job
//         pair<int, int> result = Helper(arr, idx + 1, n, slots, profit, cnt);
//         if (result.second > best.second)
//         {
//             best = result;
//         }

//         return memo[key] = best;
//     }

//     // Comparator function to sort jobs according to profit in descending order
//     static bool comparison(Job a, Job b)
//     {
//         return a.profit > b.profit;
//     }

//     // Function to find the maximum profit and the number of jobs done
//     vector<int> JobScheduling(Job arr[], int n) 
//     { 
//         // Sort jobs in decreasing order of profit
//         sort(arr, arr + n, comparison);
        
//         // Initialize the maxProfit and count of jobs
//         maxProfit = 0;
//         count = 0;

//         // Create a boolean array to keep track of free time slots
//         vector<bool> slots(n, false);

//         // Call the helper function to calculate maxProfit and count of jobs done
//         pair<int, int> result = Helper(arr, 0, n, slots, 0, 0);
//         count = result.first;
//         maxProfit = result.second;

//         return {count, maxProfit};
//     } 
// };
