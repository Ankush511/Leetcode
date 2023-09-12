class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};

        for(auto &ch : s){
            freq[ch - 'a']++;
        }

        unordered_set<int> st;
        int deletion = 0;

        for(int i=0; i<26; i++){
            while(freq[i] > 0 && st.find(freq[i]) != st.end()){
                freq[i]--;
                deletion++;
            }

            st.insert(freq[i]);
        }
        return deletion;
    }
};