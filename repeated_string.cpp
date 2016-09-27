#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::string s;
    std::cin >> s;
    long n;
    std::cin >> n;

    int length = s.length();
    int a_count_length = std::count(s.begin(), s.end(), 'a');

    long count = a_count_length * long(n / length) + std::count(s.begin(), s.begin()+(n%length), 'a');
    std::cout << count << std::endl;

    return 0;
}
