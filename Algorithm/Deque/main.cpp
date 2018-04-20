// https://www.acmicpc.net/problem/10866
// 2018-04-20

#include <stdio.h>
#include <string.h>

class Deque
{
  struct NODE
  {
    int data;

    NODE* next;
    NODE* prev;
  };

public:
  Deque();
  ~Deque();

  void Push_Front(int data);
  void Push_Back(int data);
  int Pop_Front();
  int Pop_Back();
  int Size();
  bool IsEmpty();
  int Front();
  int Back();
  void Clear();

private:
  NODE* _head;
  NODE* _tail;
  int _size;
};

Deque::Deque()
{
  _head = _tail = nullptr;
  _size = 0;
}

Deque::~Deque()
{
  // 해제를 위해 이 메소드를 호출하면, 답이 아니라고 출력합니다(시간초과).
  // 그래서 일단 주석처리 했습니다.
  // When I call the method for release, it outputs that it is the incorrect answer(timeout). 
  // So I comment out for now.
  // Clear();
}

void Deque::Push_Front(int data)
{
  NODE* newNode = new NODE;

  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  
  if (IsEmpty())
    _tail = newNode;
  else
  {
    _head->next = newNode;
    newNode->prev = _head;
  }

  _head = newNode;
  _size++;
}

void Deque::Push_Back(int data)
{
  NODE* newNode = new NODE;

  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (IsEmpty())
    _head = newNode;
  else
  {
    _tail->prev = newNode;
    newNode->next = _tail;
  }

  _tail = newNode;
  _size++;
}

int Deque::Pop_Front()
{
  if (!IsEmpty())
  {
    int data = _head->data;

    NODE* deleteNode = _head;
    _head = _head->prev;

    delete deleteNode;
    deleteNode = nullptr;

    _size--;

    return data;
  }

  return -1;
}

int Deque::Pop_Back()
{
  if (!IsEmpty())
  {
    int data = _tail->data;

    NODE* deleteNode = _tail;
    _tail = _tail->next;

    delete deleteNode;
    deleteNode = nullptr;

    _size--;

    return data;
  }

  return -1;
}

int Deque::Size()
{
  return _size;
}

bool Deque::IsEmpty()
{
  return (_size == 0) ? true : false;
}

int Deque::Front()
{
  if (!IsEmpty())
    return _head->data;

  return -1;
}

int Deque::Back()
{
  if (!IsEmpty())
    return _tail->data;

  return -1;
}

void Deque::Clear()
{
  NODE* deleteNode = _head;

  while (deleteNode != nullptr)
  {
    _head = _head->prev;

    delete deleteNode;
    deleteNode = nullptr;

    _size--;

    deleteNode = _head;
  }
}

int main()
{
  int numCommand = 0;

  scanf("%d", &numCommand);

  getc(stdin);

  Deque deque;

  char str[22];
  char command[12];
  int arg;
  for (int i = 0; i < numCommand; i++)
  {
    fgets(str, sizeof(str) - 1, stdin);

    sscanf(str, "%s %d", command, &arg);

    if (!strcmp(command, "push_front"))
    {
      deque.Push_Front(arg);
    }
    else if (!strcmp(command, "push_back"))
    {
      deque.Push_Back(arg);
    }
    else if (!strcmp(command, "pop_front"))
    {
      printf("%d\n", deque.Pop_Front());
    }
    else if (!strcmp(command, "pop_back"))
    {
      printf("%d\n", deque.Pop_Back());
    }
    else if (!strcmp(command, "size"))
    {
      printf("%d\n", deque.Size());
    }
    else if (!strcmp(command, "empty"))
    {
      printf("%d\n", deque.IsEmpty());
    }
    else if (!strcmp(command, "front"))
    {
      printf("%d\n", deque.Front());
    }
    else if (!strcmp(command, "back"))
    {
      printf("%d\n", deque.Back());
    }
  }

  return 0;
}