/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int index = -1;
    vector<NestedInteger> nestedList;
    vector<int> flattened;

    NestedIterator(vector<NestedInteger> &nestedList) {
        flattened = dfs(nestedList, 0);
    }

    vector<int> dfs(vector<NestedInteger> &nestedList, int i) {
        vector<int> flattenedParent;
        while (i < nestedList.size()) {
            if (nestedList[i].isInteger()) {
                flattenedParent.push_back(nestedList[i].getInteger());
            } else {
                vector<int> flattendChild = dfs(nestedList[i].getList(), 0);
                for (int n: flattendChild) flattenedParent.push_back(n);
            }
            i++;
        }
        return flattenedParent;
    }

    int next() {
        if (hasNext()) {
            index++;
            return flattened[index];
        } else {
            return -1;
        }
    }
    
    bool hasNext() {
        return index + 1 < flattened.size();
    }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
