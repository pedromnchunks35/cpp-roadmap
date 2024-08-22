#include <iostream>
struct Node
{
    int data;
    Node *next;
    Node(int newValue) : data(newValue), next(nullptr) {};
};
void addMember(Node *&head, int newMember);
void removeMember(Node *&head, int memberToRemove);
Node *searchNode(Node *&head, int memberToReturn);
int main()
{
    Node *head = new Node(1);
    addMember(head, 2);
    addMember(head, 3);
    addMember(head, 10);
    Node *result = searchNode(head, 3);
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
    while (copy->next != nullptr)
    {
        copy = copy->next;
    }
    copy->next = newNode;
}
void removeMember(Node *&head, int memberToRemove)
{
    Node *before = head;
    Node *copy = head;
    while (copy != nullptr)
    {
        if (copy->data == memberToRemove)
        {
            before->next = copy->next;
            delete copy;
            return;
        }
        before = copy;
        copy = copy->next;
    }
}
Node *searchNode(Node *&head, int member)
{
    Node *copy = head;
    while (copy != nullptr)
    {
        if (copy->data == member)
        {
            return copy;
        }
        copy = copy->next;
    }
    return nullptr;
}