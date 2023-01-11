#include <iostream>
#include <string>
#include <algorithm>
 //the following function returns the first letters (in order) that are mirrored in that string
std::string mirror_ends(const std::string& in)
{
    return std::string(in.begin(),
                       std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}
//rbegin is reversebegin iterator (pointer to last-1)
 
int main()
{
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}