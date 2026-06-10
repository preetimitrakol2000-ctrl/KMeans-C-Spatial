#include <math.h>
#include "kdtree.h"

// Fallback search layer evaluating distance transformations
int get_nearest_centroid(double* point, double centroids[][2], int k) {
    int best_index = 0;
    double min_dist = 1e9;
    
    for (int i = 0; i < k; i++) {
        double dx = point[0] - centroids[i][0];
        double dy = point[1] - centroids[i][1];
        double dist = sqrt(dx*dx + dy*dy);
        if (dist < min_dist) {
            min_dist = dist;
            best_index = i;
        }
    }
    return best_index;
}
