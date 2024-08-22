#include <iostream>
#include <memory>
class Node
{
public:
    int value;
    std::unique_ptr<Node> next;
    ~Node()
    {
        std::cout << "Destructed" << "\n";
    }
};

void addNode(std::unique_ptr<Node> &root, int newNodeValue)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode.get()->value = newNodeValue;
    if (root == nullptr)
    {
        root = std::move(newNode);
    }
    Node *copy = root.get();
    while (copy->next != nullptr)
    {
        copy = copy->next.get();
    }
    copy->next = std::move(newNode);
}

void printNodes(std::unique_ptr<Node> &root)
{
    Node *copy = root.get();
    while (copy != nullptr)
    {
        std::cout << "value: " << copy->value << "\n";
        copy = copy->next.get();
    }
}

void removeNode(std::unique_ptr<Node> &root, int valueToDelete)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->next == nullptr && root->value)
    {
        root = nullptr;
    }
    Node *copy = root.get();
    while (copy->next != nullptr)
    {
        if (copy->next.get()->value == valueToDelete)
        {
            copy->next = std::move(copy->next->next);
        }
        copy = copy->next.get();
    }
}

int countNodes(std::unique_ptr<Node> &root)
{
    int result = 0;
    if (root == nullptr)
    {
        return result;
    }
    Node *copy = root.get();
    while (copy != nullptr)
    {
        result++;
        copy = copy->next.get();
    }
    return result;
}

int main()
{
    std::unique_ptr<Node> root = nullptr;
    addNode(root, 1);
    addNode(root, 2);
    addNode(root, 3);
    printNodes(root);
    std::cout << "*************" << "\n";
    removeNode(root, 2);
    printNodes(root);
    std::cout << "*************" << "\n";
    std::cout << std::to_string(countNodes(root)) << "\n";
}