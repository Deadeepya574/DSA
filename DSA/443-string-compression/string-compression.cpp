class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        int end = 0;
        int count = 0;
        int mc = 0;

        while(end < chars.size()) {
            if(chars[end] == chars[start]) {
                count++;
                end++;
            }
            else {
                chars[mc++] = chars[start];

                if(count > 1) {
                    string num = to_string(count);

                    for(char c : num) {
                        chars[mc++] = c;
                    }
                }

                start = end;
                count = 0;
            }
        }
 
        chars[mc++] = chars[start];

        if(count > 1) {
            string num = to_string(count);

            for(char c : num) {
                chars[mc++] = c;
            }
        }

        return mc;
    }
};