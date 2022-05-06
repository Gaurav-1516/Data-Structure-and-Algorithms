/*** Chocolate distribution problem ***/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        int mindiff = INT_MAX;
        for(int i = 0; i <= n-m ; i++){
            if((a[i+m-1]-a[i]) < mindiff){
                mindiff = (a[i+m-1]-a[i]);
            }
        }
    
        return mindiff;
    }   
};

/* Two Sum */
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < n ; i++){
            if(mpp.find(target-arr[i]) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-arr[i]]);
                return ans;
            }
            mpp[arr[i]] = i;

        }
        return ans; 
    }
};


/* Best time to buy and sell stock - ii  */
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int pro = 0;
        int n = arr.size();
        for(int i = 1 ; i < n; i++){
            if(arr[i] > arr[i-1]){
                pro += (arr[i] - arr[i-1]);
            }
        }
        return pro;
    }
};


/* Valid Parenthesis */
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i = 0 ; i < n ; i++){
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                if(s[i] == ']'){
                    if((st.top() == '[')) st.pop();
                    else return false;
                }
                else if(s[i] == '}'){
                    if ((st.top() == '{')) st.pop();
                    else return false;

                }
                else if(s[i] == ')'){
                    if ((st.top() == '(')) st.pop();
                    else return false;
                }
                    
            }
        }
        return st.empty();
    }
};


/* Print duplicates */
void printDuplicates(string str)
{
    map<char, int> mpp;
    for (int i = 0; i < str.length(); i++) {
        mpp[str[i]]++;
    }
 
    for (auto it : mpp) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}