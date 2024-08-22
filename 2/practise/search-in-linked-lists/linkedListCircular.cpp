#include <iostream>
struct Node
{
    int data;
    Node *next;
    Node(int newData) : data(newData), next(nullptr) {}
};
void addMember(Node *&head, int newNumber);
void removeMember(Node *&head, int numberToRemove);
void print(Node *&head);
Node *searchMember(Node *&head, int numberToFind);
int main()
{
    Node *head = new Node(1);
    head->next = head;
    addMember(head, 2);
    addMember(head, 3);
    print(head);
    removeMember(head, 2);
    removeMember(head, 1);
    print(head);
    addMember(head, 4);
    Node *result = searchMember(head, 2);
    std::cout << (result == nullptr ? "Nothing " : std::to_string(result->data)) << "\n";
}
void print(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    std::cout << "**************" << "\n";
    std::cout << "Value: " << head->data << "\n";
    Node *copy = head;
    while (copy->next != head)
    {
        copy = copy->next;
        std::cout << "Value: " << copy->data << "\n";
    }
}
void addMember(Node *&head, int newNumber)
{
    Node *newNode = new Node(newNumber);
    newNode->next = head;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *copy = head;
    while (copy->next != head)
    {
        copy = copy->next;
    }
    copy->next = newNode;
}
void removeMember(Node *&head, int numberToRemove)
{
    if (head == nullptr)
    {
        return;
    }
    if (head->data == numberToRemove)
    {
        if (head->next == head)
        {
            return;
        }
        head = head->next;
        head->next = head;
        return;
    }
    Node *before = head;
    Node *copy = head;
    while (copy->next != nullptr)
    {
        before = copy;
        copy = copy->next;
        if (copy->data == numberToRemove)
        {
            Node *temp = copy->next;
            before->next = copy->next;
            delete copy;
            copy = temp;
            return;
        }
    }
}
Node *searchMember(Node *&head, int memberToFind)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->data == memberToFind)
    {
        return head;
    }
    Node *copy = head;
    while (copy->next != head)
    {
        copy = copy->next;
        if (copy->data == memberToFind)
        {
            return copy;
        }
    }
    return nullptr;
}