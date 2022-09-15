#include "gradient.h"

path_point find_highest_point(){

    int i, j;
    int view_row, view_column;
    int startview_x, startview_y;
    int edge_x, edge_y;
    int peak_x, peak_y;
    int check_peak;
    path_point user_center;
    float user_view[VIEW_SIZE][VIEW_SIZE];    
    
    user_center.x = VIEW_RADIUS;
    user_center.y = VIEW_RADIUS;

    // Find x size of the map
    int find_edge = 0;
    while(1) {
        generate_view(user_view, user_center.y, user_center.x);
        i = 0;
        while (1) {
            if (user_view[0][VIEW_RADIUS+i] == -1) {
                edge_x = user_center.x + i;
                // printf("edge_x: %d\n", edge_x);
                find_edge = 1;
                break;
            }
            if (i == VIEW_RADIUS) {
                break;
            }
            i++;
        }
        if (find_edge == 1) {
            break;
        }
        user_center.x = user_center.x + VIEW_RADIUS;

        // to avoid infinite loop
        if (user_center.x > 1000) {
            user_center.x = VIEW_RADIUS;
            user_center.y = VIEW_RADIUS;
            printf("fail to find an edge\n");
            return user_center;  
        }
    }
    
    find_edge = 0;
    while(1) {
        generate_view(user_view, user_center.y, user_center.x);
        i = 0;
        while (1) {
            if (user_view[VIEW_RADIUS+i][0] == -1) {
                edge_y = user_center.y + i;
                // printf("edge_y: %d\n", edge_y);
                find_edge = 1;
                break;
            }
            if (i == VIEW_RADIUS) {
                break;
            }
            i++;
        }
        if (find_edge == 1) {
            break;
        }
        user_center.y = user_center.y + VIEW_RADIUS;

        // to avoid infinite loop
        if (user_center.x > 1000) {
            user_center.x = VIEW_RADIUS;
            user_center.y = VIEW_RADIUS;
            // printf("fail to find an edge\n");
            return user_center;  
        }
    }

    user_center.x = VIEW_RADIUS;
    user_center.y = VIEW_RADIUS;
    for (i = VIEW_RADIUS; i < edge_x + VIEW_RADIUS; i = i + VIEW_SIZE) {
        //printf("i: %d\n", i);
        //printf("user_center.x: %d\n", user_center.x);
        for (j = VIEW_RADIUS; j < edge_y + VIEW_RADIUS; j = j + VIEW_SIZE) {
            //printf("j: %d\n", j);
            //printf("user_center.y: %d\n", user_center.y);
            generate_view(user_view, user_center.y, user_center.x);
            startview_x = user_center.x - VIEW_RADIUS;
            startview_y = user_center.y - VIEW_RADIUS;
            check_peak = 0;
        
            // Check the peak point in the view
            for (view_row = 0; view_row < VIEW_SIZE; view_row++) {
                for (view_column = 0; view_column < VIEW_SIZE; view_column++) {
                    if (check_peak < user_view[view_row][view_column]) {
                        check_peak = user_view[view_row][view_column];
                        peak_x = startview_x + view_column;
                        peak_y = startview_y + view_row;
                    }
                }
            }
            
            // Check whether it is a peak of the map
            if (declare_peak(peak_x, peak_y) == 1) {
                user_center.x = peak_x;
                user_center.y = peak_y;
                // printf("peak_x: %d\n", peak_x);
                // printf("peak_y: %d\n", peak_y);
                // printf("found a peak!\n");
                return user_center;
            }
            
            user_center.y = user_center.y + VIEW_SIZE;
            
        }
        user_center.y = VIEW_RADIUS;
        user_center.x = user_center.x + VIEW_SIZE;
    }
    
    // to avoid infinite loop
    // printf("fail to find an edge\n");
    user_center.x = VIEW_RADIUS;
    user_center.y = VIEW_RADIUS;
    return user_center;
}