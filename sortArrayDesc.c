#include <stdio.h>
#include <conio.h>

void main()
{
  int arr[]={7,8,5,6,1,4,9,2,10,3};
  int i,j,index;
  int arrlen=sizeof(arr)/4;
  for(i=0;i<arrlen-1;i++){
    int checknum=arr[i];
    for(j=i+1;j<arrlen;j++){
        if(checknum<arr[j]){
            checknum=arr[j];
            index=j;
        }
    }
    while(index>i){
        arr[index]=arr[index-1];
        index--;
    }
    arr[i]=checknum;
  }
  for(int a=0;a<arrlen;a++){
        printf("%d ",arr[a]);
    }
    printf("\n");
}
