class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> st;

        string curr = "";
        int k = 0;

        for(int i = 0; i < s.size(); i++) {

            if(isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
            }

            else if(s[i] == '[') {
                num.push(k);
                st.push(curr);

                k = 0;
                curr = "";
            }

            else if(s[i] == ']') {
                int count = num.top();
                num.pop();

                string prev = st.top();
                st.pop();

                string temp = "";

                for(int j = 0; j < count; j++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            else {
                curr += s[i];
            }
        }

        return curr;
    }
};