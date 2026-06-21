class Solution {
public:
string chooseSwap(string &s) {
int count[26] = {0};
string str;
for (int i = 0; i<s.length(); i++) {
count[s[i]-'a']++;
if (count[s[i]-'a'] == 1) {
str.push_back(s[i]);
}
}
sort(str.begin(), str.end());
int j = 0;
int count1[26] = {0};
char ch;
char ch1;
for (int i = 0; i<s.length(); i++) {
if (count1[s[i]-'a'] > 0) {
continue;
}
if (s[i] == str[j]) {
count1[s[i]-'a']++;
j++;
continue;
}
if (s[i] != str[j]) {
ch = s[i];
ch1 = str[j];
break;
}
}
for (int i = 0; i<s.length(); i++) {
if (s[i] == ch) {
s[i] = ch1;
}
else if (s[i] == ch1) {
s[i] = ch;
}
}
return s;
}
};