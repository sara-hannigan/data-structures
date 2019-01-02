#include <iostream>
#include <string>
#include <vector>
#include <cstring>


using std::string;
using std::endl;
using std::cout;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

unsigned long long hash_func(const string& s) {
    static const unsigned long long multiplier = 1;
    static const unsigned long long prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = s.size() - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

unsigned long long * preComputeHashes (const string& t, size_t subSize, size_t tSize) {
    static const unsigned long long multiplier = 1;
    static const unsigned long long prime = 1000000007;
    size_t subArray = tSize - subSize;
    unsigned long long * preHash = new unsigned long long [tSize - subSize + 1];
    preHash[subArray] = hash_func (t.substr(tSize-subSize, tSize-1));
    unsigned long long y = 1;
    for (size_t i = 0; i <= subSize; i++) {
        y = (y * multiplier) % prime;
    }
    for (int i = (tSize - subSize - 1); i >= 0; --i) {
        preHash[i] = (multiplier * preHash[i+1]+ t[i] - y * t[i + subSize]) % prime;
    }
    return preHash;
}

bool areEqual (const string& s, const string& t) {
    if (s.compare(t) == 0) {
        return true;
    }
    return false;
    
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    signed long long substringHashVal = hash_func(s);
    //Take out substring
    unsigned long long subSize = s.size();
    unsigned long long stringSize = t.size();
    if (subSize > stringSize) {
        return ans;
    }
    if (subSize == stringSize) {
        if (areEqual(s, t)) {
            ans.push_back(0);
            return ans;
        }
    }
    unsigned long long * preHash = preComputeHashes(t, subSize, stringSize);
    //Precompute hashes + reverse iteration (might need to change vector to stack or something...)
    for (int i = 0; i <= stringSize-subSize; ++i) {
//        string tSubstring = t.substr(i, subSize);
//        unsigned long long stringPartHash = hash_func(tSubstring);
        if (substringHashVal != preHash[i]) {
            continue;
        }
        //        if (stringPartHash != substringHashVal) {
        //            continue;
        //        }
        if (t.compare(i, subSize, s) == 0) {
            ans.push_back(i);
        }
    }
    delete preHash;
    return ans;
    
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
