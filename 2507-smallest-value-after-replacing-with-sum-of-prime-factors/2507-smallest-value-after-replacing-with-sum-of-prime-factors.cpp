class Solution {
public:
    int isPrimeValue(int val) {
        for (int i = 2; i <= (int)sqrt(val); i++) {
            if (val % i == 0) return false;    
        }
        return true;
    }
    
    int smallestValue(int n) {
        while (n > 2) {
            int m = n;
            unordered_map<int,int> primeCnt;
            while (m > 1) {
                bool found = false;
                for (int d = 2; d < n; d++) {
                    bool isPrime = isPrimeValue(d);
                    while (m % d == 0 && isPrime) {
                        found = true;
                        primeCnt[d]++;
                        m /= d;
                    }
                    if (m == 1) break;
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