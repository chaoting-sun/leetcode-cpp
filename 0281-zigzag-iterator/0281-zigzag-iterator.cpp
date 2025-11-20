class ZigzagIterator {
public:
    int i, j, n1, n2;
    bool isV1;
    vector<int> v1, v2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i = 0;
        j = 0;
        n1 = v1.size();
        n2 = v2.size();
        isV1 = true;
        this->v1 = v1;
        this->v2 = v2;
    }

    int next() {   
        if (!hasNext()) return -1;
        int res = -1;
        if (isV1) {
            res = i < n1 ? v1[i++] : v2[j++];
        } else {
            res = j < n2 ? v2[j++] : v1[i++];
        }
        isV1 = !isV1;
        return res;
    }

    bool hasNext() {
        return i < n1 || j < n2;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */