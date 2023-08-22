class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        while(num > 0){
            num--;
            int digit = num % 26;
            ans += digit + 'A';
            num = num / 26;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};