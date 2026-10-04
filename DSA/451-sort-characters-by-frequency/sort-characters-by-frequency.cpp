class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            ans += string(curr.first, curr.second);
        }

        return ans;
    }
};