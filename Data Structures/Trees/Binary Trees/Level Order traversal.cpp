// Time Complexity: O(n)
// Memory Complexity: O(w) where w = width of the tree
// Level Order traversal of a binary tree

vector<ll> levelOrder(BT *root)
{
    vector<ll> levelOrderNodes;
    queue<BT *> qe;

    if (root)
    {
        qe.push(root);
    }

    while (!qe.empty())
    {
        auto p = qe.front();
        qe.pop();

        levelOrderNodes.push_back(p->data);

        if (p->left)
        {
            qe.push(p->left);
        }

        if (p->right)
        {
            qe.push(p->right);
        }
    }

    return levelOrderNodes;
}

---------------------------------------
Application:
https://cses.fi/problemset/task/3359/
