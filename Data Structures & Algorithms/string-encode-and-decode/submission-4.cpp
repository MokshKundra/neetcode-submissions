class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string ans=strs[0];
        for(int i=1; i<strs.size(); i++){
            ans = ans + ";" + strs[i];
        }
        ans = ans + ";";
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        for(int i=0; i<s.length(); i++){
            if(s[i]==';'){
                ans.push_back(temp);
                temp="";
            }
            else{
                temp=temp+s[i];
            }
        }
        return ans;
    }
};
