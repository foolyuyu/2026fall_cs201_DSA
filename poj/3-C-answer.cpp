#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int nums[605], ntop;
char ops[605];
int otop;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void calc() {
    int b = nums[ntop--];
    int a = nums[ntop--];
    char op = ops[otop--];

    int result = 0;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
    }

    nums[++ntop] = result;
}

int evaluate(const string& s) {
    ntop = otop = -1;

    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i];

        if (isdigit(c)) {
            int num = 0;
            while (i < (int)s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            nums[++ntop] = num;
            --i;
        }
        else if (c == '(') {
            ops[++otop] = c;
        }
        else if (c == ')') {
            while (otop >= 0 && ops[otop] != '(') {
                calc();
            }
            --otop;
        }
        else {
            while (otop >= 0 &&
                   ops[otop] != '(' &&
                   priority(ops[otop]) >= priority(c)) {
                calc();
            }
            ops[++otop] = c;
        }
    }

    while (otop >= 0) {
        calc();
    }

    return nums[ntop];
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        cout << evaluate(s) << '\n';
    }

    return 0;
}