class Solution {
vector<vector<int>> dir;
vector<int> scores;
public:
    int longest(int pos) {
        if (scores[pos] > 0) return scores[pos];
        scores[pos] = 1;
        for (int i : dir[pos]) {
            scores[pos] = max(scores[pos], longest(i) + 1);
        }
        return scores[pos];
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        dir.clear();
        dir.resize(n);
        scores.clear();
        scores.resize(n);
        unordered_map<string, int> positionMap;
        for (int i = 0; i < n; i++) {
            positionMap[words[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            string& cur = words[i];
            for (int j = 0; j < cur.length(); j++) {
                string target = cur.substr(0, j) + cur.substr(j+1);
                auto it = positionMap.find(target);
                if (it == positionMap.end()) continue;
                dir[it->second].push_back(i);
            }
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, longest(i));
        }
        return result;
    }
};
