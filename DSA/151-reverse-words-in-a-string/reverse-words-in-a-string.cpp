class Solution {
public:
    string reverseWords(string s) {
        stack<string> st; 
        string str = "";
        int start =0;
        for(int i=0;i<s.size();i++){
           if(s[i] == ' '){
            if ( str != "") st.push(str);
            str = "";
           }
           else{
            str += s[i];
           }
        }
        if(str != "") {
            st.push(str);
        } 
        str = "";
        while(st.size()>1){
            string ss = st.top();
            st.pop();
            str += ss;
            str += ' ';
        }
        string ss = st.top();
            st.pop();
             str += ss;


        return str;
        
    }
};