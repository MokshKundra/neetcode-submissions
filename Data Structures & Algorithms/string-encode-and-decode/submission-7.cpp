class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs.size(); i++){
            ans=ans+to_string(strs[i].length())+";"+strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        int size=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==';'){
              size=stoi(temp);
              temp="";
              if(size==0){
                ans.push_back("");
              }
              continue;
            }
            temp=temp+s[i];
            size--;
            if(size==0){
                ans.push_back(temp);
                temp="";
            }
        }
        return ans;
    }
};
