    if(bfsResult[index][1]>T){
        return 0;  // Numerology is longer than timeSlot
    }
    else{
        int arr[nodes], i=0, tempCapacity[nodes][T], time=T-1;
        link* ptr=bfsPath[bfsResult[index][0]];

        // Copy the capacity array to a temporary array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<T;j++){
                tempCapacity[i][j]=capacity[i][j];
            }
        }

        // Extract the nodes from the BFS path
        while(ptr!=NULL){
            arr[i]=ptr->val;
            i++;
            ptr=ptr->prev;
        }

        // Check numerology constraint for each time step
        for(int i=bfsResult[index][1]-1;i>0;i--){
            if(i!=1){
                if(check(arr[i],tempCapacity, time)&&check(arr[0],tempCapacity, time)){
                    tempCapacity[arr[i]][time]++;
                    tempCapacity[arr[0]][time]++;
                }
                else{
                    return 0;
                }
                if(check(arr[i],tempCapacity, time-1)&&check(arr[i-1],tempCapacity, time-1)){
                    tempCapacity[arr[i]][time-1]++;
                    tempCapacity[arr[i-1]][time-1]++;
                }
                else{
                    return 0;
                }
                if(check(arr[i],tempCapacity, time-2)&&check(arr[i-1],tempCapacity, time-2)){
                    tempCapacity[arr[i]][time-2]++;
                    tempCapacity[arr[i-1]][time-2]++;
                } 
                else{
                    return 0;
                }   
            }
            else{
                if(check(arr[1],tempCapacity, time)&&check(arr[0],tempCapacity, time)){
                    tempCapacity[arr[1]][time]++;
                    tempCapacity[arr[0]][time]++;
                } 
                else{
                    return 0;
                }
                if(check(arr[1],tempCapacity, time-1)&&check(arr[0],tempCapacity, time-1)){
                    tempCapacity[arr[1]][time-1]++;
                    tempCapacity[arr[0]][time-1]++;
                } 
                else{
                    return 0;
                } 
            }
                    
            time--;
        }
       
        // for(int j=T-1;j>=0;j--){
        //     for(int i=0;i<nodes;i++){
        //         printf("%d",tempCapacity[i][j]);
        //     }
        //     printf("\n");
        // }   
        // printf("\n");

        // Copy the updated temporary capacity array back to the main capacity array
        for(int i=0;i<nodes;i++){
            for(int j=0;j<T;j++){
                capacity[i][j]=tempCapacity[i][j];
            }
        }       
        return 1;
    }