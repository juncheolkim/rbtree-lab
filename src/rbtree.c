#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  p->root = NULL;
  return p;
}
/*
  각각의 노드를 돌며 노드의 메모리를 반환한다.
*/
void delete_node(node_t *t) {
  if (t->left){
    delete_node(t->left);
  };
  if (t->right) {
    delete_node(t->right);
  };
  free(t);
}
/*
  루트에서 삭제를 시작한다.
*/
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  if (t->root != NULL){
    delete_node(t->root);
    if (t->root->left){
      delete_node(t->root->left);
    };
    if (t->root->right){
      delete_node(t->root->right);
    };
  };
  free(t);
}


node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *p = (node_t *)calloc(1, sizeof(node_t)); \
  p->color = RBTREE_RED;
  p -> key = key;
  p -> left = NULL;
  p -> right = NULL;
  p -> parent = NULL;
  if (t->root == NULL){
    t->root = p;
    p -> color = RBTREE_BLACK;
  };

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  return t->root;
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
