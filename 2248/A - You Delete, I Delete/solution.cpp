#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Function to find Bob's optimal minimizing response
string get_bob_best_response(const string& s_alice) {
    string min_str = "";
    bool first = true;
    
    for (size_t j = 0; j < s_alice.length(); ++j) {
        if (s_alice[j] == '1') {
            string s_bob = s_alice.substr(0, j) + s_alice.substr(j + 1);
            if (first || s_bob < min_str) {
                min_str = s_bob;
                first = false;
            }
        }
    }
    // If there were no '1's left for Bob to delete, return the string as is
    return first ? s_alice : min_str;
}
 
void solve() {
    string s;
    cin >> s;
    
    string best_final_str = "";
    bool first_alice = true;
    
    // Alice tries deleting every possible '0'
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            string s_alice = s.substr(0, i) + s.substr(i + 1);
            
            // Bob plays optimally against Alice's current choice
            string bob_outcome = get_bob_best_response(s_alice);
            
            // Alice maximizes her outcome
            if (first_alice || bob_outcome > best_final_str) {
                best_final_str = bob_outcome;
                first_alice = false;
            }
        }
    }
    
    cout << best_final_str << "
";
}
 
int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}