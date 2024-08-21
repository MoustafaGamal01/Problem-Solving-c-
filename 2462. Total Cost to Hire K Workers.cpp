class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res(0); 
        int x(costs.size());

        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        
        for (int i = 0; i < candidates; i++) {
            pq1.push(costs[i]);

            if (i < x - candidates)
                pq2.push(costs[x - i - 1]); 
        }
        
        int l(candidates - 1), r(x - candidates); 
         
        while (k--) {
            if (pq1.empty() || (pq2.size() && pq2.top() < pq1.top())) {
                res += pq2.top(); 
                pq2.pop(); 
                
                if (--r > l)  pq2.push(costs[r]); 
            } else {
                res += pq1.top(); 
                pq1.pop(); 

                if (++l < r)  pq1.push(costs[l]); 
            }
        }
        
        return res; 
    }
};