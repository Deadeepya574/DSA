class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &p : points) {
            int dist = p[0] * p[0] + p[1] * p[1];

            pq.push({dist, {p[0], p[1]}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            res.push_back({curr.second.first, curr.second.second});
        }

        return res;
    }
};