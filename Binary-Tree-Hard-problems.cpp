#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void addrightchild(node *&root);

void addleftchild(node *&root)
{
    if (root == NULL)
        return;
    int value;
    string an;
    cout << "do you want to enter the value of left child ";
    cin >> an;
    if (an == "yes")
    {
        cout << "enter the left child value";
        cin >> value;
        root->left = new node(value);
        string anss;
        cout << "do you want to add left child or right child or both  ?";
        cin >> anss;
        if (anss == "left")
        {
            addleftchild(root->left);
        }
        else if (anss == "right")
        {
            addrightchild(root->left);
        }
        else if (anss == "both")
        {
            addleftchild(root->left);
            addrightchild(root->left);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}

void addrightchild(node *&root)
{
    if (root == NULL)
        return;
    int value;
    string a;
    cout << " do you want to enter the value of right child ";
    cin >> a;
    if (a == "yes")
    {
        cout << "enter the right child value";
        cin >> value;

        root->right = new node(value);
        string ansss;
        cout << "do you want to add left child or right child or both  ?";
        cin >> ansss;
        if (ansss == "left")
        {
            addleftchild(root->right);
        }
        else if (ansss == "right")
        {
            addrightchild(root->right);
        }
        else if (ansss == "both")
        {
            addleftchild(root->right);
            addrightchild(root->right);
        }
        else
        {

            return;
        }
    }
    else
    {
        return;
    }
}

// Root To Node Path Problem (Time Complexity - O(N) and Space Complexity - O(N))
bool roottonodepath(node *root, int a, vector<int> &arr)
{

    if (!root)
    {
        return false;
    }

    arr.push_back(root->val);

    if (root->val == a)
    {
        return true;
    }

    if ((roottonodepath(root->left, a, arr)) || (roottonodepath(root->right, a, arr)))
    {
        return true;
    }
    arr.pop_back();

    return false;
}

// Lowest Common Ancestor - O(N) and O(N)
int lca(node *root, int p, int q)
{
    vector<int> res1;
    vector<int> res2;

    if (!roottonodepath(root, p, res1) || !roottonodepath(root, q, res2))
    {
        return -1; // node not found
    }

    int size;

    if (res1.size() >= res2.size())
    {
        size = res2.size();
    }
    else
    {
        size = res1.size();
    }

    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (res1[i] != res2[i])
        {
            break;
        }
        else
        {
            index = i;
        }
    }

    return res1[index];
}

// Children Sum Property O(N) and O(H) H is height of binary tree
void childrensumproperty(node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    int value = root->val;
    int d1;
    int d2;
    if (root->left)
    {
        d1 = root->left->val;
    }

    if (root->right)
    {
        d2 = root->right->val;
    }

    if (d1 + d2 < value)
    {
        if (root->left)
            root->left->val = value;
        if (root->right)
            root->right->val = value;
    }
    else
    {
        root->val = d1 + d2;
    }

    childrensumproperty(root->left);
    childrensumproperty(root->right);

    int tot = 0;
    if (root->left)
    {
        tot += root->left->val;
    }
    if (root->right)
    {
        tot += root->right->val;
    }

    if (root->left or root->right)
    {
        root->val = tot;
    }
}

//Print all nodes at a Distance K 
void kdist(node* root){

}
int main()
{
    string ans;
    int val;
    cout << "Shall we make a Binary Tree?";
    cout << endl;
    cout << "Please reply Yes/No ?";
    cin >> ans;
    if (ans == "Yes")
    {
        cout << "Let's Start making our first Binary Tree";
        cout << "Ok now enter the root value";
        cin >> val;

        node *root = new node(val);

        addleftchild(root);
        addrightchild(root);

        // vector<int> res;
        // int a;
        // // cout << "Enter the element you want to check ";
        // cin >> a;

        int ress = lca(root, 1, 2);
        cout << ress;
    }
    else
    {
        cout << "Thank You for your response!";
    }
}