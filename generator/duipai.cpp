#include <bits/stdc++.h>

int main() {
    std::string path = getenv("PROJECT_ROOT");
    int cnt = 0;
    system(std::string(path + "\\bin\\" + "data.exe").c_str());
    system(std::string(path + "\\bin\\" + "J_1.exe").c_str());
    system(std::string(path + "\\bin\\" + "J.exe").c_str());
    system("fc std.txt brute.txt");
    return 0;
}