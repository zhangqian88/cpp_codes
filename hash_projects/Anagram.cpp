//
//  Anagram.cpp
//  hash_projects
//
//  Created by yzc on 3/7/16.
//  Copyright © 2016 yzc. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> p2i;
        if (s.size()!=t.size()){
            return false;
        }
        for (int i=0; i<s.size(); i++){
            if (p2i.find(s[i])==p2i.end()){
                p2i[s[i]]=1;
            }else {
                p2i[s[i]]++;
            }
        }
        for (int i=0;i<t.size();i++){
            if (p2i.find(t[i])==p2i.end()){
                return false;
            }
            else if (p2i[t[i]]==0){
                return false;
            }
            else{
                p2i[t[i]]--;
            }
        }
        return true;
    }
};
