#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<char> lines;

int main(void) {

    while (1) {
        char temp;
        bool isLine = true, isEnd = true;
        lines.clear();

        while(1) {
            scanf("%c", &temp);
            if (temp == '.') {
                break;
            }
            isEnd = false;

            if (temp == '(' || temp == '[') {
                lines.push_back(temp);
            }
            else if (temp == ')' || temp == ']') {
                if (lines.empty()) {
                    isLine = false;
                    break;
                }
                if (lines.back() == '(') {
                    if (temp == ']') {
                        isLine = false;
                        break;
                    }
                    lines.pop_back();
                }else if (lines.back() == '[') {
                    if (temp == ')') {
                        isLine = false;
                        break;
                    }
                    lines.pop_back();
                }
            }
        }

        if (isEnd) {
            break;
        }

        while (getchar() != '\n') {}

        if (isLine && lines.empty()) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}