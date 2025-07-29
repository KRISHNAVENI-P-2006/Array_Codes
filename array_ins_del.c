#include<stdio.h>
void main(){
    int n,i,val,ar[20],ch,ind,temp,op;
    printf("Enter no: of elements in the array:\n");
    scanf("%d",&n);
    printf("Enter elements into the array:");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("Array: ");
    for(i=0;i<n;i++){
        printf("%d  ",ar[i]);
    }
    do{
        printf("\nFor insertion, choose 1, for deletion, choose 2");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter index(0 based): ");
            scanf("%d",&ind);
            if(ind<0 ||ind>n){printf("Invalid index !!");}
            else{
            printf("Enter value: ");
            scanf("%d",&val);
        for(i=n;i>ind;i--){
            ar[i]=ar[i-1];
        }
        ar[ind]=val;
        n++;
        printf("Updated Array:\n");
        for(i=0;i<n;i++){
        printf("%d  ",ar[i]);
        }}
    }else if (ch==2){
        printf("Array: ");
    for(i=0;i<n;i++){
        printf("%d  ",ar[i]);
    }
        printf("Enter the position(0 based): ");
        scanf("%d",&ind);
        if(ind<0 ||ind>=n){printf("Invalid index !!");}
        else{
        for(i=ind;i<n-1;i++){
            ar[i]=ar[i+1];
        }
        n--;
        printf("Updated Array:\n");
        for(i=0;i<n;i++){
        printf("%d  ",ar[i]);
        }
    }}
    else{printf("Choose something valid !!");}
        printf("Press 1 to continue...");
        scanf("%d",&op);
    }while(op==1);

}