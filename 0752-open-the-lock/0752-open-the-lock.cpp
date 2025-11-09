class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsLookup;
        for (auto& deadend: deadends) {
            deadendsLookup.insert(deadend);
        }

        string start = "0000";
        queue<string> q;
        unordered_set<string> visited;

        if (deadendsLookup.count(start)) return -1;

        q.push(start);
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string s = q.front();
                q.pop();
                if (s == target) return time;

                for (int j = 0; j < 4; j++) {
                    string nextS = s;
                    nextS[j] = (nextS[j] - '0' + 1) % 10 + '0';
                    if (!deadendsLookup.count(nextS) && !visited.count(nextS)) {
                        q.push(nextS);
                        visited.insert(nextS);
                    }

                    string prevS = s;
                    prevS[j] = (prevS[j] - '0' + 9) % 10 + '0';
                    if (!deadendsLookup.count(prevS) && !visited.count(prevS)) {
                        q.push(prevS);
                        visited.insert(prevS);
                    } 
                }
            }
            time++;
        }
        return -1;
    }
};