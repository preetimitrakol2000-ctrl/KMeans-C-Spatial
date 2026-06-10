#include <stdio.h>
#include "kdtree.h"

extern int get_nearest_centroid(double* point, double centroids[][2], int k);

int main() {
    printf("📊 Initializing Spatial-Accelerated KMeans-C-Spatial Clustering Node...\n\n");

    double dataset[4][2] = {
        {1.2, 1.5}, {2.0, 2.2}, {8.5, 9.0}, {9.1, 9.5}
    };
    
    double centroids[2][2] = {
        {1.0, 1.0}, // Initial Centroid 0
        {10.0, 10.0} // Initial Centroid 1
    };

    KDNode* spatial_root = NULL;
    for (int i = 0; i < 4; i++) {
        spatial_root = insert_kd_node(spatial_root, dataset[i], i, 0);
    }

    printf("🎯 Target Cluster Partition Mapping Logs:\n");
    for (int i = 0; i < 4; i++) {
        int cluster_id = get_nearest_centroid(dataset[i], centroids, 2);
        printf("   • Node Coordinate Point Data (%.1f, %.1f) -> Assigned Centroid ID: %d\n", 
                dataset[i][0], dataset[i][1], cluster_id);
    }

    free_kd_tree(spatial_root);
    return 0;
}
