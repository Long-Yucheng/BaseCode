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

        if(num >= 11)  // ����11��ʾ����ֵͬ�ĸ���������11��
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

            //���������ǣ���0��ʼ����������ֵ��ʼλ��
            cout << "start point is :" << i-num+1 << endl;
            // num ��ʾ������ֵͬ�ж��ٸ�
            cout << "count is : " << num << endl;

            num = 1;
        }

    }

    return 0;
}
