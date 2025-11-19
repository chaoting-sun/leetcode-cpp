/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 * public:
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool isInteger() const;
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int getInteger() const;
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    // 使用 Stack 來暫存 NestedInteger，模擬 DFS
    stack<NestedInteger> stk;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // 初始化時，將最外層的列表倒序放入 Stack
        // 倒序是為了讓第一個元素位於 Stack 頂端 (LIFO)
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stk.push(nestedList[i]);
        }
    }

    int next() {
        // 題目保證呼叫 next() 之前 hasNext() 為 true
        // 但為了安全起見，通常可以先 check hasNext()
        // 這裡假設 hasNext() 已經確保了 stk.top() 是一個整數
        int result = stk.top().getInteger();
        stk.pop();
        return result;
    }
    
    bool hasNext() {
        // 核心邏輯：不斷拆解 Stack 頂端的列表，直到頂端是整數或 Stack 變空
        while (!stk.empty()) {
            NestedInteger current = stk.top();
            
            // Case 1: 頂端已經是整數，準備好可以被 next() 取用
            if (current.isInteger()) {
                return true;
            }
            
            // Case 2: 頂端是列表，需要拆解 (Flatten)
            stk.pop(); // 移除原本的列表包裝
            const vector<NestedInteger> &list = current.getList();
            
            // 將子列表的內容倒序推回 Stack
            for (int i = list.size() - 1; i >= 0; i--) {
                stk.push(list[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */