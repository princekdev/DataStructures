#include <iostream>

class CharStack
{
private:
  int stackSize = 10;
  char arr[10];
  int stackTop = -1;

public:
  void push(char val)
  {
    if (isFull())
    {
      printf("Stack overflow!\n");
      return;
    }
    arr[stackTop + 1] = val;
    stackTop++;
  }

  char pop()
  {
    if (isEmpty())
    {
      printf("Stack underflow!\n");
      return NULL;
    }
    stackTop--;
    return arr[stackTop + 1];
  }

  char peek(int position)
  {
    if (stackTop + 1 < position)
    {
      printf("Index out of stacked range!\n");
      return NULL;
    }
    return arr[stackTop + 1 - position];
  }

  bool isEmpty()
  {
    if (stackTop == -1)
    {
      return 1;
    }
    return 0;
  }

  bool isFull()
  {
    if (stackTop == stackSize - 1)
    {
      return 1;
    }
    return 0;
  }

  char top()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return arr[stackTop];
  }

  char bottom()
  {
    if (isEmpty())
    {
      printf("Empty stack!\n");
      return NULL;
    }
    return arr[0];
  }

  void printStack()
  {
    printf("Top\n");
    for (int i = stackTop; i > -1; i--)
    {
      printf("%c\n", arr[i]);
    }
    printf("Bottom\n\n");
  }
};

int main()
{
  CharStack charStack;

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