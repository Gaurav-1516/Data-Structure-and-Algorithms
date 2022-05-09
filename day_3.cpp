/* Implement StrStr() */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) return 0;
        
        for(int i = 0 ; i <= n-m ; i++){
            int j = 0;
            for(; j < m ; j++){
                if(haystack[i+j] == needle[j]) continue;
                else break;
            }
            if(j == m) return i;
        }
        return -1;
    }
};

/* Longest Commom Prefix */
class Solution {
public:
    string commPrefix(string ans, string s){
        string res = "";
        int n = ans.size();
        int m = s.size();
        for(int i = 0 ; i < n ; i++){
            if(i >= m) break;
            if(ans[i] == s[i]) res += ans[i];
            else break;
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        // Considering the first string as the prefix;
        string ans = strs[0];
        int n = strs.size();
        for(int i = 1; i < n ; i++){
            ans = commPrefix(ans,strs[i]);
        }
        return ans;
    }
};


/* Valid Palindrome - 2 */
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() -1;
        while(i <= j){
            if(s[i] != s[j]){
                // In first step we are skipping 1st and in other we are skipping 2nd;
                return (check(s,i+1,j) || check(s,i,j-1));
            }
            i++;
            j--;
        }
        return true;
    }
private:
    bool check(string &s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
}
};

/* Excel Sheet Column Title */
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0){
            n -= 1;
            char temp;
            temp = 'A' + n % 26;
            ans = temp + ans;
            n /= 26;
        }
        return ans;
    }
};

/* Palindrome Number */
class Solution {
public:
    
    bool isPalindrome(int x) {
        // string original = to_string(x);
        // string reversed = original;
        // reverse(reversed.begin(),reversed.end());
        // return (original == reversed);
        if(x < 0 || (x!=0 && x%10==0)) return false;
        int rev = 0;
        while (rev < x){
            rev = rev*10 + x%10;
            x /= 10;
        }
        return (rev==x || rev/10==x);
        
    }
};

/* Missing Number */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int res=0;
        for(; i < n; i++){
            res = res^(nums[i]^i);
        }
        return res^i;
    }
};