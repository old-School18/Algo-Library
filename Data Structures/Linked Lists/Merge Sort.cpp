// Time Complexity: O(nlogn)
// Memory Complexity: O(logn) Recursive stack
// Merge sort algorithm for linked lists

Node *tortoiseHare(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *mergedListHead = new Node(-1);
    Node *temp = mergedListHead;

    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left != nullptr)
    {
        temp->next = left;
    }
    if (right != nullptr)
    {
        temp->next = right;
    }

    return mergedListHead->next;
}

Node *mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *middleNode = tortoiseHare(head);
    Node *left = head;
    Node *right = middleNode->next;
    middleNode->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
