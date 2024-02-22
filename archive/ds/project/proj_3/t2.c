#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tree_node{
    int left_point;
    int right_point;
    struct tree_node *left_link; 
    struct tree_node *right_link; 
};

struct queue_node{
    struct queue_node *next;
    int value;
    int count;
};

struct graph_node{
    int point;
    struct graph_node *next;
};

struct queue_node *front=NULL;
struct queue_node *last=NULL;
//struct tree_node *root=NULL;
struct graph_node* list[5000];

int queue_pop_arr[2];//0: value, 1: count
int req_route[5000];

void add_graph_link(int node1,int node2){
    if(list[node1]==NULL){
        struct graph_node *temp=(struct graph_node*)malloc(sizeof(struct graph_node));
        temp->point=node2;
        temp->next=NULL;
        list[node1]=temp;
    }else{
        struct graph_node *temp=list[node1];
        while(1){
            if(temp->next==NULL){
                break;
            }
            temp=temp->next;
        }
        struct graph_node *new_node=(struct graph_node*)malloc(sizeof(struct graph_node));
        new_node->point=node2;
        new_node->next=NULL;
        temp->next=new_node;
    }
    if(list[node2]==NULL){
        struct graph_node *temp=(struct graph_node*)malloc(sizeof(struct graph_node));
        temp->point=node1;
        temp->next=NULL;
        list[node2]=temp;
    }else{
        struct graph_node *temp=list[node2];
        while(1){
            if(temp->next==NULL){
                break;
            }
            temp=temp->next;
        }
        struct graph_node *new_node=(struct graph_node*)malloc(sizeof(struct graph_node));
        new_node->point=node1;
        new_node->next=NULL;
        temp->next=new_node;
    }
    return;
}

void queue_init(){
    while(1){
        struct queue_node *temp=front;
        if(temp==NULL){
            break;
        }
        front=front->next;
        free(temp);
    }
    last=NULL;
    return;
}

void queue_push(int value,int count){
    struct queue_node *temp=(struct queue_node*)malloc(sizeof(struct queue_node));
    temp->value=value;
    temp->count=count;
    temp->next=NULL;
    if(front==NULL){//no data in queue
        front=temp;
        last=temp;
    }else{
        last->next=temp;
        last=temp;
    }
    return;
}

int queue_pop(){
    if(front==NULL){//no data in queue
        return -1;
    }else if(front==last){//only one data in queue
        struct queue_node *temp=front;
        queue_pop_arr[0]=front->value;
        queue_pop_arr[1]=front->count;
        front=NULL;
        last=NULL;
        free(temp);
        return 1;
    }else{
        struct queue_node *temp=front;
        queue_pop_arr[0]=front->value;
        queue_pop_arr[1]=front->count;
        front=front->next;
        free(temp);
        return 1;
    }
}

int BFS(int start,int end,int num){
    int count=0;//steps from start to end
    queue_init();
    int visit[num+5];
    int parent[num+5];
    for(int i=0;i<num;++i){//visit array initalize
        visit[i]=0;
    }
    for(int i=0;i<num;++i){//parent array initalize
        parent[i]=-1;
    }
    int x=start;
    visit[x]=1;
    while(1){
        if(x==end){
            visit[x]=1;
            break;
        }
        struct graph_node *temp=list[x];
        //printf("%d\n",temp->point);
        while(1){
            if(temp==NULL){
                break;
            }
            if(visit[temp->point]!=1){
                queue_push(temp->point,count+1);
                parent[temp->point]=x;
                visit[temp->point]=1;
                //printf("%d %d\n",temp->point,count+1);
            }
            temp=temp->next;
        }
        if(queue_pop()==1){
            count=queue_pop_arr[1];
            x=queue_pop_arr[0];
        }else{
            break;
        }
        //printf("%d %d %d\n",count,x,start);
        
    }

    // find the route
    x=end;
    //printf("%d ",count);
    /*for(int i=0;i<num;++i){//test visit
        printf("%d ",parent[i]);
    }
    printf("\n");*/
    if(count==0){
        return 0;
    }
    for(int i=0;i<=count;++i){//route initialize
        req_route[i]=-1;
    }
    for(int i=count;i>=0;--i){
        if(x==start){
            break;
        }
        req_route[i]=x;
        x=parent[x];
    }
    req_route[0]=start;
    if(req_route[1]==-1){
        for(int i=1;i<count;++i){
            req_route[i]=req_route[i+1];
        }
        count-=1;
    }
    //printf("%d ",count);
    return count;
}

