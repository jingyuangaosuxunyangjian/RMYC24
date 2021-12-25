//功能：RMYC能量机关24点规则出题
//第三方依赖：无
//开源协议：BSD
//联系方式：jingqiao@syirobot.cn/3068250570@qq.com
//作者：jingqiao
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void addition();
void subtraction();
void multiplication();
void division();

int output[4] = {0};

int main()
{
    cout << "Hello World" << endl;
    int choice = 0;

    srand((unsigned)time(NULL));
    choice = rand() % 4;//choice in [0,3]
    if (choice == 0)
    {
        addition();
        cout << '+';
    }
    else if (choice == 1)
    {
        subtraction();
        cout << '-';
    }
    else if (choice == 2)
    {
        multiplication();
        cout << '*';
    }
    else
    {
        division();
        cout << '/';
    }   

    cout << output[0] << "|" << output[1] << "|" << output[2] << "|" << output[3] << endl;
    
    return 0;
}

void addition()
{
    int choice = 0;
    int x1, x2, x3;

    srand((unsigned)time(NULL));
    choice = rand() % 5;

    if (choice == 0)//1 + 1 + 1 + 1
    {
        while (output[0] + output[1] + output[2] >= 24 || output[0] + output[1] + output[2] <= 14)
        {
            output[0] = rand() % 10;
            output[1] = rand() % 10;
            output[2] = rand() % 10;
        }
        output[3] = 24 - (output[0] + output[1] + output[2]);
    }
    else if (choice == 1)//1 + 1 + 1
    {
        while (output[choice] + output[choice + 1] <  15)
        {
            choice = rand() % 4;
            output[choice] = rand() % 4 + 6;
            output[(choice + 1) % 4] = rand() % 4 + 6;
        }
        output[(choice + 2) % 4] = 24 - (output[choice] + output[choice + 1]);
        output[(choice + 3) % 4] = rand() % 10;
    }
    else if (choice == 2)//2 + 1 + 1
    {
        choice = rand() % 2;//choice in [0,1]
        if (choice == 0)
        {
            choice = rand() % 4;//choice in [0,3]
            output[choice] = 1;
            x1 = choice;
            while (choice == x1)
            {
                choice = rand() % 4;
            }
            output[choice] = rand() % 10;
            x2 = choice;
            while (choice == x1 || choice == x2)
            {
                choice = rand() % 4;
            }
            if (output[x2] < 5)
            {
                while (24 - 10 - output[x2] - output[choice] > 9)
                {
                    output[choice] = rand() % 10;
                }
                
            }
            else 
            {
                output[choice] = (rand() % (24 - 10 - output[x2])) % 10;//choice a number in [0,24-10-output[x2]]
            }
            x3 = choice;
            choice = 0;
            while (choice == x1 || choice == x2 || choice == x3)
            {
                choice = rand() % 4;
            }
            output[choice] = 24 - 10 - output[x2] - output[x3];
        }
        else{
            choice = rand() % 4;//choice in [0,3]
            output[choice] = 2;
            x1 = choice;
            while (choice == x1)
            {
                choice = rand() % 4;
            }
            x2 = choice;
            while (choice == x1 || choice == x2)
            {
                choice = rand() % 4;
            }
            x3 = choice;
            while (choice == x1 || choice == x2 || choice == x3)
            {
                choice = rand() % 4;
            }
            output[x2] = rand() % 5;
            output[x3] = rand() % 5;
            while (output[x2] + output[x3] > 4)
            {
                output[x2] = rand() % 5;
                output[x3] = rand() % 5;
            }
            output[choice] = 4 - output[x2] - output[x3];
        }
    }
    else if (choice == 3)//2 + 1
    {
        output[0] = rand() % 10;
        output[1] = rand() % 10;
        output[2] = rand() % 10;
        output[3] = rand() % 10;

        choice = rand() % 2;//choice in [0,1]
        if (choice == 0)//1_ + x
        {
            choice = rand() % 4;//choice in [0,3]
            output[choice] = 1;
            x1 = choice;
            while (choice == x1)
            {
                choice = rand() % 4;
            }
            output[choice] = rand() % 5 + 5;
            x2 = choice;
                while (choice == x1 || choice == x2)
            {
                choice = rand() % 4;
            }
            output[choice] = 24 - 10 - output[x2];
        }
        else//2_ + x
        {
            choice = rand() % 4;//choice in [0,3]
            output[choice] = 2;
            x1 = choice;
            while (choice == x1)
            {
                choice = rand() % 4;
            }
            output[choice] = rand() % 4;
            x2 = choice;
            while (choice == x1 || choice == x2)
            {
                choice = rand() % 4;
            }
            output[choice] = 4 - output[x2];
        }
    }
    else//2 + 2
    {
        choice = rand() % 4;
        output[choice] = 1;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 1;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = rand() % 5;
        x3 = choice;
        choice = 0;
        while (choice == x1 || choice == x2 || choice == x3)
        {
            choice ++;
        }
        output[choice] = 4 - output[x3];
    }
}

