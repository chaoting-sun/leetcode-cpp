/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// class Solution {
// public:
//     NestedInteger deserialize(string s) {
//         if (s.empty()) return NestedInteger();
//         if (s[0] != '[') return NestedInteger(stoi(s));

//         stack<NestedInteger> stk;
//         int i = 0;
//         while (i < s.size()) {
//             if (s[i] == '[') {
//                 stk.push(NestedInteger());
//                 i++;
//             } else if (s[i] == ']') {
//                 NestedInteger finished = stk.top();
//                 stk.pop();
//                 if (stk.empty()) {
//                     stk.push(finished);
//                 } else {
//                     stk.top().add(finished);
//                 }
//                 i++;
//             } else if (s[i] == ',') {
//                 i++;
//             } else {
//                 // digit
//                 int j = i;
//                 if (s[j] == '-') j++;
//                 while (j < s.size() -  1 && isdigit(s[j + 1])) {
//                     j++;
//                 }
//                 int num = stoi(s.substr(i, j - i + 1));
//                 stk.top().add(NestedInteger(num));
//                 i = j + 1;
//             }
//         }

//         return stk.top();
//     }
// };

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        // Edge case: 若字串不以 '[' 開頭，代表這只是一個單純的數字，非 List
        if (s[0] != '[') return NestedInteger(stoi(s));

        int index = 0;
        return dfs(s, index);
    }

    // 使用 Reference 傳遞 index，確保全域進度一致
    NestedInteger dfs(string &s, int &index) {
        NestedInteger res; // 建立當前層的空容器
        
        // 確保當前指向的是 '['，並移動到下一個字元
        if (index < s.size() && s[index] == '[') {
            index++; 
        }

        while (index < s.size()) {
            if (s[index] == ']') {
                // 遇到結尾括號，消耗它並回傳當前層結果
                index++; 
                return res;
            } else if (s[index] == ',') {
                // 跳過分隔符
                index++;
            } else if (s[index] == '[') {
                // 遇到巢狀結構，遞迴呼叫，並將結果加入當前層
                res.add(dfs(s, index));
            } else {
                // 處理數字
                int j = index;
                if (s[j] == '-') j++; // 處理負號
                while (j < s.size() && isdigit(s[j])) {
                    j++;
                }
                int num = stoi(s.substr(index, j - index));
                res.add(NestedInteger(num));
                
                index = j; // 更新全域索引
            }
        }
        
        return res;
    }
};