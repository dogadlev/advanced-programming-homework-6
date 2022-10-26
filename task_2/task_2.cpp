#include <iostream>
#include <set>

int main(int argc, char **argv)
{
    std::cout << "[IN]:" << std::endl;

    unsigned int size = 0;
    int elm = 0;
    std::set<int> nums;

    std::cin >> size;
    while (size)
    {
        std::cin >> elm;
        nums.insert(elm);
        --size;
    }

    std::cout << "[OUT]:" << std::endl;
    for (auto itr = nums.crbegin(); itr!=nums.crend(); ++itr)
        std::cout << *itr << std::endl;

    return 0;
}