void subtraction()
{
    int choice = 0;
    int x1, x2, x3 = 0;
    int minuend = 0;
    int subtrahend = 0;

    srand((unsigned)time(NULL));
    choice = rand() % 2;
    if (choice == 0)//2 - 2
    {
        minuend = rand() % 66 + 34;//in [34,99]
        subtrahend = minuend - 24;
        choice = rand() % 4;
        output[choice] = minuend / 10;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = minuend % 10;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = subtrahend / 10;
        x3 = choice;
        choice = 0;
        while (choice == x1 || choice == x2 || choice == x3)
        {
            choice ++;
        }
        output[choice] = subtrahend % 10;
    }
    else//2 - 1
    {
        output[0] = rand() % 10;
        output[1] = rand() % 10;
        output[2] = rand() % 10;
        output[3] = rand() % 10;
        minuend = rand() % 4 + 24;//in [24,33]
        subtrahend = minuend - 24;
        choice = rand() % 4;
        output[choice] = minuend / 10;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = minuend % 10;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = subtrahend;
    }
}

void multiplication()
{
    int choice = 0;
    int x1, x2, x3 = 0;

    srand((unsigned)time(NULL));
    output[0] = rand() % 10;
    output[1] = rand() % 10;
    output[2] = rand() % 10;
    output[3] = rand() % 10;
    choice = rand() % 6;
    if (choice == 0)//2 * 2 * 2 * 2
    {
        output[0] = 2;
        output[1] = 2;
        output[2] = 2;
        output[3] = 2;
        choice = rand() % 4;
        output[choice] = 3;
    }
    else if (choice == 1)//2 * 3 * 4
    {
        choice = rand() % 4;
        output[choice] = 2;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 3;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = 4;
    }
    else if (choice == 2)//2 * 2 * 6
    {
        choice = rand() % 4;
        output[choice] = 2;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 2;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = 6;
    }
    else if (choice == 3)//12 * 2
    {
        choice = rand() % 4;
        output[choice] = 1;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 2;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = 2;
    }
    else if (choice == 4)//24 * 1
    {
        choice = rand() % 4;
        output[choice] = 2;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 4;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = 1;
    }
    else//4 * 6
    {
        choice = rand() % 4;
        output[choice] = 4;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = 6;
    }
}

void division()
{
    int choice = 0;
    int x1, x2, x3 = 0;
    
    srand((unsigned)time(NULL));
    choice = rand() % 2;
    if (choice == 0)//x * 24, x in [1,4]
    {
        output[0] = rand() % 10;
        output[1] = rand() % 10;
        output[2] = rand() % 10;
        output[3] = rand() % 10;
        
        choice = rand() % 4;
        output[choice] = rand() % 4 + 1;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = (output[x1] * 24) / 10;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = output[x1] * 24 % 10;
    }
    else//x * 24, x in [5,9]
    {
        choice = rand() % 4;
        output[choice] = rand() % 5 + 5;
        x1 = choice;
        while (choice == x1)
        {
            choice = rand() % 4;
        }
        output[choice] = output[x1] * 24 / 100;
        x2 = choice;
        while (choice == x1 || choice == x2)
        {
            choice = rand() % 4;
        }
        output[choice] = output[x1] * 24 / 10 % 10;
        x3 = choice;
        choice = 0;
        while (choice == x1 || choice == x2 || choice == x3)
        {
            choice ++;
        }
        output[choice] = output[x1] * 24 % 10;
    }
}