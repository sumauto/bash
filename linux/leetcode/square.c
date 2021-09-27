//
//  square.c
//  linux
//
//  Created by lincoln.zhu on 2021/9/27.
//

#include "square.h"
#include <stdlib.h>

void print_array(int* nums,int size){
    for(int i=0;i<size;i++){
        printf("%d\n",nums[i]);
    }
}

void swap(int *a,int i, int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void quickSort(int *a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];
     
    while(i < j)
    {
        while(i < j && key <= a[j]){
            j--;
        }
         
        swap(a,i,j);
        while(i < j && key >= a[i]){
            i++;
        }
         
        swap(a,i,j);
    }
     
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int* result=malloc(sizeof(int) * numsSize);
    int neg_find_index=-1;
    for(int i=numsSize-1;i>=0;i--){
        if (neg_find_index==-1&&nums[i]<0) {
            neg_find_index=0;
        }
        if (neg_find_index!=-1) {
            result[neg_find_index]=nums[i]*nums[i];
            neg_find_index++;
        }else{
            result[i]=nums[i]*nums[i];
        }
        
    }
  
    quickSort(result,  0, numsSize-1);
  

    return result;
}

void reverse(int* nums, int start, int end){
    for (; start<end; start++,end--) {
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
}
}

void rotate(int* nums, int numsSize, int k){
    int move=k%numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums, 0, move-1);
    reverse(nums, move, numsSize-1);
}

