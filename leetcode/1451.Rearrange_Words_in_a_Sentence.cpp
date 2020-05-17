class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int , string> > a;
        int start = 0;
        for (int i = 0; i < text.size(); ++i) {
            if (text[i] == ' ') {
                a.push_back(make_pair(i-start, text.substr(start, i-start)));
                start = i+1;
            }
        }
        a.push_back(make_pair(text.size()-start, text.substr(start, text.size()-start)));
        stable_sort(a.begin(), a.end(),
          [] (const auto& a, const auto& b) {
                return a.first < b.first;
            });
        string ans;
        for (int i = 0; i < a.size(); ++i) {
            if (i == 0) {
                a[i].second[0] = toupper(a[i].second[0]);
                ans += a[i].second + " ";
            } else if (i == a.size()-1) {
                a[i].second[0] = tolower(a[i].second[0]);
                ans += a[i].second;
            } else {
                a[i].second[0] = tolower(a[i].second[0]);
                ans += a[i].second + " ";
            }
        }
        return ans ;
    }
};
