#include<stdio.h>
void main(){
    printf("This code displays the lower triangle in a matrix\n");
    int i,j,n,sum=0;
    printf("Enter the order: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);}
    printf("The matrix is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("%d ",a[i][j]);}
        printf("\n");
    }
    printf("The lower triangle is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
       if(i<j)
       a[i][j]=0;}}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("%d ",a[i][j]);}
        printf("\n");}
      for(i=0;i<n;i++){
        for(j=0;j<n;j++)
       sum=sum+a[i][j];}
    printf("The sum of lower triangle is %d",sum);
      
}