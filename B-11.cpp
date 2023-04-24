//		B-11

#include <iostream>
using namespace std;
class Node
{

public:
    string key;
    string mean;
    Node *left;
    Node *right;
    Node(string k,string m)
    {
        key=k;
        mean=m;
        left = NULL;
        right = NULL;
    }
};
class BST
{
public:
    Node *insertToBst(Node *root, string keyW,string meaning)
    {

        if (root == NULL)
        {
            root = new Node(keyW,meaning);
            return root;
        }

        if (keyW > root->key)
        {

            root->right = insertToBst(root->right, keyW , meaning);
            return root;
        }
        else
        {

            root->left = insertToBst(root->left, keyW , meaning);
            return root;
        }
    }

    void create(Node *&root)
    {
        string keyW;
        string meaning;
        cout << "Enter keyword to insert in BST (if not enter no) : " << endl;
        cin >> keyW;
        cout<<"Enter meaning of above keyword (if not enter no) :"<<endl;
        cin>>meaning;
        while (keyW !="no" && meaning != "no")
        {
            
            root = insertToBst(root, keyW , meaning);
            cout << "Enter keyword to insert in BST (if not enter no) : " << endl;
            cin >> keyW;
            cout<<"Enter meaning of above keyword (if not enter no) :"<<endl;
            cin>>meaning;
            
        }
    }
    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->key << ":"<<root->mean<<" ";
        inOrder(root->right);
    }
    Node *search(Node *root, string keyW)
    {

        if (root == NULL)
            return NULL;
        if (root->key == keyW)
            return root;

        if (root->key < keyW)
            return search(root->right, keyW);

        else
        {

            return search(root->left, keyW);
        }
    }
   void update(Node* root){
            
            Node* p;
            string k;
            string newMeaning;
            cout<<"Enter which key meaning to update :"<<endl;
            cin>>k;
            p=search(root, k);
            if (p == NULL)
                cout << "\nElement not present in BST";
            else{
                
                cout<<"Enter new meaning  : "<<endl;
                cin>>newMeaning;
                p->mean=newMeaning;
                
            }
   }
   //find min
    Node *findMin(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
   //delete key 
    Node *deleteNode(Node *node, string key)
{
    if (node == NULL) // Base case: empty tree or key not found
        return node;

    if (key < node->key) // Search in the left subtree
        node->left = deleteNode(node->left, key);
    else if (key > node->key) // Search in the right subtree
        node->right = deleteNode(node->right, key);
    else // Node with the key to be deleted is found
    {
        // Case 1: Node has no children
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        // Case 2: Node has one child
        else if (node->left == NULL)
        {
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == NULL)
        {
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        // Case 3: Node has two children
        else
        {
            Node *temp = findMin(node->right);
            node->key = temp->key;
            node->mean = temp->mean;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    return node;
}


//max comparison
  int maxComparisons(Node* root, string keyW, int& count) {
    if (root == NULL) {
        return count;
    }
    count++;
    if (root->key == keyW) {
        return count;
    }
    if (root->key < keyW) {
        return maxComparisons(root->right, keyW, count);
    }
    else {
        return maxComparisons(root->left, keyW, count);
    }
}

    
};

int main()
{
    BST b;
    string key;
    Node *root = NULL;
    Node *p;
    int ch;
    int count = 0;
    
  do{
    {   
        cout << "\n**********MENU**********" << endl;
        cout << "\n1.Create\n2.Insert\n3.Inorder\n4.Search\n5.update\n6.Delete key\n7.Maximum comparisons\n8.Exit\n";
        cout << "\nEnter a choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:

            b.create(root);
            break;
        case 2:
    {
        string newKey, newMeaning;
        cout << "Enter the keyword to add: ";
        cin >> newKey;
        cout << "Enter the meaning of the keyword: ";
        cin >> newMeaning;
        
        root = b.insertToBst(root, newKey, newMeaning);
        cout << "\nKeyword added successfully!";
        break;
    }
        case 3:
            b.inOrder(root);
            break;
        case 4:
            cout << "\nEnter key to be searched : ";
            cin >> key;
            p = b.search(root, key);
            if (p == NULL)
                cout << "\nElement not found";
            else
                cout << "\nElement found :" << p->key;
            break;
        
        case 5:
            b.update(root);
            break;
        case 6:
            cout << "Enter key to be deleted : ";
            cin >> key;
            root = b.deleteNode(root, key);
            break;
        
        case 7:
            cout << "\nEnter key to find maximum comparisons: ";
            cin >> key;
            
            int maxCount;
            maxCount = b.maxComparisons(root, key, count);
            if (maxCount == 0) {
                cout << "\nElement not found";
            }
            else {
                cout << "\nMaximum comparisons required to find " << key << " is " << maxCount;
            }
            break;
        case 8:
            exit(1);
        }
    }
  }while(true);
   
    
    return 0;
}
