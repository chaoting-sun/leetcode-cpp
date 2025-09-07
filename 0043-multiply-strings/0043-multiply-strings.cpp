class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + res[i + j + 1];                
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans = "";
        int start = res[0] == 0 ? 1 : 0;
        for (int i = start; i < n1 + n2; i++) {
            ans.push_back(res[i] + '0');
        }
        return ans;
    }
};