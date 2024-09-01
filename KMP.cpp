#include <string>
#include <iostream>
#include <vector>
using namespace std;

class KMP
{
private:
    /* data */
public:
    auto Pi_calculate(string string) ->vector<int>;
    auto Pi_calculate2(string string) ->vector<int>;
    KMP(/* args */);
    ~KMP();
    
};

auto KMP::Pi_calculate(string str) -> vector<int>
{
    // 初始化一个与str相同长度的vector，后续节约时间，占用空间较大（Pi计算2）
    // vector<int> Pi(str.size()); 

    // 仅初始化一个int，后续增加，时间消耗大，但如果中途满足条件，可停止后续计算即可节省空间
    vector<int> Pi={0};
    for (int i = 1;i<str.size(); i++)
    {
        Pi.emplace_back(0);
        int len = Pi[i-1]; 
        while (len||str[i] == str[len])
        {
            if(str[i] == str[len]){
                Pi[i] = len +1;
                break;
            }
            else len = Pi[len-1];
        }
    }
    return Pi;
}

auto KMP::Pi_calculate2(string str) -> vector<int>
{
    vector<int> Pi(str.size());
    for (auto i = 1 ;i<str.size(); i++)
    {
        int len = Pi[i-1];
        while (len && str[i]!=str[len])
            len = Pi[len-1];
        if(str[i] == str[len]){
            Pi[i] = len +1;
        }
    }
    return Pi;
}


KMP::KMP(/* args */)
{
}

KMP::~KMP()
{
}

int main(){
    string ss = "ATGATC#ATCGATCATGATCGATACGTAAGCT";
    KMP *kmp = new KMP;
    vector<int> Pis = kmp->Pi_calculate(ss);
    // vector<int> Pis = kmp->Pi_calculate2(ss);
    cout<<' '<<endl<<"Pi数组: ";
    for (size_t i = 0; i < Pis.size(); i++)
    {
        cout<<Pis[i]<<' ';
    }
    return 0;
}