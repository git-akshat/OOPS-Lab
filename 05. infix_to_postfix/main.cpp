/*
Write a C++ program to create a class called EXPRESSION. Accept an
arithmetic expression (assumed to be valid INFIX form) and assign to
EXPRESSION object. Convert the expression in the object to POSTFIX form by
writing appropriate member functions. Display the results.
*/

#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
using namespace std;

class EXPRESSION
{
    private:
            char infix[50],postfix[50];
            char s[50];
            int top;
    public:
            EXPRESSION(char *str)
            {
                strcpy(infix,str);
                top=0;
            }
            void push(char ch)
            {
                s[++top]=ch;
            }

            char pop()
            {
                return(s[top--]);
            }

            int precedence(char ch)
            {
                if(ch== '(' || ch== '#') return(1);
                if(ch== '+' || ch== '-') return(2);
                if(ch== '*' || ch== '/') return(3);
                if(ch == '^') return(4);
                return 0;
            }

            void display()
            {
                cout << postfix << endl;
            }

            void convert();
};


void EXPRESSION::convert()
{
    int i,j=0;
    push('#');
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]== ')')
        {
            while(s[top]!='(')
                postfix[j++]=pop();
            pop();
        }
        else
        {
            while(precedence(s[top])>=precedence(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
    }
    while(s[top]!='#')
        postfix[j++]=pop();
    postfix[j]='\0';
}


int main()
{
        char infix[50];
        cout << "Enter the valid Infix Expression :";
        cin >> infix;
        EXPRESSION Exp(infix);
        Exp.convert();
        cout << "\nThe Corresponding Suffix expression is:";
        Exp.display();
        return 0;
}
