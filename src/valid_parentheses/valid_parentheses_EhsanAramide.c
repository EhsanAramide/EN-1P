#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// * typedefs
typedef struct LinkedListNode LinkedListNode;
typedef struct LinkedList LinkedList;
typedef struct Stack Stack;

// * Linked List Implementation
struct LinkedListNode
{
    char value;
    LinkedListNode* next;
};

struct LinkedList
{
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
};

LinkedListNode* listNodeInit(char value, LinkedListNode* next)
{
    LinkedListNode* node = (LinkedListNode*)calloc(1, sizeof(LinkedListNode));
    node->value = value;
    node->next = next;
    return node;
}

LinkedList* listInit()
{
    LinkedList* list = (LinkedList*)calloc(1, sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void listAddFirst(LinkedList* list, char value)
{
    LinkedListNode* node = listNodeInit(value, list->head);
    list->head = node;
    (list->size)++;
    if (list->size == 1)
    {
        list->tail = list->head;
    }
}

void listAddLast(LinkedList* list, char value)
{
    LinkedListNode* node = listNodeInit(value, NULL);
    (list->size)++;
    if (list->size == 1)
    {
        list->tail = node;
        list->head = list->tail;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

char listRemoveFirst(LinkedList* list)
{
    LinkedListNode* node = list->head;
    list->head = node->next;
    char value = node->value;
    free(node);
    (list->size)--;
    return value;
}

// * Stack Implementation
struct Stack
{
    LinkedList* list;
};

Stack* stackInit()
{
    Stack* stack = (Stack*)calloc(1, sizeof(Stack));
    stack->list = listInit();
    return stack;
}

char stackFirst(Stack* stack)
{
    return stack->list->head->value;
}

void stackPush(Stack* stack, char value)
{
    listAddFirst(stack->list, value);
}

char stackPop(Stack* stack)
{
    return listRemoveFirst(stack->list);
}

int stackSize(Stack* stack)
{
    return stack->list->size;
}

int strichr(char* str, char c)
{

    for (int index = 0; *str != '\0'; str++, index++)
    {
        if (*str == c)
        {
            return index;
        }
    }
    return -1;
}

char* openP = "([{";
char* closeP = ")]}";

bool isValid(char* s)
{
    Stack* stack = stackInit();
    while (*s != '\0')
    {
        int index = strichr(openP, *s);
        if (index != -1)
        {
            stackPush(stack, *s);
        }
        else
        {
            index = strichr(closeP, *s);
            if (stackSize(stack) == 0 || index != strichr(openP, stackPop(stack)))
            {
                return false;
            }
        }
        s++;
    }
    return stackSize(stack) == 0 ? true : false;
}

int main(int argc, char const* argv[])
{
    char* s = "{}[[[]]]";
    printf("is %s valid? %s\n", s, isValid(s) ? "true" : "false");
    return 0;
}
