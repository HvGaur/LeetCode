#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    struct Robot{
        int position;
        int health;
        char dir;
        int index;
    }
    vector<int> survivedRobotsHealth(vector<int>& positions, vector<int>& healths, string dir){
        int n = positions.size();
        vector<Robot> rootObj;
        for(int i = 0; i < n; i++){
            rootObj.push_back({positions[i], healths[i], dir[i], i});
        }

        sort(rootObj.begin(), rootObj.end(), [](const Robot& a, const Robot& b){
            return a.position < b.position;
        })

        vector<Robot> eval;

        for(auto& robot: rootObj){
            if(robot.dir = 'R'){
                eval.push_back(robot);
            }
            else{

                bool removal = false;

                while(!eval.empty() && eval.back().dir == 'R' && eval.back().health <= robot.health){
                    if(eval.back().health==robot.health){
                        eval.pop_back();
                        // robot.he
                        removal = true;
                        break;
                    }
                    eval.pop_back();
                    robot.health--;
                }

                if(!removal && !eval.empty() && eval.back().dir == 'L' && eval.back().health > robot.health){
                    eval.back().health--;
                    removal = true;
                }

                if(!removal){
                    eval.push_back(robot);
                }
            }
        }
        sort(eval.begin(), eval.end(), [](const Robot& a, const Robot& b){
            return a.index < b.index;
        });

        vector<int> res;

        for(auto& rob: eval){
            res.push_back(rob.health);
        }
        return res
    }
};