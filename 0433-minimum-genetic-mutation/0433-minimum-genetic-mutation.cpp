class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> genes { 'A', 'C', 'G', 'T' };
        
        unordered_set<string> bankSet;
        for (string& b: bank) bankSet.insert(b);
        int geneLength = startGene.size();

        queue<string> q;
        q.push(startGene);
        bankSet.erase(startGene);

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string currGene = q.front();
                q.pop();
                if (currGene == endGene) return steps;

                string next = currGene;
                for (int i = 0; i < geneLength; i++) {
                    char org = next[i];
                    for (char gene: genes) {
                        if (org == gene) continue;
                        next[i] = gene;
                        if (!bankSet.count(next)) continue;
                        q.push(next);
                        bankSet.erase(next);
                    }
                    next[i] = org;
                }
            }
            steps++;
        }
        return -1;
    }
};