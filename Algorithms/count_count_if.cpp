#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>
#include <cassert>
 
int main()
{
    std::array<int, 10> const v= {1, 2, 3, 4, 4, 3, 7, 8, 9, 10};
    std::cout << "v: ";
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
 
    // determine how many integers match a target value.
    for (const int target: {3, 4, 5})
    {
        const int num_items = std::count(v.cbegin(), v.cend(), target);
        std::cout << "number: " << target << ", count: " << num_items << '\n';
    }
 
    // use a lambda expression to count elements divisible by 4.
    int count_div4 = std::count_if(v.begin(), v.end(), [](int i) { return i % 4 == 0; });
    std::cout << "numbers divisible by four: " << count_div4 << '\n';
 
    // A simplified version of `distance` with O(N) complexity: // how many elements
    auto distance = [](auto first, auto last)
    {
        return std::count_if(first, last, [](auto){ return true; });
    };
    assert(distance(v.begin(), v.end()) == 10);
}