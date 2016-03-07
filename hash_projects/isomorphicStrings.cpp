//
//  isomorphicStrings.cpp
//  hash_projects
//
//  Created by yzc on 3/7/16.
//  Copyright © 2016 yzc. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>
//using namespace std;

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.size()!=t.size()){
            return false;
        }
        std::unordered_map<char,int> train;
        std::unordered_map<char,int> test;
        int idx=0;
        for (int i=0;i<s.size();i++){
            if (train.find(s[i]) == train.end()){
                train[s[i]]=idx;
                idx++;
                std::cout <<s[i]<<std::endl;
            }
        }
        idx=0;
        for (int i=0;i<t.size();i++){
            if (test.find(t[i]) == test.end()){
                test[t[i]]=idx;
                idx++;
            }
            if (train[s[i]]!=test[t[i]]){
                return false;
            }
        }
        return true;
    }
};