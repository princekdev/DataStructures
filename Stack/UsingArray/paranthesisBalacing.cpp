#include <iostream>
#include "stack.h"

int main()
{
  Stack<char> charStack(10);

  std::string expression = "9+8*(10+9/3)*[7-7*(8/2)]";

  std::cout << expression << std::endl
            << std::endl;

  int i = 0;
  while (expression[i] != '\0')
  {
    char symbol = expression[i];

    if (symbol == '(' || symbol == '{' || symbol == '[')
    {
      charStack.push(symbol);
    }
    else if (symbol == ')' || symbol == '}' || symbol == ']')
    {
      if (charStack.isEmpty())
      {
        printf("Extra closing bracket found, Unbalanced Expression!\n");
        return 0;
      }

      if (charStack.top() == '(' && symbol == ')' || charStack.top() == '{' && symbol == '}' || charStack.top() == '[' && symbol == ']')
      {
        charStack.pop();
      }
      else
      {
        printf("Unmatched closing bracket found, Unbalanced Expression!\n");
        return 0;
      }
    }

    i++;
  }
  if (charStack.isEmpty())
  {
    printf("Balanced Expression!\n");
  }
  else
  {
    printf("Extra opening bracket(s) found, Unbalanced Expression!\n");
  }

  return 0;
}