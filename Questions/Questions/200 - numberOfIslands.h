#ifndef LEET200_H
#define LEET200_H

#include "config.h"

class Solution200
{
public:
    int numIslands(std::vector<std::vector<char>>& grid);
    void markByBFS(std::vector<std::vector<char>>& grid, int x, int y);
};
#endif
