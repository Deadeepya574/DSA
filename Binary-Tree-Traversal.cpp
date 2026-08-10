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

void print_preorder_recursive_traversal(node *root)
{
    if (root == nullptr)
    { 
        return;
    }

    cout << root->val << " ";
    print_preorder_recursive_traversal(root->left);
    print_preorder_recursive_traversal(root->right);
}

void print_inorder_recursive_traversal(node *root)
{
    if (root == nullptr)
    { 
        return;
    }
    print_inorder_recursive_traversal(root->left);
    cout << root->val << " ";

    print_inorder_recursive_traversal(root->right);
}

void print_postorder_recursive_traversal(node *root)
{
    if (root == nullptr)
    { 
        return;
    }

    print_postorder_recursive_traversal(root->left);
    print_postorder_recursive_traversal(root->right);
    cout << root->val << " ";
}

void print_level_order_recursive_traversal(node* root){
    if(root==nullptr){
        return  ;
    }
    queue<node*> q;
     
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            node* curr= q.front();
            q.pop();
            cout << curr->val << " ";
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
        
    }
    

}

void print_preorder_iterative_traversal(node* root){
    
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
        print_level_order_recursive_traversal(root);
    }
    else
    {
        cout << "Thank You for your response!";
    }
}