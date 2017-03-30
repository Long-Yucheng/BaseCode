//---------------------------------------------------
//Author : Long Yucheng
//Mail	 : frank.long.yucheng@gmail.com
//---------------------------------------------------

#include<iostream>
#include<string>


using namespace std;

int main()
{
    std::string str = "987600000000000000000789111111111111111666666666666";

    int num = 1;

    char word;
    int len = str.length()-1;

    for(int i=0; i<len; i++)
    {
        if (str[i] == str[i+1]) {
            word = str[i];
            ++num;
        } else {
            num = 1;
        }

        if(num >= 11)  // 这里11表示，相同值的个数至少是11个
        {
            ++i;
            while (i < len) {
                if (str[i] == str[i+1]) {
                    ++i;
                    ++num;
                } else {
                    break;
                }
            }

            //这里的输出是：从0开始计数，连续值起始位置
            cout << "start point is :" << i-num+1 << endl;
            // num 表示连续相同值有多少个
            cout << "count is : " << num << endl;

            num = 1;
        }

    }

    return 0;
}
