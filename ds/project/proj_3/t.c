#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 40000

int **adj_matrix;
int *memory_size;
int **search;
int **requests;
int **path;
int *visited;
int number = 0;
int **trough;
int **tree;
int *output;

struct node{
    int id;
    struct node *next;
};

struct Queue {
    struct node *front;
    struct node *rear;
};

struct Queue *queue;

// Create queue
struct Queue *createqueue(){
    struct Queue *newqueue = malloc(sizeof(struct Queue));
    newqueue -> front = NULL;
    newqueue -> rear = NULL;

    return newqueue;
}

int isempty(struct Queue *queue){
    // Return 1 if the queue is empty
    return (queue -> front == NULL); 
}

void enqueue(struct Queue *queue, int id) {
    // Create new node
    struct node *newnode = malloc(sizeof(struct node));
    newnode -> id = id;
    newnode -> next = NULL;

    // If queue is empty, newnode will be front and rear
    if(isempty(queue)){
        queue -> front = newnode;
        queue -> rear = newnode;
    }
    // Add newnode to the rear, and update the rear pointer
    else{
        queue -> rear -> next = newnode;
        queue -> rear = newnode;
    }   
}

int dequeue(struct Queue *queue) {
    int id;
    // If queue is empty
    if(isempty(queue)){
        printf("Error: Queue is empty!\n");
    }

    // Store the front node
    struct node *frontnode = queue -> front;

    // Move the front pointer to next node
    queue -> front = frontnode -> next;

    // If the front pointer is NULL, refresh the rear pointer
    if(queue -> front == NULL)
        queue -> rear = NULL;
    
    // Get information
    id = frontnode -> id;
    free(frontnode);

    return id;
}

void clearqueue(struct Queue *queue){
    while (queue->front != NULL) {
        // Store the front node
        struct node *frontnode = queue->front;

        // Move the front pointer to next node
        queue->front = frontnode->next;

        // If the front pointer is NULL, refresh the rear pointer
        if (queue->front == NULL)
            queue->rear = NULL;

        // Free the memory
        free(frontnode);
    }
}

/*
void clearqueue(struct Queue *queue){
    // Store the front node
    struct node *frontnode = queue -> front;

    // Move the front pointer to next node
    queue -> front = frontnode -> next;

    // If the front pointer is NULL, refresh the rear pointer
    if(queue -> front == NULL)
        queue -> rear = NULL;

    // Free the memory
    free(frontnode);
}
*/
void initVisited(int num_nodes) {
    visited = malloc(num_nodes * sizeof(int));
    for(int i = 0; i < num_nodes; i++){
        visited[i] = 0;
    }
}

int bfs(int start, int end, int num_nodes){
    int steps, amount, num;

    search = malloc(num_nodes * sizeof(int *));
    for(int i = 0; i < num_nodes; i++){
        search[i] = malloc(2 * sizeof(int));
    }
    for(int i = 0; i < num_nodes; i++){
        search[i][0] = 0;
        search[i][1] = 0;
    }

    queue = createqueue();

    initVisited(num_nodes);

    enqueue(queue ,start);
    visited[start] = 1;
    search[0][0] = start; // id
    search[0][1] = -1;   // position
    amount = -1;
    num = 1;

    while (!isempty(queue)) {
        int current = dequeue(queue);
        amount++;

        if (current == end) {
            //printf("Path found from %d to %d: ", start, end);

            // Print the path
            int temp = end;
            int pos = amount;
            steps = 1;
            while (temp != start) {
                //printf("%d ", temp);
                path[number][steps - 1] = temp;
                pos = search[pos][1];   // get position
                temp = search[pos][0]; // get id
                steps++;
            }
            //printf("%d\n", start);
            path[number][steps - 1] = start;
            for(int i = 0; i < num_nodes; i++){
                free(search[i]);
            }
            free(search);
            free(visited);
            // Free the queue
            while (!isempty(queue)) {
                clearqueue(queue);
            }
            free(queue);

            return steps;
        }
        else{
            for(int i = 0; i < num_nodes; i++){
                if(adj_matrix[current][i] == 1 && visited[i] == 0){
                    enqueue(queue, i);
                    visited[i] = 1;
                    search[num][0] = i;
                    search[num][1] = amount;
                    num++;
                }
            }
        }
        
    }

    //printf("Path not found from %d to %d\n", start, end);
    for(int i = 0; i < num_nodes; i++){
        free(search[i]);
    }
    free(search);
    free(visited);
    // Free the queue
    while (!isempty(queue)) {
        clearqueue(queue);
    }
    free(queue);
    return -1;
}

