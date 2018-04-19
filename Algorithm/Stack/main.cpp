// https://www.acmicpc.net/problem/10828
// 2018-04-16
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node
{
  int data;

  Node* prevNode;
};

class Stack
{
public:
  Stack();
  ~Stack();

  void Push(int data);
  int Pop();
  int Size();
  bool IsEmpty();
  int Top();

private:
  Node* _topNode;
  int _size;
};

Stack::Stack()
{
  _topNode = nullptr;
  _size = 0;
}

Stack::~Stack()
{
  Node* deleteNote = _topNode;

  while (deleteNote != nullptr)
  {
    _topNode = deleteNote->prevNode;

    delete deleteNote;
    deleteNote = nullptr;

    deleteNote = _topNode;
  }
}

void Stack::Push(int data)
{
  Node* newNode = new Node;

  newNode->data = data;

  newNode->prevNode = _topNode;
  _topNode = newNode;

  _size++;
}

int Stack::Pop()
{
  if (_topNode != nullptr)
  {
    int data = _topNode->data;
    Node* prevNode = _topNode->prevNode;

    delete _topNode;
    _size--;

    _topNode = prevNode;

    return data;
  }

  return -1;
}

int Stack::Size()
{
  return _size;
}

bool Stack::IsEmpty()
{
  return (_size == 0) ? true : false;
}

int Stack::Top()
{
  if (_topNode != nullptr)
  {
    return _topNode->data;
  }

  return -1;
}

int main()
{
  Stack stack;

  int commandNum = 0;
  scanf("%d", &commandNum);

  getc(stdin); // 입력 버퍼에 \n이 남아있어서 초기화

  char str[15];
  for (int i = 0; i < commandNum; i++)
  {
    fgets(str, sizeof(str) - 1, stdin);

    char command[15];
    sscanf(str, "%s", command);

    if (!strcmp(command, "push"))
    {
      int data = -1;
      sscanf(str, "%s %d", command, &data);

      stack.Push(data);
    }
    if (!strcmp(command, "pop"))
    {
      printf("%d\n", stack.Pop());
    }
    if (!strcmp(command, "size"))
    {
      printf("%d\n", stack.Size());
    }
    if (!strcmp(command, "empty"))
    {
      printf("%d\n", stack.IsEmpty());
    }
    if (!strcmp(command, "top"))
    {
      printf("%d\n", stack.Top());
    }
  }

  return 0;
}