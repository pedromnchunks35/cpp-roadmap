#include <iostream>
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int newData) : data(newData), prev(nullptr), next(nullptr) {}
};

void addMember(Node *&head, int newMember);
void removeMember(Node *&head, int memberToRemove);
Node *searchMember(Node *&head, int memberToSearch);
void print(Node *&head);
int main()
{
    Node *head = new Node(1);
    addMember(head, 2);
    addMember(head, 4);
    addMember(head, 6);
    print(head);
    Node *result = searchMember(head, 4);
    std::cout << result->data << "\n";
}
void addMember(Node *&head, int newMember)
{
    Node *newNode = new Node(newMember);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *copy = head;
    while (copy != nullptr)
    {
        if (copy->next == nullptr)
        {
            newNode->prev = copy;
            copy->next = newNode;
            return;
        }
        copy = copy->next;
    }
}
void removeMember(Node *&head, int memberToRemove)
{
    Node *before = head;
    Node *copy = head;
    while (copy != nullptr)
    {
        if (copy->data == memberToRemove)
        {
            if (before != nullptr)
            {
                before->next = copy->next;
            }
            if (copy->next != nullptr)
            {
                copy->next->prev = before;
            }
            Node *temp = copy->next;
            delete copy;
            copy = temp;
            return;
        }
        copy = copy->next;
    }
}
Node *searchMember(Node *&head, int memberToSearch)
{
    Node *copy = head;
    while (copy != nullptr)
    {
        if (copy->data == memberToSearch)
        {
            return copy;
        }
        copy = copy->next;
    }
    return nullptr;
}
void print(Node *&head)
{
    Node *copy = head;
    while (copy != nullptr)
    {
        std::cout << copy->data << "\n";
        copy = copy->next;
    }
}