void initTree(int T, int node){     // row is T, column is node
    for(int i = 0; i < T; i++){
        for(int j = 0; j < node; j++)
            tree[i][j] = 0;
    }
}

int checktrough(int T, int num_nodes){
    int temp;
    for(int i = 0; i < T; i++){
        for(int j = 0; j < num_nodes; j++){
            temp = tree[i][j] + trough[i][j];

            if(temp > memory_size[j]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int num_nodes, num_links, timeslots, num_requests;
    int id, memory, link_1, link_2;
    int min, temp;

    scanf(" %d %d %d %d", &num_nodes, &num_links, &timeslots, &num_requests);

    /* Allocate memory */
    memory_size = malloc(num_nodes * sizeof(int));
    adj_matrix = malloc(num_nodes * sizeof(int *));
    for(int n = 0; n < num_nodes; n++){
        adj_matrix[n] = malloc(num_nodes * sizeof(int));
    }

    path = malloc(num_requests * sizeof(int *));
    for(int i = 0; i < num_requests; i++){
        path[i] = malloc(MAX_SIZE * sizeof(int));
    }

    requests = malloc(num_requests * sizeof(int *));
    for(int i = 0; i < num_requests; i++){
        requests[i] = malloc(4 * sizeof(int));
    }

    for(int i = 0; i < num_requests; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            path[i][j] = 0;
        }
    }

    /* Create nodes */
    for(int i = 0; i < num_nodes; i++){
        scanf(" %d %d", &id, &memory);
        memory_size[id] = memory;
    }

    /* Create edges */
    for(int i = 0; i < num_links; i++){
        scanf(" %d %d %d", &id, &link_1, &link_2);

        adj_matrix[link_1][link_2] = 1;
        adj_matrix[link_2][link_1] = 1;
    }

    /* Get requests */
    for(int i = 0; i < num_requests; i++){
        scanf(" %d %d %d", &id, &link_1, &link_2);

        requests[i][0] = id;
        requests[i][1] = link_1;
        requests[i][2] = link_2;

        requests[i][3] = bfs(link_2, link_1, num_nodes);
        number++;
    }
/*
    // Check
    for(int i = 0; i < number; i++){
        printf("Request %d, steps %d: ", requests[i][0], requests[i][3]);
        for(int j = 0; j < requests[i][3]; j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
*/
    /* Sorting */
    for(int i = 0; i < num_requests - 1; i++){
        min = i;
        for(int j = i + 1; j < num_requests; j++){
            if(requests[j][3] < requests[min][3])
                min = j;
        }

        for(int k = 0; k < requests[i][3]; k++){
            temp = path[i][k];
            path[i][k] = path[min][k];
            path[min][k] = temp;
        }

        for(int k = 0; k < 4; k++){
            temp = requests[i][k];
            requests[i][k] = requests[min][k];
            requests[min][k] = temp;
        }
    }
/*
    // Check
    for(int i = 0; i < number; i++){
        printf("Request %d, steps %d: ", requests[i][0], requests[i][3]);
        for(int j = 0; j < requests[i][3]; j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
*/
    int amount = 0;
    tree = malloc(timeslots * sizeof(int *));
    for(int i = 0; i < timeslots; i++){
        tree[i] = malloc(num_nodes * sizeof(int));
    }

    trough = malloc(timeslots * sizeof(int *));
    for(int t = 0; t < timeslots; t++){
        trough[t] = malloc(num_nodes * sizeof(int));
    }

    for(int i = 0; i < timeslots; i++){
        for(int j = 0; j < num_nodes; j++){
            trough[i][j] = 0;
        }
    }

    output = malloc(num_requests * sizeof(int));

    /* Create tree */
    for(int i = 0; i < num_requests; i++){
        // Pass greater request
        if(requests[i][3] > timeslots){
            break;
        }

        initTree(timeslots, num_nodes);

        if(requests[i][3] == 2){
            tree[0][path[i][0]] = 1;
            tree[0][path[i][1]] = 1;
            tree[1][path[i][0]] = 1;
            tree[1][path[i][1]] = 1;
        }
        else{
            for(int j = 0; j < requests[i][3]; j++){
                tree[j][path[i][0]] = 1;

                if((j < requests[i][3] - 2) || j == 0){
                    tree[j][path[i][j + 1]] = 2;
                    tree[j][path[i][j + 2]] = 1;
                    tree[j + 1][path[i][j + 1]] = 2;
                }
                else{
                    tree[j][path[i][requests[i][3] - 1]] = 1; 
                }
            }
        }
/*
        // Check
        printf("Tree %d:\n", requests[i][0]);
        for(int j = 0; j < timeslots; j++){
            for(int k = 0; k < num_nodes; k++){
                printf("%d", tree[j][k]);
            }
            printf("\n");
        }
*/
        int check;

        /* Add to trough */
        check = checktrough(timeslots, num_nodes);

        if(check == true){
            /*
            // Check
            printf("Tree %d:\n", requests[i][0]);
            for(int j = 0; j < timeslots; j++){
                for(int k = 0; k < num_nodes; k++){
                    printf("%d", tree[j][k]);
                }
                printf("\n");
            }
            */
            for(int  j= 0; j < timeslots; j++){
                for(int k = 0; k < num_nodes; k++){
                    trough[j][k] = tree[j][k] + trough[j][k];
                }
            }

            // Check
            printf("Trough:\n");
            for(int j = 0; j < timeslots; j++){
                for(int k = 0; k < num_nodes; k++){
                    printf("%d", trough[j][k]);
                }
                printf("\n");
            }

            output[amount] = i; // Get position
            amount++;
        }
/*
        // Check
        printf("Trough:\n");
        for(int j = 0; j < timeslots; j++){
            for(int k = 0; k < num_nodes; k++){
                printf("%d ", trough[j][k]);
            }
            printf("\n");
        }
*/
    }

    /* Output */
    int place, start;

    printf("%d\n", amount);

    for(int i = 0; i < amount; i++){
        place = output[i];

        //printf("place: %d\n", place);
        printf("#%d ", requests[place][0]);
        for(int j = 0; j < requests[place][3]; j++){
            printf("%d ", path[place][j]);
        }
        printf("\n");
        start = path[place][0];

        if(requests[place][3] == 2){
            printf("%d %d %d\n", start, path[place][1], 2);
        }
        else{
            for(int column = 0; column < requests[place][3]; column++){
                if(column == 0 || column == 1){
                    printf("%d %d %d\n", path[place][column], path[place][column + 1], 2);
                }
                else if(column == requests[place][3] - 1){
                    printf("%d %d %d %d %d %d %d\n", start, path[place][column], start, path[place][column - 1], path[place][column - 1], path[place][column], column + 1);
                }
                else{
                    printf("%d %d %d %d %d %d %d\n", start, path[place][column], start, path[place][column - 1], path[place][column - 1], path[place][column], column + 1);
                    printf("%d %d %d\n", path[place][column], path[place][column + 1], column + 1);
                }
            }
        }
    }

    //printf("Break point_1\n");

    /* Free Memory */
    for(int n = 0; n < num_nodes; n++){
        free(adj_matrix[n]);
    }
    free(adj_matrix);

    for(int i = 0; i < num_requests; i++){
        free(path[i]);
    }
    free(path);

    for(int i = 0; i < num_requests; i++){
        free(requests[i]);
    }
    free(requests);

    for(int t = 0; t < timeslots; t++){
        free(tree[t]);
    }
    free(tree);

    for(int t = 0; t < timeslots; t++){
        free(trough[t]);
    }
    free(trough);

    free(memory_size);

    free(output);

    //printf("Break point_2\n");
/*
    // Free the queue
    if (queue != NULL) {
        if(!isempty(queue)){
            clearqueue(queue);
        }
        free(queue);
        printf("Free queue\n");
    }
*/
    //printf("Break point_3\n");

    return 0;
}