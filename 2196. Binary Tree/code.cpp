#include<bits/stdc.h++>

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mymap; //map for integer and the nodes.
        unordered_set<int> child; // map to enter only the children.
        for(const auto& desc: descriptions){
            int par = desc[0];
            int chil = desc[1];
            bool left = desc[2];

            if(mymap.count(par) == 0){
                mymap[par] = new TreeNode(par);
            }
            if(mymap.count(chil) == 0){
                mymap[chil] = new TreeNode(chil);
            }

            if(left){
                mymap[par]-> left = mymap[chil];
            }
            else{
                mymap[par] -> right = mymap[chil];
            }
            child.insert(chil);
        }

        for(const auto& [val, node]: mymap){
            if(child.count(val)==0) return node;
        }
        return nullptr;
    }
};