#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted is lesser, insert in left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert in right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

void left_view(Node* root)
{
	if(root==NULL)
	return;

	queue<Node*> q;
	q.push(root);

	while(q.size())
	{
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			Node* temp=q.front();
			q.pop();
			
			if(i==0)
			cout<<temp->data<<" ";

			if(temp->left!=NULL)
			q.push(temp->left);
			if(temp->right!=NULL)
			q.push(temp->right);
		}
	}
}


int main() 
{
	Node* root = NULL;  // Creating an empty tree

	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	left_view(root);
}
