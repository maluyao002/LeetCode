class Solution {
    unordered_map<string, int> longestPerWord;
    unordered_map<int, set<string>> lenMap;
public:
    int longestStrChain(vector<string>& words) {
        int result = 1;
        
        for (string c : words) {
            int len = c.length();
            lenMap[len].insert(c);
        }
        
        for (string word : words) {
            result = max(result, longestForWord(word));
        }
        return result;
    }
    
    int longestForWord(const string& word) {
        if (longestPerWord.find(word) != longestPerWord.end()) return longestPerWord[word];
        
        longestPerWord[word] = 1;
        int len = word.length();
        if (len > 1 && lenMap.find(len-1) != lenMap.end()) {
            for (string target : lenMap.find(len-1)->second) {
                if (isPredecessor(word, target)) {
                    longestPerWord[word] = max(longestPerWord[word], longestForWord(target) + 1);
                }
            }
        }
        return longestPerWord[word];
    }
    
    bool isPredecessor(const string &cur, const string &prev) {
        for (auto i = 0, j = 0; i < prev.size(); ++j) {
            if (prev[i] == cur[j]) ++i;
            if (j - i == 2) return false;
        }
        return true;
    }
};
