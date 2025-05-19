#include<stdio.h>
#define MAX 10000
int parent[MAX];
int rank[MAX];

//logic for initialization 
void init(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}


//logic for finding parent
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }

    return parent[x];
}


//logic for union two set
void union_set(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);

    if(parent_x!=parent_y){

        if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }else if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }else{
            parent[parent_y]=parent_x;
            rank[parent_x]++;
        }
    }
}


//logic for same set
void is_sameset(int x,int y){
        if(find(x)==find(y)){
            printf("yes\n");
        }else{
            printf("no\n");
    }
}

int main(){

    int n;
    scanf("%d",&n);
    //logic for special case
    if(n<1){
        printf("Invalid input\n");
        return -1;
    }


    init(n);


    int x,y;
    scanf("%d %d",&x,&y);

    //logic for special case
    if((x<0 || x>=n) || (y<0 || y>=n)){
        printf("Invalid input\n");
        return -1;
    }

    union_set(x,y);
    is_sameset(x,y);

    return 0;
}