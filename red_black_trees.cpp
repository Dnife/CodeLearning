#include <string>
#include <iostream>

struct trees_node
{
    /* data */
    int value = 0;
    bool isRed = true;//red = 0; black = 1;
    trees_node * left_ptr;
    trees_node * right_ptr;
    trees_node * father_ptr;
    trees_node(int x): value(x), isRed(true), left_ptr(nullptr), right_ptr(nullptr), father_ptr(nullptr){};
};

class RedBlackTree{

    private:
    trees_node * root = nullptr;
    trees_node * cur, * pre;
    
    void find_position(int value){
        if (cur){
            if (value < cur->value)
            {
                cur = cur->left_ptr;
            }
            else if(value > cur->value)
            {
                cur = cur->right_ptr;
            }
            find_position(value);
        }
    }


    public:
    trees_node* addnode(int value){
        if (!root)
        {
            root = new trees_node(value);
            cur = root;
            pre = root->father_ptr;
        }
        else{
            trees_node *tmp = new trees_node(value);
            find_position(value);
            if (value < cur->value && !cur->left_ptr)
            {
                cur->left_ptr = tmp;
            }            
            else if (value > cur->value && !cur->right_ptr)
            {
                cur->right_ptr = tmp;
            }
        }
        
        return root;
    }

    int isMatch(trees_node* test_node){
        if (!test_node->father_ptr && test_node->isRed)
        {
            //error: root is red
            root->isRed = false;
        }
        
        return 0;
    }

    trees_node * restruct(int err){
        switch (err)
        {
        case 0:
            /* code */
            break;
        case 1:
            
        default:
            break;
        }
        
        return root;
    }
};
