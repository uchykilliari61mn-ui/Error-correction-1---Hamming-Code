#include <string>
#include <bitset>
using namespace std;

string encode(const string& text) {
    string result;
    for (unsigned char c : text) {
        string bits = bitset<8>(c).to_string();  // ASCII -> 8-бітний двійковий
        for (char b : bits)
            result += string(3, b);              // потроюємо кожен біт
    }
    return result;
}

string decode(const string& code) {
    string bits;
    // Кожна трійка -> біт за більшістю
    for (size_t i = 0; i < code.size(); i += 3) {
        int ones = (code[i] == '1') + (code[i+1] == '1') + (code[i+2] == '1');
        bits += (ones >= 2) ? '1' : '0';
    }
    // Кожні 8 біт -> символ
    string result;
    for (size_t i = 0; i < bits.size(); i += 8)
        result += char(bitset<8>(bits.substr(i, 8)).to_ulong());
    return result;
}
