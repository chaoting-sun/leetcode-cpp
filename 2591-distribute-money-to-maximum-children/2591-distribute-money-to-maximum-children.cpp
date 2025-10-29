class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        if (money > children * 8) return children - 1;
        
        int numEights = (money - children) / 7;
        int remainder = (money - children) % 7;
        
        // 特殊情況：剩餘1人且剩3元（會導致最後一人拿4元）
        if (numEights == children - 1 && remainder == 3) {
            return numEights - 1;
        }
        
        return numEights;
    }
};