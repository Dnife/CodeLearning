#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// #include <functional>

using namespace std;
template <typename T>
bool bfs(vector<T> &nums,int start){
    vector<bool> isv(nums.size(),false);
    queue<T> q1;
    q1.push(start);    
    while(!q1.empty()){
        T i = q1.front();
        q1.pop();
        if(i<0||i>=nums.size()) continue;
        if(isv[i]) continue;

        isv[i] = true;
        if (!nums[i]) return true;
        q1.push(i+nums[i]);
        q1.push(i-nums[i]);
    }
    return false;
}

template <typename T>
bool dfs(vector<T> &nums, int start){
    vector<char> isv(nums.size(),0);
    // function<bool(int)> dfs = [&](int i){
    //     if(i<0||i>=nums.size()) return false;
    //     if(isv[i]) return false;
    //     isv[i] = 1;
    //     if (!nums[i]) return true;
    //     return dfs(i+nums[i])||dfs(i-nums[i]);
    // };
    auto dfs = [&](auto& dfs,int i){
        if(i<0||i>=nums.size()) return false;
        if(isv[i]) return false;
        isv[i] = 1;
        if (!nums[i]) return true;
        return dfs(dfs,i+nums[i])||dfs(dfs,i-nums[i]);
    };
    return dfs(dfs, start);
}


int main(){
    cout<<' '<<endl<<"DFS_BFS.exe result:"<<endl;
    vector<int> nums={1,4,6,2,6,3,5,0,2,5,3,5,2,3};
    
    if(bfs(nums,5)) cout<<"bfs:True"<<endl;
    if(dfs(nums,4)) cout<<"dfs:True"<<endl;

    int a=10,b=3;
    int res = [a,b](){ return a + b;}();

    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    // 使用Lambda表达式对向量进行排序
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a > b;});

    // 输出排序后的向量元素
    for(int num : numbers) {
        std::cout << num << " ";
    }

    
    return 0;
}