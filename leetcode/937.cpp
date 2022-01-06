class Solution {
public:
    
    static bool mycmp (const string& a, const string& b) {
        auto pos_a = a.find(" ");
        auto pos_b = b.find(" ");
        
        string id_a = a.substr(pos_a+1, a.length()-pos_a+1);
        string id_b = b.substr(pos_b+1, b.length()-pos_b+1);
        
        string aa = a.substr(0, pos_a+1);
        string bb = b.substr(0, pos_b+1);
        
        if ('a' <= id_a[0] && id_a[0] <= 'z') {
            if ('a' <= id_b[0] && id_b[0] <= 'z') {
                if (id_a == id_b) {
                    return aa < bb; 
                } else {
                    return id_a < id_b;
                }
            } else {
                return true;
            }
        } else {
            if ('a' <= id_b[0] && id_b[0] <= 'z') {
                return false; 
            } else {
                return true;
            }
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dig;
        vector<string> let;
        for (auto s : logs) {
            if ('a' <= s.back() && s.back() <= 'z') 
                let.push_back(s);
            else 
                dig.push_back(s);
        }
        sort(let.begin(), let.end(), mycmp);
        
        for (auto s : dig) {
            let.push_back(s); 
        }
        
        
        return let;
    }
};
