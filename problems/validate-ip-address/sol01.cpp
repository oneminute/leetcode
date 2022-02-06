#include <vector>
#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;

struct IP
{
    union   // 让32位整数与长度为4的unsigned char共用内存，从而省略从4段ip地址转换为32位整数的过程
    {
        unsigned int ip;
        struct
        {
            unsigned char segs[4];
        };
    };
};

int main(int argc, char *argv[])
{

    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "120#255#255#127", "2030043007"));
    suite.push_back(new st::StreamTestCase("Test 02", "255", "-1"));
    suite.push_back(new st::StreamTestCase("Test 03", "192#168#132#100", "-1"));
    suite.push_back(new st::StreamTestCase("Test 04", "0#0#0#0", "0"));
    suite.push_back(new st::StreamTestCase("Test 05", "1#0#0#0", "16777216"));
    suite.push_back(new st::StreamTestCase("Test 06", "0#0#0#1", "1"));
    runner.addTask(&suite);
    runner.start();

    string data;
    while (cin >> data)
    {
        int begin = 0;      // ip地址每一段的起始索引
        int segCount = 0;   // 当前读取到ip地址总段数
        bool valid = false; // 是否合法
        IP ip;              // ip地址结构体
        ip.ip = 0;
        for (int i = 0; i < data.size(); i++)
        {
            int end = begin;
            if (data[i] == '#')     // 如果找到#，标记该段结尾
                end = i;
            else if (i == data.size() - 1)  // 如果找到最后一个字符，标记该段结尾
                end = i + 1;
            
            int segLength = end - begin;
            if (segLength)    // 如果该段长度合法，则转换该地址分段
            {
                string segStr = data.substr(begin, segLength);
                int seg = stoi(segStr);
                if (seg < 0 || seg > 255)   // 验证是否在0到255内
                    break;
                ip.segs[4 - ++segCount] = static_cast<unsigned char>(seg);  // 按高向低的顺序放置ip分段
                begin = end + 1;
            }
        }
        if (segCount == 4 && ip.ip <= 0x7fffffff)
            valid = true;

        if (valid)
            cout << ip.ip << endl;
        else
            cout << -1 << endl;
        runner.check();
    }
    runner.check();
    runner.finish();

    return 0;
}