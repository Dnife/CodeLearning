#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {2,1,1,3,4,1,2,4,1,4,1,2,3,4,5,6,3,4,1,4,5,2,1,2,1,3};
    int level =0, next =0, cur =0;
    //使用path存储路径
    vector<int> path={0};
    // 循环更新从i位置走一步能到达的最远位置next，
    // 走level步可到达的所有位置cur
    // 复杂度O（n）
    for (int i = 0; i < nums.size()-1; i++)
    {
        // next = max(next,i+nums[i]);
        if (next<i+nums[i])
        {
            next=i+nums[i];
            //每当找到本层能跳最远的位置时，保存该位置
            path[level] = i;
        }
        
        // 当i等于cur时，表示需要再走一步才能到达新位置
        if (i==cur) {
            level ++;
            cur = next;
            path.emplace_back(0);
        }
    }
    cout<<' '<<endl;
    cout<<"跳到末尾需要的最少步数："<<level<<endl;
    int res=0;
    cout<<"可跳到末尾的路径：";
    for (int i = 0; i < level; i++)
    {
        cout<<path[i]<<' ';
        res+=nums[path[i]];
    }
    cout<<endl;
    
    cout<<"最远能跳的距离："<<res<<endl<<"末尾位置："<<nums.size()<<endl;
    return 0;
} 