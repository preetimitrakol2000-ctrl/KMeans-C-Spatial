#define KDTREE_H

typedef struct KDNode {
    double point[2]; // Coordinates: [x, y]
    int point_index;
    struct KDNode* left;
    struct KDNode* right;
} KDNode;

KDNode* insert_kd_node(KDNode* root, double* point, int index, int depth);
void free_kd_tree(KDNode* root);

#endif
