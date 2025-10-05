class Solution {
public:
    int isPrime(int val) {
        for (int i = 2; i <= (int)sqrt(val); i++) {
            if (val % i == 0) return false;    
        }
        return true;
    }
    
    int smallestValue(int n) {
        unordered_set<int> primesInN;
        for (int d = 2; d <= n; d++) {
            if (isPrime(d)) primesInN.insert(d);
        }
    
        while (n > 2) {
            int m = n;
            unordered_map<int,int> primeCnt;
            while (m > 1) {
                bool found = false;
                int d = 2;
                while (d <= m) {
                    if (primesInN.count(d)) {
                        while (m % d == 0) {
                            found = true;
                            primeCnt[d]++;
                            m /= d;
                        }
                    }
                    if (m == 1) break;
                    d++;
                }
                if (!found) break;
            }

            if (primeCnt.size() == 0) break;

            int newN = 0;
            for (auto [val, cnt]: primeCnt) {
                newN += val * cnt;
            }
            if (newN == n) break;
            n = newN;
        }
        return n;        
    }
};