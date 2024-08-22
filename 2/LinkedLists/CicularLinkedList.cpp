#include <iostream>
struct Node
{
    int data;
    Node *next;
    Node(int newData) : data(newData), next(nullptr) {}
};
void addNewMember(Node *&head, int newMember);
void removeMember(Node *&head, int memberToRemove);
void print(Node *&head);
bool checkIfLooped(Node *&head);
int main()
{
    Node *head = new Node(1);
    head->next = head;
    addNewMember(head, 2);
    addNewMember(head, 10);
    removeMember(head, 10);
    print(head);
    std::cout << checkIfLooped(head) << "\n";
}
void addNewMember(Node *&head, int newMember)
{

    Node *newNode = new Node(newMember);
    newNode->next = head;
    if (!head)
    {
        head->next = newNode;
        return;
    }
    if (head->next == head)
    {
        head->next = newNode;
        return;
    }
    Node *copy = head;
    while (copy->next != head)
    {
        copy = copy->next;
    }
    copy->next = newNode;
}
void removeMember(Node *&head, int memberToRemove)
{
    Node *copy = head;
    if (copy->next == head)
    {
        return;
    }
    Node *before = copy;
    while (copy->next != head)
    {
        before = copy;
        copy = copy->next;
        if (copy->data == memberToRemove)
        {
            before->next = copy->next;
            delete copy;
            break;
        }
    }
}
bool checkIfLooped(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
void print(Node *&head)
{
    Node *copy = head;
    while (copy->next != head)
    {
        std::cout << copy->data << "\n";
        copy = copy->next;
    }
    std::cout << copy->data << "\n";
}