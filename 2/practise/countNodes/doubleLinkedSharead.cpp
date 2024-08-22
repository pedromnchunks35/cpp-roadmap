#include <iostream>
#include <memory>
class Node
{
public:
    Node(int newValue) : next(nullptr), value(newValue) {}
    ~Node()
    {
        std::cout << "Destructed" << "\n";
    }
    std::weak_ptr<Node> prev;
    std::shared_ptr<Node> next;
    int value;
};
void addNode(std::shared_ptr<Node> &root, int newValue)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>(newValue);
    if (root == nullptr)
    {
        newNode->prev = root;
        root = std::move(newNode);
        return;
    }
    std::shared_ptr point = root;
    while (auto nextVal = point->next)
    {
        point = nextVal;
    }
    newNode->prev = point;
    point->next = std::move(newNode);
}
void printNode(std::shared_ptr<Node> &root)
{
    if (root == nullptr)
    {
        return;
    }
    std::shared_ptr<Node> point = root;
    while (point != nullptr)
    {
        std::cout << point->value << "\n";
        point = point->next;
    }
}
int main()
{
    std::shared_ptr<Node> root = std::make_shared<Node>(1);
    addNode(root, 2);
    addNode(root, 3);
    printNode(root);
}
