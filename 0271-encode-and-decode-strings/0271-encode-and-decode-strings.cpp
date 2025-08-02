class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_s = "";
        string combined_s = "";

        int n = strs.size();
        encoded_s = to_string(n) + ',';
        
        for (int i = 0; i < n; i++) {
            encoded_s += to_string(strs[i].size()) + ',';
            combined_s += strs[i];
        }
        return encoded_s + combined_s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int current = 0;
        while (s[current] != ',') current++;
        int n_vec = stoi(s.substr(0, current));

        vector<int> len_str;
        int cnt_vec = 0;
        current++;
        int tail = current;

        while (cnt_vec < n_vec) {
            while (s[tail] != ',') tail++;
            len_str.push_back(stoi(s.substr(current, tail)));
            tail += 1;
            current = tail;
            cnt_vec += 1;
        }

        vector<string> ans;
        for (int i = 0; i < n_vec; i++) {
            ans.push_back(s.substr(current, len_str[i]));
            current += len_str[i];
        }

        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));