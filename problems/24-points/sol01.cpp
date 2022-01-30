#include <vector>
#include <iostream>
#include <string>
#include <SimpleTest.h>

using namespace std;

// 运算符列表
char operators[4] = { '+', '-', '*', '/' };

/**
 * @brief cardToInt
 * 牌面字符串转换为数字
 * @param card 待转换的牌面字符串
 * @return 对应的数字
 */
int cardToInt(string card)
{
    int value;
    if (card == "A" || card == "a") value = 1;
    else if (card == "J" || card == "j") value = 11;
    else if (card == "Q" || card == "q") value = 12;
    else if (card == "K" || card == "k") value = 13;
    else // 对于数字牌面，直接转为数字即可
        value = stoi(card);
    return value;
}

/**
 * @brief dts
 * 递归遍历函数。思路如下：
 * 给定一组牌cards，要抽出的牌索引removingCardIndex，要执行的四则运算符currentOperator，执行到当前这一次调用前的四则运算结果result，和当前形成的字符串表达式expression。
 * 从cards中，将要抽出的牌索引removingCardIndex移除掉。然后对cards中剩余的牌依次遍历，将上一次的执行结果和当前遍历的牌面值用currentOperator运算符执行一次运算，判断结果是
 * 否为24，如果是24，则无需继续计算，直接返回到当前牌的表达式即可。如果不是24，则将当前剩余的牌cards，本次遍历抽出的牌，本次遍历的四则运算符，以及本次运算后的数值结果和表达式作为
 * 参数，再次递归调用dts。直到4张牌用尽，或是找到24为止。
 * 返回的结果中，只要表达式不为空，则表示找到了24，为空则表示没有找到24。
 * @param cards 当前剩余的牌集合。
 * @param removingCardIndex 准备要抽出的一张牌，在进入该函数后，如果索引值不是-1，则会把该索引对应的牌从cards中移除掉。
 * @param currentOperator 当前这一次要执行的四则运算符。如果值为-1，则表示无运算。这用于第一次调用dts函数时。
 * @param result 计算到当前这一张牌时，前面的牌四则运算后的数值结果。
 * @param expression 计算到当前这一张牌时，前面的牌形成的计算表达式字符串。
 * @return 如果找到等于24的表达式，则返回该表达式，如果找不到，则返回空字符串。
 */
string dts(vector<string> cards, int removingCardIndex, char currentOperator, int result, string expression)
{
    // 如果待删除的牌索引有效，则将之从cards中删除
    if (removingCardIndex != -1)
    {
        cards.erase(cards.begin() + removingCardIndex);
    }

    // 对剩余的牌执行遍历
    for (int i = 0; i < cards.size(); i++)
    {
        int currentResult = result;
        string currentExpression = expression;
        string card = cards[i];
        int cardValue = cardToInt(card);
        switch(currentOperator)
        {
        case '+':
            currentResult = result + cardValue;
            currentExpression.push_back(currentOperator);
            break;
        case '-':
            currentResult = result - cardValue;
            currentExpression.push_back(currentOperator);
            break;
        case '*':
            currentResult = result * cardValue;
            currentExpression.push_back(currentOperator);
            break;
        case '/':
            currentResult = result / cardValue;
            currentExpression.push_back(currentOperator);
            break;
        default:
            currentResult = cardValue;
        }
        currentExpression.append(card);
        if (currentResult == 24)
            return currentExpression;

        for (char oprt: operators)
        {
            string resultExpression = dts(cards, i, oprt, currentResult, currentExpression);
            // 判断返回的表达式，如果不为空，则找到了24，直接将表达式向上返回即可。
            if (!resultExpression.empty())
                return resultExpression;
        }
    }

    return "";
}

int main()
{
    st::StreamTestRunner runner;
    st::TestSuite suite("Suite 01");
    suite.push_back(new st::StreamTestCase("Test 01", "4 2 K A", "K+A*2-4"));
    suite.push_back(new st::StreamTestCase("Test 01", "1 9 1 2", "K+A*2-4"));
    runner.addTask(&suite);
    runner.start();

    string inputs[4];
    while (cin >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3])
    {
        vector<string> cards;
        for (int i = 0; i < 4; i++)
        {
            // 如果输入中有joker和JOKER则跳出循环
            if (inputs[i] == "joker" || inputs[i] == "JOKER")
                break;
            cards.push_back(inputs[i]);
        }

        // 如果收集到的牌集合不满足4张，那就是因为有joker或JOKER，提示错误。
        if (cards.size() != 4)
        {
            cout << "ERROR" << endl;
            continue;
        }

        // 张一次执行dts函数，将所有牌都传入进去，不抽取牌，也不执行运算。
        string result = dts(cards, -1, -1, 0, "");
        if (result.empty())
        {
            result = "NONE";
        }
        cout << result << endl;
        runner.check();
    }
    runner.finish();
    return 0;
}
