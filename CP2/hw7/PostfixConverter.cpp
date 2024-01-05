#pragma warning( disable : 4996 )
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

//判斷字元是否為運算子（'+', '-', '*', '/'）
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

//判斷運算子的優先順序，優先順序越高的運算子傳回的值越大(權重)
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

//接收一個中序表示法的字串作為輸入，並將其轉換成後序表示法的字串後傳回
string infixToPostfix(const string& infix) {
    stack<char> operators;//堆疊（stack）用來存放運算子
    string postfix;//字串 postfix 來存放後序表示法的結果
    unordered_map<char, int> variables;  // Store variable values if needed

    // 函式使用迴圈依序讀取中序表示法字串中的每個字元：
    // 若字元是字母，直接加到 postfix 字串中。
    // 若字元是開始括號 '(', 則將其壓入stack。
    // 若字元是結束括號 ')', 則從stack中依序pop運算子並附加到 postfix 字串中，直到遇到開始括號 '(' 為止。開始和結束括號都不會加到 postfix 字串。
    // 若字元是運算子（'+', '-', '*', '/'），則從stack中彈出運算子並附加到 postfix 字串中，直到遇到優先順序比目前運算子低的運算子或開始括號為止。然後將目前的運算子壓入stack。
    for (char c : infix) {
        if (isalpha(c)) {
            postfix += c;  // Append variables directly to postfix expression
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(')
                operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // 迴圈結束後，將運算子堆疊中剩餘的運算子彈出並附加到 postfix 字串中。
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    //傳回 postfix 字串作為後序表示法的結果
    return postfix;
}

int main() {
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}


//https://www.youtube.com/watch?v=fz7ZgqGFHx4