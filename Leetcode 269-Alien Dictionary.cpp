//faster than 58%

class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        auto cmp = [](char& a, char& b) {
            return a > b;
        };
        
        set<pair<char, char>> st;
        unordered_set<char> ch;
        vector<int> in(256, 0);
        priority_queue<char,vector<char>,decltype(cmp)> q(cmp);
        string res = "";
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    st.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (auto a : st) ++in[a.second];
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                //res += a;
            } 
        }
        while (!q.empty()) {
            char c = q.top(); q.pop();
            res+=c;
            for (auto a : st) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                    }
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};