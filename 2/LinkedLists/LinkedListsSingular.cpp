#include <iostream>
struct Node
{
    Node *next;
    int data;
    Node(int newData) : data(newData), next(nullptr) {}
};
void addMember(Node *&head, int newData);
void removeMember(Node *&head, int toRemove);
void print(Node *head);
int main()
{
    Node *head = new Node(1);
    addMember(head, 2);
    removeMember(head, 1);
    removeMember(head, 2);
    addMember(head, 110);
    print(head);
}
void addMember(Node *&head, int newData)
{
    Node *newNode = new Node(newData);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *copy = head;
    while (copy->next != nullptr)
    {
        copy = copy->next;
    }
    copy->next = newNode;
}
void removeMember(Node *&head, int toRemove)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->data == toRemove)
    {
        head = head->next;
        return;
    }
    Node *before = head;
    Node *copy = head;
    while (copy->next != nullptr)
    {
        before = copy;
        copy = copy->next;
        if (copy->data == toRemove)
        {
            before->next = copy->next;
            delete copy;
        }
    }
}

void print(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *copy = head;
    if (copy != nullptr)
    {
        std::cout << copy->data << "\n";
    }
    while (copy->next != nullptr)
    {
        copy = copy->next;
        std::cout << copy->data << "\n";
    }
}