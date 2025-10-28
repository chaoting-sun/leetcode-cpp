class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        if (money > children * 8) return children - 1;
        int leftMoney = money - children;
        int numEights = leftMoney / 7;
        int leftChildren = children - numEights;
        if (leftMoney - numEights * 7 == 3 && leftChildren == 1) {
            return numEights - 1;
        } else {
            return numEights;
        }
    }
};

// money < children -> -1

// money / 8 = 0 -> 0
//             k -> money % 8 >= n - k

// 8k + (n-k) * 1 <= money
// n + 7k <= money
// k <= (money - n) / 7