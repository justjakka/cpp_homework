#include <iostream>
#include <stack>

using namespace std;


int quickexit()
{
    cout << "No" << endl;
    exit(0);
}


int main()
{
    string brackets;
    cin >> brackets;

    stack<char> temp;

    for (int i = 0; i < brackets.length(); i++)
    {
        if ((brackets[i] == '}' || brackets[i] == ']' || brackets[i] == ')') && temp.empty())
            quickexit();
        else
        {
            if (brackets[i] == '{' || brackets[i] == '[' || brackets[i] == '(')
                temp.push(brackets[i]);
            else
            {
                if (brackets[i] == '}')
                {
                    if (temp.top() != '{')
                    {
                        quickexit();
                    }
                    else
                        temp.pop();
                }

                if (brackets[i] == ')')
                {
                    if (temp.top() != '(')
                    {
                        quickexit();
                    }
                    else
                        temp.pop();
                }

                if (brackets[i] == ']')
                {
                    if (temp.top() != '[')
                    {
                        quickexit();
                    }
                    else
                        temp.pop();
                }

            }
        }
    }

    cout << "Yes" << endl;
}