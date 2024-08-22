#include <string>
#include <vector>
using namespace std;

class KMP
{
private:
    /* data */
    static vector<int> Pi;
    auto Pi_calculate(string string) ->vector<int>;
    auto Pi_calculate2(string string) ->vector<int>;
public:
    KMP(/* args */);
    ~KMP();
    
};

auto KMP::Pi_calculate(string str) -> vector<int>
{
    for (auto i = 0 ;i<str.size(); i++)
    {
        Pi.emplace_back(0);
        int len = Pi[i-1];
        while (len)
        {
            if(str[i] == str[len]){
                Pi[i] = len +1;
                break;
            }
            else len = Pi[len-1];
        }
    }
    return KMP::Pi;
}

auto KMP::Pi_calculate2(string str) -> vector<int>
{
    // Pi(str.size());
    for (auto i = 0 ;i<str.size(); i++)
    {
        int len = Pi[i-1];
        while (len && str[i]!=str[len])
            len = Pi[len-1];
        if(str[i] == str[len]){
            Pi[i] = len +1;
        }
    }
    return KMP::Pi;
}


KMP::KMP(/* args */)
{
}

KMP::~KMP()
{
}