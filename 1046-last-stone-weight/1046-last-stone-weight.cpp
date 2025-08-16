class Solution {
public:
    // Approach: Max Heap
    // Time: O(nlogn)
    // - push into max heap: n*logn
    // - destroying stones: for each time, there is at most 1 stone left (x < y). so this will run about O(n) in worst time.
    // Space: O(n)

    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while (pq.size() >= 2) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            // both stones are destroyed
            if (stone1 == stone2) continue;
            int new_stone = stone1 - stone2;
            pq.push(new_stone);
        }

        return pq.size() == 0 ? 0 : pq.top();
    }
};