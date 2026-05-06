class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char &itr: s){
            itr = tolower(itr);
            if(isalnum(itr) || itr == '_'){
                temp += itr;
            }
        }
        string temp2(temp.begin(), temp.end());
        reverse(temp2.begin(), temp2.end());

        for(int i = 0; i < temp.length(); i++){
            if(temp[i] != temp2[i]){
                return false;
            }
        }
        return true;
    }
};
