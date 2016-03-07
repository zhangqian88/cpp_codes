//
//  ValidSudoku.cpp
//  hash_projects
//
//  Created by yzc on 3/7/16.
//  Copyright © 2016 yzc. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // check size
        std::unordered_map<char, int> p2i;
        if (board.size()!=9 || board[0].size()!=9)
        {
            return false;
        }
        // check row
        for (int i=0;i<9;i++)
        {
            p2i.clear();
            for (int j=0;j<9;j++)
            {
                if ((board[i][j]<'1' || board[i][j]>'9' || p2i.find(board[i][j])!=p2i.end() ) && board[i][j]!='.' )
                {
                    return false;
                }
                p2i[board[i][j]]=1;
            }
        }
        
        // check column
        for (int i=0;i<9;i++)
        {
            p2i.clear();
            for (int j=0;j<9;j++)
            {
                if ( p2i.find(board[j][i])!=p2i.end() && board[j][i]!='.' )
                {
                    return false;
                }
                p2i[board[j][i]]=1;
            }
        }
        
        // check subset
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                p2i.clear();
                for (int k=i*3;k<i*3+3;k++)
                {
                    for (int h=j*3;h<j*3+3;h++)
                    {
                        if ( p2i.find(board[k][h])!=p2i.end() && board[k][h]!='.' )
                        {
                            return false;
                        }
                        p2i[board[k][h]]=1;
                    }
                }
            }
        }
        return true;
    }
    
};
