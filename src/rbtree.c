#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

node_t *new_node(color_t color, key_t key)
{
    node_t *ptr = (node_t*)malloc(sizeof(node_t));
    ptr->color = color;
    ptr->key=key;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->parent=NULL;
    return ptr;
}

rbtree *new_rbtree(void) {
    rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));

    // TODO: initialize struct if needed
    p->nil = new_node(RBTREE_BLACK, 0);
    p->root = p->nil;

    return p;
}

/*
    각각의 노드를 돌며 노드의 메모리를 반환한다.
*/
void delete_node(rbtree *t,node_t *x) {
    if (x->left != t->nil){
        delete_node(t, x->left);
    };
    if (x->right != t->nil) {
        delete_node(t, x->right);
    };
}
/*
    루트에서 삭제를 시작한다.
*/
void delete_rbtree(rbtree *t) {
    // TODO: reclaim the tree nodes's memory
    if (t->root != t->nil){
        delete_node(t,t->root);
    };
    free(t->nil);
    free(t);
}

void left_rotate(rbtree *t, node_t *x);
void right_rotate(rbtree *t, node_t *x);

void insert_fixup(rbtree *t, node_t *z){
    while (z->parent==RBTREE_RED)
    {
        if (z->parent==z->parent->parent->left)
        {
            node_t *y = z->parent->parent->right;
            if (y->color==RBTREE_RED)
            {
                z->parent->color = RBTREE_BLACK;
                y->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z=z->parent;
                    left_rotate(t,z);
                    z->parent->color = RBTREE_BLACK;
                    z->parent->parent->color = RBTREE_RED;
                    right_rotate(t,z->parent->parent);
                }
            }
        }
        else
        {
            node_t *y = z->parent->parent->left;
            if (y->color==RBTREE_RED)
            {
                z->parent->color = RBTREE_BLACK;
                y->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z=z->parent;
                    right_rotate(t,z);
                    z->parent->color = RBTREE_BLACK;
                    z->parent->parent->color = RBTREE_RED;
                    left_rotate(t,z->parent->parent);
                }
            }
        }
    }
    t->root->color = RBTREE_BLACK;
}

void left_rotate(rbtree *t, node_t *x)
{
    node_t *y = x->right;
    x->right = y->left;
    if (y->left != t->nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == t->nil)
    {
        t->root = y;
    }
    else if (x==x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left=x;
    x->parent = y;
}

void right_rotate(rbtree *t, node_t *x)
{
    node_t *y = x->left;
    x->left = y->right;
    if (y->right != t->nil)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == t->nil)
    {
        t->root = y;
    }
    else if (x==x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right=x;
    x->parent = y;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
    // TODO: implement insert
    node_t *z = new_node(RBTREE_RED, key); // key 값을 가지는 노드 생성
    
    node_t *y = t->nil;
    node_t *x = t->root;
    while (x != t->nil)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z ->parent=y;
    if (y==t->nil)
    {
        t->root=z;
    }
    else if (z->key < y->key)
    {
        y->left=z;
    }
    else
    {
        y->right=z;
    }
    z -> left = t->nil;
    z -> right = t->nil;
    insert_fixup(t,z);
    
    return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
    // TODO: implement find
    node_t* p = t->root;
    node_t* tmp = NULL;
    while (p!=t->nil)
    {
        if (p->key == key)
        {
            tmp = p;
            break;
        }
        else if (p ->key > key)
        {
            p = p -> right;
        }
        else
        {
            p = p -> left;
        }
    }
    return tmp;
}

node_t *rbtree_min(const rbtree *t) {
    // TODO: implement find
    return t->root;
}

node_t *rbtree_max(const rbtree *t) {
    // TODO: implement find
    return t->root;
}

int rbtree_erase(rbtree *t, node_t *p) {
    // TODO: implement erase
    return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
    // TODO: implement to_array
    return 0;
}
