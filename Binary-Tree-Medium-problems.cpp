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
        left = nullptr;
        right = nullptr;
    }
};

// Maximum Depth of Height of Binary Tree 
int maxdepth(node *root)
{
    if (root == NULL)
        return 0;

    int l = maxdepth(root->left);
    int r = maxdepth(root->right);
     
 
    return 1 + max(l, r);
}


// Is Balanced Tree or not with O(n*2)
bool isbalancedbt(node* root){
    if(root == nullptr){
        return true;
    }

    int l = maxdepth(root->left);
    int r = maxdepth(root->right);

    if(abs(l-r) > 1 ) return false;

    bool left = isbalancedbt(root->left);
    bool right = isbalancedbt(root->right);

    if(left || right ) return false;

    return true;
}


// is balanced with O(n)
int isbalancedbt_optimal(node *root)
{
    if (root == NULL)
        return 0;

    int l = isbalancedbt_optimal(root->left);
    int r = isbalancedbt_optimal(root->right);
    if(l == -1 || r == -1 ) return -1;
if(abs(l - r ) > 1 ) return -1;
    return 1 + max(l, r);
}


// Diameter is longest path  between two nodes and finding diameter of a binary tree
// it is the max (l , r)
//O(n*2)
int diameter(node* root){
    if(root == nullptr){
        return;
    }
    
    int l = maxdepth(root->left);
    int r = maxdepth(root->right);

    int maxi = max(maxi,l+r);

    diameter(root->left);
    diameter(root->right);

    return maxi;
}
//O(n)
int find_max_diameter(node* root,int maxi){
if (root == NULL)
        return 0;

    int l = find_max_diameter(root->left,maxi);
    int r = find_max_diameter(root->right,maxi);
    maxi = max(maxi,l+r);
 
    return 1+max(l,r) ;
}



//Maximum Path sum 
int maxsum(node* root,int maxi){
    if(root == nullptr){
        return 0;
    }
    int leftsum =max(0, maxsum(root->left,maxi));
    
    int rightsum = max(0,maxsum(root->right,maxi));
 maxi = max(maxi,leftsum+rightsum+root->val);
 return (root->val)+ max(leftsum,rightsum);
}


//Same Tree or NOT
// if same traversal then same  



//Symmetric Binary Tree or NOT ?
//To determine if a tree is a mirror image of itself, you pass the left subtree and the right subtree into a recursive function. You then perform a standard Preorder Traversal (Root → Left → Right) on the left subtree, while simultaneously performing a Mirrored Preorder Traversal (Root → Right → Left) on the right subtree


int main()
{
}