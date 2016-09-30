#include <iostream>
#include <vector>
#include <utility>
#include <set>

int main(void)
{
    int n, k;
    std::vector<int> a;

    std::cin >> n >> k;
    for (int i = 0; i != n; i++)
    {
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }

    if (k == 1)
    {
        int count = 1;
        std::cout << count << std::endl;
        return 0;
    }


    /* 
     * let's say k is 4
     * then pairs like
     * (1,3), (2,2)
     * and the container store these pairs
     * */
    int first = 1;
    int end = k - 1;
    std::vector<std::pair<int,int> > pairs_container;
    for (; first <= end; first++, end--)
    {
        std::pair<int,int> pair(first, end);
        pairs_container.push_back(pair);
    }

    std::vector<int> result;
    std::set<int> pair_equal_set; // like (2,2), which elements can only pick one
    std::set<int> remainder_zero_set; // like 4 % 4 = 0, k is 4, which elements can only pick one
    for (auto it = pairs_container.begin(); it != pairs_container.end(); ++it)
    {
        // each it is a pair
        std::vector<int> count(2,0);
        for (auto elem : a)
        {
            if (elem % k == it->first)
                count[0]++;
            if (elem % k == it->second)
                count[1]++;
            if (elem % k == 0)
            {
                remainder_zero_set.insert(elem);
            }
        }

        // "==" situation, either not push_back
        if (count[0] > count[1])
        {
            for (auto elem : a)
            {
                if (elem % k == it->first)
                    result.push_back(elem);
            }
        }
        else if (count[0] < count[1])
        {
            for (auto elem : a)
            {
               if (elem % k == it->second) 
                   result.push_back(elem);
            }
        }
        else
        {
            if (it->first == it->second) // like (2,2)
            {
                for (auto elem : a)
                {
                    if (elem % k == it->first)
                    {
                        pair_equal_set.insert(elem);
                    }
                }
            }
        }

    }

    std::cout << "result: ";
    for (auto em : result)
    {
        std::cout << em << " ";
    }
    std::cout << std::endl;

    std::cout << "pair_equal_set: ";
    for (auto em : pair_equal_set)
    {
        std::cout << em << " ";
    }
    std::cout << std::endl;

    std::cout << "remainder_zero_set: ";
    for (auto em : remainder_zero_set)
    {
        std::cout << em << " ";
    }
    std::cout << std::endl;

      int c = result.size();
      if (pair_equal_set.size() > 0)
          c++;
      if (remainder_zero_set.size() > 0)
          c++;

      std::cout << c << std::endl;
        

    return 0;
}
