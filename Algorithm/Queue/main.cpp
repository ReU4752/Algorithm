// https://www.acmicpc.net/problem/10845
// 2018-04-19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Queue
{
  struct Node
  {
    int data;

    Node* next;
  };

public:
  Queue();
  ~Queue();

  void Push(int data);
  int Pop();
  int Size();
  bool IsEmpty();
  int Front();
  int Back();

  void Clear();

private:
  Node* _front;
  Node* _rear;
  int _count;
};

Queue::Queue()
{
  _front = _rear = nullptr;
  _count = 0;
}

Queue::~Queue()
{
  Clear();
}

void Queue::Push(int data)
{
  Node* newNode = new Node;

  newNode->data = data;
  newNode->next = nullptr;

  if (IsEmpty())
  {
    _front = newNode;
  }
  else
  {
    _rear->next = newNode;
  }

  _rear = newNode;
  _count++;
}

int Queue::Pop()
{
  if (!IsEmpty())
  {
    int data = _front->data;

    Node* deleteNode = _front;

    _front = deleteNode->next;

    delete deleteNode;
    deleteNode = nullptr;

    _count--;
    if (0 > _count)
      _count = 0;

    return data;
  }

  return -1;
}

int Queue::Size()
{
  return _count;
}

bool Queue::IsEmpty()
{
  return (_count == 0) ? true : false;
}

int Queue::Front()
{
  if (_front != nullptr && _count > 0)
  {
    return _front->data;
  }

  return -1;
}

int Queue::Back()
{
  if (_rear != nullptr && _count > 0)
  {
    return _rear->data;
  }

  return -1;
}

void Queue::Clear()
{
  Node* deleteNode = _front;

  while (deleteNode != nullptr)
  {
    _front = deleteNode->next;

    delete deleteNode;
    deleteNode = nullptr;
    _count--;

    deleteNode = _front;
  }

  _rear = _front = nullptr;
}

int main()
{
  int numCommand = 0;
  scanf("%d", &numCommand);

  getc(stdin);

  Queue queue;

  char str[30];
  char command[15];
  int arg;
  for (int i = 0; i < numCommand; i++)
  {
    fgets(str, sizeof(str) - 1, stdin);

    sscanf(str, "%s %d", command, &arg);

    if (!strcmp(command, "push"))
    {
      queue.Push(arg);
    }
    else if (!strcmp(command, "pop"))
    {
      printf("%d\n", queue.Pop());
    }
    else if (!strcmp(command, "size"))
    {
      printf("%d\n", queue.Size());
    }
    else if (!strcmp(command, "empty"))
    {
      printf("%d\n", queue.IsEmpty());
    }
    else if (!strcmp(command, "front"))
    {
      printf("%d\n", queue.Front());
    }
    else if (!strcmp(command, "back"))
    {
      printf("%d\n", queue.Back());
    }
  }

  return 0;
}