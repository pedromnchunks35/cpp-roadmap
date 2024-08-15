#include <iostream>
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int newData) : data(newData), prev(nullptr), next(nullptr) {}
};
void addMember(Node *&head, const int newMember);
void remMember(Node *&head, const int revMember);
void print(Node *&head);
int main()
{
    Node *head = new Node(1);
    addMember(head, 2);
    addMember(head, 10);
    print(head);
    remMember(head, 2);
    print(head);
    remMember(head, 10);
    print(head);
    remMember(head, 1);
    print(head);
    addMember(head, 100);
    print(head);
    addMember(head, 2);
    remMember(head, 100);
    print(head);
}
void addMember(Node *&head, const int newMember)
{
    Node *newNode = new Node(newMember);
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
    newNode->prev = copy;
    copy->next = newNode;
}
void remMember(Node *&head, const int revMember)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->data == revMember)
    {
        Node *next = head->next;
        delete head;
        head = next;
        head->prev == nullptr;
        return;
    }
    Node *copy = head;
    while (copy->next != nullptr)
    {
        copy = copy->next;
        if (copy->data == revMember)
        {
            if (copy->next != nullptr)
            {
                copy->next->prev = copy->prev;
            }
            copy->prev->next = copy->next;
            delete copy;
        }
    }
}
void print(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    std::cout << "***********" << "\n";
    std::cout << "Prev: " << "NULL " << " Current: " << head->data << "\n";
    Node *copy = head;
    while (copy->next != nullptr)
    {
        copy = copy->next;
        std::cout << "Prev: " << copy->prev->data << " Current: " << copy->data << "\n";
    }
}