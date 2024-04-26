#include <iostream>
#include <vector>

int main()
{
    int tops;
    std::cin >> tops;

    std::vector<std::vector<int>> adj;
    int sides = 0;

    for (int i = 0; i < tops; i++)
    {
        std::vector<int> line;
        for (int j = 0; j < tops; j++)
        {
            int num = 0;
            std::cin >> num;
            line.push_back(num);
            sides += num;
        }
        adj.push_back(line);
    }

    std::vector<std::vector<int>> inc(tops, std::vector<int> (sides, 0));
    int c = 0;

    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
        {
            if (adj[i][j] == 1)
            {
                inc[i][c] = 1;
                inc[j][c] = -1;
                c++;
            }
        }
    }

    for (int i = 0; i < inc.size(); i++)
    {
        for (int j = 0; j < inc[0].size(); j++)
        {
            if (inc[i][j] == -1)
            {
                std::cout << "-1 ";
            }
            else
            {
                std::cout << inc[i][j] << "  ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