/*
struct tree_node* create_tree_node(int left,int right){
    struct tree_node *temp=(struct tree_node*)malloc(sizeof(struct tree_node));
    temp->left_point=left;
    temp->right_point=right;
    temp->left_link=NULL;
    temp->right_link=NULL;
    return temp;
}

struct tree_node* tree_move_left(struct tree_node* node){
    node=node->left_link;
    return node;
}

struct tree_node* tree_move_right(struct tree_node* node){
    node=node->right_link;
    return node;
}

struct tree_node* add_left(struct tree_node* node,int left,int right){
    node->left_link=create_tree_node(left,right);
    return node->left_link;
}

struct tree_node* add_right(struct tree_node* node,int left,int right){
    node->right_link=create_tree_node(left,right);
    return node->right_link;
}
*/

int main(){
    int node_num,link_num,time_slot,req_num;
    scanf("%d %d %d %d",&node_num,&link_num,&time_slot,&req_num);
    int node_id, quantum_memories;
    int node_memory[node_num+5];
    int node_time_memory[time_slot+1][node_num];
    for(int i=0;i<node_num;++i){// node input
        scanf("%d %d",&node_id,&quantum_memories);
        node_memory[node_id]=quantum_memories;
    }
    //int link[link_num+5][2];
    int link_id,link_end1,link_end2;
    for(int i=0;i<link_num;++i){// link input
        scanf("%d %d %d",&link_id,&link_end1,&link_end2);
        //link[link_id][0]=link_end1;
        //link[link_id][1]=link_end2;
        add_graph_link(link_end1,link_end2);
    }
    int req[req_num+5][2];
    int req_id,req_src,req_dst;
    for(int i=0;i<req_num;++i){// request input
        scanf("%d %d %d",&req_id,&req_src,&req_dst);
        req[req_id][0]=req_src;
        req[req_id][1]=req_dst;
    }
    int req_tie[req_num+5];
    for(int i=0;i<req_num;++i){//find shortest path
        req_tie[i]=BFS(req[i][0],req[i][1],node_num);
        /*printf("%d ",req_tie[i]);//route test
        for(int j=0;j<=req_tie[i];++j){
            printf("%d ",req_route[j]);
        }
        printf("\n");*/
    }
    //output
    int accept_count=0;
    char accept_content[4000][400];//record output
    for(int i=0;i<time_slot;++i){//initialize time memory array
        for(int j=0;j<node_num;++j){
            node_time_memory[i][j]=0;
        }
    }
    for(int i=0;i<2000;++i){//initialize output array
        strcpy(accept_content[i],"\0");
    }
    int time=2;
    while(1){
        if(time>time_slot){
            break;
        }
        for(int i=0;i<req_num;++i){
            //printf("%d ",req_tie[i]);
            if(req_tie[i]==1){//find smallest request: 1 steps
                int flag=0;
                BFS(req[i][0],req[i][1],node_num);
                for(int j=0;j<=req_tie[i]+1;++j){//check memory size
                    //printf("%d ",req_route[j]);
                    if(node_time_memory[time][req_route[j]]+1>node_memory[req_route[j]]){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    continue;
                }
                for(int j=0;j<=req_tie[i];++j){
                    node_time_memory[time][req_route[j]]+=1;
                }
                char str[100];
                sprintf(str,"%d %d %d\n",i,req[i][0],req[i][1]);
                strcat(accept_content[accept_count],str);
                sprintf(str,"%d %d %d\n",req[i][0],req[i][1],time);
                strcat(accept_content[accept_count],str);
                accept_count++;
                req_tie[i]=-1;//-1 mean finish
                continue;
            }
            if(req_tie[i]!=-1){//find other requests
                int flag=0;
                BFS(req[i][0],req[i][1],node_num);
                if(time+req_tie[i]+1>time_slot){//can not finish at time slot
                    req_tie[i]=-1;
                    continue;
                }
                for(int j=0;j<=req_tie[i];++j){//check memory size
                    if(node_time_memory[time+j][req[i][0]]+1>node_memory[req[i][0]]){//start point
                        flag=1;
                        break;
                    }
                    if(node_time_memory[time+j][req_route[1+j]]+2>node_memory[req_route[1+j]]&&j<req_tie[i]-1){
                        flag=1;
                        break;
                    }
                    if(node_time_memory[time+j][req_route[2+j]]+1>node_memory[req_route[2+j]]&&j<req_tie[i]-1){
                        flag=1;
                        break;
                    }
                    if(j>=req_tie[i]-1&&node_time_memory[time+j][req[i][1]]+1>node_memory[req[i][1]]){//last point
                        flag=1;
                        break;
                    }
                    if(node_time_memory[time+j][req_route[j]]+2>node_memory[req_route[j]]&&j>0&&j!=req_tie[i]){
                        flag=1;
                        break;
                    }
                }
                //printf("%d",flag);
                if(flag==1){
                    continue;
                }
                char str[100];
                sprintf(str,"%d ",i);
                strcat(accept_content[accept_count],str);
                for(int j=0;j<=req_tie[i];++j){//print first line
                    sprintf(str,"%d ",req_route[j]);
                    strcat(accept_content[accept_count],str);
                }
                strcat(accept_content[accept_count],"\n");
                for(int j=0;j<req_tie[i];++j){
                    node_time_memory[time+j][req[i][0]]++;//start point
                    if(j<req_tie[i]-1){
                        node_time_memory[time+j][req_route[1+j]]+=2;
                    }
                    if(j<req_tie[i]-1){
                        node_time_memory[time+j][req_route[2+j]]+=1;
                    }
                    if(j>=req_tie[i]-1){//last point
                        node_time_memory[time+j][req[i][1]]++;
                    }
                    if(j>0&&j<req_tie[i]){
                        node_time_memory[time+j][req_route[j]]+=2;
                    }
                    //print to string
                    if(j==0){
                        sprintf(str,"%d %d %d\n",req[i][0],req_route[1],time);
                        strcat(accept_content[accept_count],str);
                    }
                    if(j!=req_tie[i]-1){
                        sprintf(str,"%d %d %d\n",req_route[1+j],req_route[2+j],time+j);
                        strcat(accept_content[accept_count],str);
                        sprintf(str,"%d %d %d %d %d %d %d\n",req[i][0],req_route[2+j],req[i][0],req_route[1+j],req_route[1+j],req_route[2+j],time+1+j);
                        strcat(accept_content[accept_count],str);
                    }
                    
                }
                printf("hi\n");
                for(int k=0;k<node_num;k++){
                    printf("%d",node_memory[k]);
                }       
                printf("\n");
                for(int j=0;j<time_slot;j++){
                    for(int k=0;k<node_num;k++){
                        printf("%d",node_time_memory[j][k]);
                    }
                    printf("\n");
                }
                printf("\n");                
                accept_count++;
                req_tie[i]=-1;
                continue;
            }
        }
        time++;
    }

    //output
    printf("%d\n",accept_count);
    for(int i=0;i<accept_count;++i){
        printf("%s",accept_content[i]);
    }
    
    return 0;
}