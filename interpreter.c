#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(int *stack, int val)
{
    stack++;
    *stack = val;
}

void pop(int *stack)
{
    *stack = 0;
    stack--;
}

int top(int *stack)
{
    return *stack;
}

int main()
{
    char input[300];
    char tape[30000] = {0};
    int *stack = (int *)calloc(100, sizeof(int));

    scanf("%s", &input);

    int n = 0;
    int i = 0;
    int slen = strlen(input);

    while (i < slen)
    {
        char ch = input[i];

        switch (ch)
        {
        case '>':
            n++;
            break;

        case '<':
            n--;
            break;

        case '+':
            tape[n]++;
            break;

        case '-':
            tape[n]--;
            break;

        case '.':
            printf("%c", tape[n]);
            break;

        case ',':
            scanf(" %c", &tape[n]);
            break;

        case '[':
            if (tape[n] == 0)
            {
                int depth = 1;

                while (depth > 0)
                {
                    i++;
                    if (input[i] == '[')
                        depth += 1;
                    if (input[i] == ']')
                        depth -= 1;
                }
            }
            else
                push(stack, i);
            break;

        case ']':
            if (tape[n] == 0)
                pop(stack);
            else
                i = top(stack);
            break;

        default:
            printf("Enter valid string\n");
            return -1;
        }

        i++;
    }

    return 0;
}