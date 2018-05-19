#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct BinNode{
    int data;
    BinNode* left;
    BinNode* right;
};

// this is the DFS version
void preOrder(BinNode* root){
    if(root){
        stack<BinNode*> stack;
        stack.push(root);
        while(stack.size()){
            BinNode* node=stack.top();
            stack.pop();
            cout<<node->data<<" ";
            if(node->right)
                stack.push(node->right);
            if(node->left)
                stack.push(node->left);
        }
    }
    cout<<endl;
}

// this is the textbook's version
void preOrder2(BinNode* root){
    stack<BinNode*> stack;
    while(root || stack.size()){
        while(root){
            cout<<root->data<<" ";
            stack.push(root);
            root=root->left;
        }
        root=stack.top();
        stack.pop();
        root=root->right;
    }
    cout<<endl;
}

// this is the textbook's version
void midOrder2(BinNode* root){
    stack<BinNode*> stack;
    while(root || stack.size()){
        while(root){
            stack.push(root);
            root=root->left;
        }
        root=stack.top();
        stack.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
    cout<<endl;
}

// this is the textbook's version
void postOrder2(BinNode* root){
    stack<BinNode*> stack;
    BinNode* last=nullptr;
    while(root || stack.size()){
        while(root){
            stack.push(root);
            root=root->left;
        }
        root=stack.top();
        // now root is the leftmost
        if(root->right==nullptr || root->right==last){
            cout<<root->data<<" ";
            last=root;
            stack.pop();
            root=nullptr;
        }else{
            root=root->right;
        }
    }
    cout<<endl;
}

// this is my own version after understanding what exactly is going on in this algorithm
void preOrder3(BinNode* root){
    stack<BinNode*> stack;
    while(root || stack.size()){
        if(root){
            cout<<root->data<<" ";
            stack.push(root);
            root=root->left;
        }else{
            root=stack.top();
            stack.pop();
            root=root->right;
        }
    }
    cout<<endl;
}

// this is my own version after understanding what exactly is going on in this algorithm
void midOrder3(BinNode* root){
    stack<BinNode*> stack;
    while(root || stack.size()){
        if(root){
            stack.push(root);
            root=root->left;
        }else{
            root=stack.top();
            stack.pop();
            cout<<root->data<<" ";
            root=root->right;
        }
    }
    cout<<endl;
}

// this is my own version after understanding what exactly is going on in this algorithm
void preOrder4(BinNode* root){
    stack<BinNode*> stack;
    while(root || stack.size()){
        if(root){
            cout<<root->data<<" ";
            if(root->right)
                stack.push(root->right);
            if(root->left)
                stack.push(root->left);
            root=nullptr; // important! so the next loop it'll pick the stack.top() as new root.
        }else{
            // due to the while loop, here #stack must >0
            root=stack.top();
            stack.pop();
        }
    }
    cout<<endl;
}

int main()
{
    BinNode n7={7, nullptr, nullptr};
    BinNode n8={8, nullptr, nullptr};
    BinNode n6={6, &n7, &n8};
    BinNode n4={4, nullptr, &n6};
    BinNode n2={2, &n4, nullptr};
    BinNode n5={5, nullptr, nullptr};
    BinNode n3={3, nullptr, &n5};
    BinNode n1={1, &n2, &n3};
    BinNode n0={0, nullptr, &n1};

    cout<<"Preorder1 (DFS):"<<endl;
    preOrder(&n0);

    cout<<"Preorder2 (Textbook):"<<endl;
    preOrder2(&n0);

    cout<<"Preorder3 (Own):"<<endl;
    preOrder3(&n0);

    cout<<"Preorder4 (Own):"<<endl;
    preOrder4(&n0);

    cout<<"Midorder2 (Textbook):"<<endl;
    midOrder2(&n0);

    cout<<"Midorder3 (Own):"<<endl;
    midOrder3(&n0);

    cout<<"Postorder2 (Textbook):"<<endl;
    postOrder2(&n0);

    cout<<"All done!"<<endl;

    return 0;
}
