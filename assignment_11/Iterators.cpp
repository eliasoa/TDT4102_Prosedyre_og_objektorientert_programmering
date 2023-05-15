#include <Iterators.h>

void replace(std::vector<std::string> &vec, std::string old, std::string replace){
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it == old)
        {
            it = vec.erase(it);
            it = vec.insert(it,replace);
        }
    }
}

void replace(std::set<std::string> &set, std::string old, std::string replace){
    for (auto it = set.begin(); it != set.end(); it++)
    {
        if (*it == old)
        {
            it = set.erase(it);
            it = set.insert(it,replace);
        }
    }
}

void problem1(){
    // Problem 1a
    std::vector<std::string> stringVector = {"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"}; 
    for (auto it = stringVector.begin(); it != stringVector.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    // Problem 1b
    for (auto it = stringVector.rbegin(); it != stringVector.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    // Problem 1c
    std::vector<std::string> vektor = {"Lorem","Ipsum","Dolor","Lorem"}; 
    std::cout << "Before repalce is used:" << std::endl;
    for (auto it = vektor.begin(); it != vektor.end() ;it++)
    {
        std::cout << *it << std::endl;
    }
    replace(vektor,"Lorem","Latin");
    std::cout << "After repalce is used:" << std::endl;
    for (auto it = vektor.begin(); it != vektor.end() ;it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Problem 1d:" << std::endl;

    std::set<std::string> stringSet = {"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"};
    for (auto it = stringSet.begin(); it != stringSet.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    for (auto it = stringSet.rbegin(); it != stringSet.rend(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::set<std::string> set = {"Lorem","Ipsum","Dolor","Lorem"};
    std::cout << "Before repalce is used:" << std::endl;
    
    for (auto it = set.begin(); it != set.end() ;it++)
    {
        std::cout << *it << std::endl;
    }

    replace(set,"Lorem","Latin");

    std::cout << "After repalce is used:" << std::endl;
    for (auto it = set.begin(); it != set.end() ;it++)
    {
        std::cout << *it << std::endl;
    }
}

