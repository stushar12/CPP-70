void abc(Node * root,vector<int> &v,int level,int &maxlevel)
{
    if(root==NULL)
    return ;
    else
    {  
        if(maxlevel<level)
        {
              v.push_back(root->data);
              maxlevel=level;
        }
        abc(root->left,v,level+1,maxlevel);
  
        abc(root->right,v,level+1,maxlevel);
    }
}
vector<int> leftView(Node *root)
{
   vector<int> v;
   int level=1;
   int maxlevel=0;
   abc(root,v,1,maxlevel);
   return v;
}