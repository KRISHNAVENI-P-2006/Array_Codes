#include<stdio.h>
void main(){
    int n,i,j,temp;
    printf("Enter the order: ");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++){
     printf("Enter elements of %d column: ",i+1);
     for(j=0;j<n;j++)
     scanf("%d",&a[j][i]);
    }
    printf("\n The matrix is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<(n);j++)
        printf("%d ",a[i][j]);
    printf("\n");
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;

            
        }
    }
    printf("\nThe modified version is: \n");
     for(i=0;i<n;i++){
        for(j=0;j<(n);j++)
        printf("%d ",a[i][j]);
    printf("\n");
    }
}