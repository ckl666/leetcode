#include <iostream>
#include <string>

using namespace std;

/*
 * 动态规划 
 *
 * great
 *
 * rgeat
 *
 */

bool isScramble(string s1,string s2)
{
    
}


/*
 * 分治算法
 * 时间复杂度：
 * T(n) = 4*T(n/2) + 
 */
#if 0
bool isScramble(string s1,string s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }
    int len = s1.size();
    if(len == 1 && s1 == s2)
    {
        return true;
    }
    else if(len == 1 && s1 != s2)
    {
        return false;
    }
    else
    {
        string s11 = s1.substr(0,len/2);
        string s12 = s1.substr(len/2);

        string s21 = s2.substr(0,len/2);
        string s22 = s2.substr(len/2);
        if((isScramble(s11,s21) && isScramble(s12,s22)) 
                || (isScramble(s11,s22) && isScramble(s12,s21)))
        {
            return true;
        }

        s21 = s2.substr(0,len/2+1);
        s22 = s2.substr(len/2+1);
        if((isScramble(s11,s21) && isScramble(s12,s22)) 
                || (isScramble(s11,s22) && isScramble(s12,s21)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
#endif 


int main()
{
    string str1 = "great";
    string str2 = "rgtae";
    if(isScramble(str1,str2))
    {
        cout << "is scramble" <<endl;
    }
    else
    {
        cout << "is not scramble" << endl;
    }
    return 0;
}
