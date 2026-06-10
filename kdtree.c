#include <stdlib.h>
#include <string.h>
#include "kdtree.h"

KDNode* insert_kd_node(KDNode* root, double* point, int index, int depth) {
    if (root == NULL) {
        KDNode* node = (KDNode*)malloc(sizeof(KDNode));
        node->point[0] = point[0];
        node->point[1] = point[1];
        node->point_index = index;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    int axis = depth % 2; // Cycle through dimensions: X (0) and Y (1)
    if (point[axis] < root->point[axis]) {
        root->left = insert_kd_node(root->left, point, index, depth + 1);
    } else {
        root->right = insert_kd_node(root->right, point, index, depth + 1);
    }
    return root;
}

void free_kd_tree(KDNode* root) {
    if (root == NULL) return;
    free_kd_tree(root->left);
    free_kd_tree(root->right);
    free(root);
}
