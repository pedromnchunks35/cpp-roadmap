#include <iostream>
#include <memory>

class Node
{
public:
    Node(int value) : value(value), prev(nullptr), next(nullptr) {}
    ~Node()
    {
        std::cout << "Destructed" << "\n";
    }
    Node *prev;
    std::unique_ptr<Node> next;
    int value;
};

void addNode(std::unique_ptr<Node> &root, int newValue)
{
    std::unique_ptr<Node> newNode = std::make_unique<Node>(newValue);
    if (root == nullptr)
    {
        root = std::move(newNode);
        return;
    }
    Node *copy = root.get();
    while (copy->next.get() != nullptr)
    {
        copy = copy->next.get();
    }
    newNode->prev = copy;
    copy->next = std::move(newNode);
}

void printList(std::unique_ptr<Node> &root)
{
    if (root == nullptr)
    {
        return;
    }
    Node *copy = root.get();
    while (copy != nullptr)
    {
        std::cout << copy->value << "\n";
        copy = copy->next.get();
    }
}

void removeNode(std::unique_ptr<Node> &root, int itemToRemove)
{
    if (root == nullptr)
    {
        return;
    }
    Node *copy = root.get();
    while (copy != nullptr)
    {
        if (copy->value == itemToRemove)
        {
            copy->next->prev = copy->prev;
            copy->prev->next = std::move(copy->next);
            return;
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
    std::unique_ptr<Node> head = std::make_unique<Node>(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    printList(head);
    removeNode(head, 3);
    printList(head);
    std::cout << std::to_string(countNodes(head)) << "\n";
}
