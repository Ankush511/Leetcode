typedef pair<int, char> P;
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26,0);
        for(auto &ch : s){
            freq[ch - 'a']++;

            if(freq[ch - 'a'] > (n+1)/2){
                return "";
            }
        }

        string ans = "";
        priority_queue<P, vector<P>> pq;

        for(char ch = 'a'; ch<='z'; ch++){
            if(freq[ch - 'a'] > 0){
                pq.push({freq[ch - 'a'], ch});
            }
        }
        
        while(pq.size() >= 2){
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second);
            p1.first--;
            ans.push_back(p2.second);
            p2.first--;

            if(p1.first > 0){
                pq.push(p1);
            }
            if(p2.first > 0){
                pq.push(p2);
            }
        }

        if(!pq.empty()){
            ans.push_back(pq.top().second);
        }

        return ans;
    }
};