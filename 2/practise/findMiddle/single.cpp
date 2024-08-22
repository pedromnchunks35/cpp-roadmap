#include <iostream>
#include <memory>
class Node
{
public:
    Node(int newValue) : value(newValue)
    {
    }
    ~Node()
    {
        std::cout << "Destructed" << "\n";
    }
    int value;
    std::unique_ptr<Node> next;
};
void addNode(std::unique_ptr<Node> &root, int newValue);
void printList(std::unique_ptr<Node> &root);
void removeMember(std::unique_ptr<Node> &root, int itemToRemove);
Node *getMiddleMember(std::unique_ptr<Node> &root);
int main()
{
    std::unique_ptr<Node> root = std::make_unique<Node>(1);
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 4);
    addNode(root, 5);
    printList(root);
    std::cout << "***********" << "\n";
    removeMember(root, 4);
    printList(root);
    std::cout << "****************" << "\n";
    std::cout << std::to_string(getMiddleMember(root)->value) << "\n";
}
void addNode(std::unique_ptr<Node> &root, int newValue)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(newValue);
    if (root == nullptr)
    {
        root = std::move(newNode);
        return;
    }
    Node *point = root.get();
    while (point->next != nullptr)
    {
        point = point->next.get();
    }
    point->next = std::move(newNode);
}
void printList(std::unique_ptr<Node> &root)
{
    if (root == nullptr)
    {
        return;
    }
    Node *point = root.get();
    while (point != nullptr)
    {
        std::cout << point->value << "\n";
        point = point->next.get();
    }
}
void removeMember(std::unique_ptr<Node> &root, int itemToRemove)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->value == itemToRemove)
    {
        root = std::move(root->next);
        return;
    }
    Node *point = root.get();
    while (point->next != nullptr)
    {
        if (point->next->value == itemToRemove)
        {
            point->next = std::move(point->next->next);
            return;
        }
        point = point->next.get();
    }
}
Node *getMiddleMember(std::unique_ptr<Node> &root)
{
    int count = 0;
    if (root == nullptr)
    {
        return nullptr;
    }
    Node *point = root.get();
    while (point != nullptr)
    {
        count++;
        point = point->next.get();
    }
    int n = count / 2;
    n = (n % 2 == 0 ? n - 1 : n);
    int tempCount = 0;
    point = root.get();
    while (n != tempCount)
    {
        tempCount++;
        point = point->next.get();
    }
    return point;
}