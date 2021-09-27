//
//  main.c
//  linux
//
//  Created by lincoln.zhu on 2021/9/19.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "leetcode/square.h"

#define len(INT) sizeOf(INT)/sizeOf(0)


int testRead(void)
{
    // insert code here...
    printf("Hello, World!\n");
    FILE *read_fp;
    char buffer[BUFSIZ];
    int chars_read;
    memset(buffer, '\0', sizeof(buffer));
    read_fp=popen("uname -a", "r");
    if (read_fp!=NULL) {
        chars_read=fread(buffer,sizeof(char), BUFSIZ, read_fp);
        if (chars_read>0) {
            printf("Output was:-\n%s\n",buffer);
        
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
    
}

int testWrite(void) {
    
    FILE *fd;
    char buffer[BUFSIZ+1];
    
    sprintf(buffer, "hei hei hei\n");
    fd=popen("od -c", "w");
    fwrite(buffer, sizeof(char), strlen(buffer), fd);
    pclose(fd);
    exit(EXIT_SUCCESS);

}

int testPipe(void) {
    int file_pipes[2];
    pipe(file_pipes);
    printf("%d\n",file_pipes[0]);
    printf("%d\n",file_pipes[1]);
    
    pipe(file_pipes);
    printf("%d\n",file_pipes[0]);
    printf("%d\n",file_pipes[1]);
    
   

    return 0;
}

extern int* sortedSquares(int* nums, int numsSize, int* returnSize);
extern void rotate(int* nums, int numsSize, int k);
extern void print_array(int* nums,int size);

int main(int argc, const char * argv[]) {
    //testPipe();
    //平方
    int nums[] = {-4,-1,0,3,10};
    int returnSize;
    int* result=sortedSquares(nums,sizeof(nums)/sizeof(0),&returnSize);
    printf("returnSize:%d\n",returnSize);
    for(int i=0;i<returnSize;i++){
        printf("%d\n",result[i]);
    }
    
    //旋转
//    int nums[] = {1,2,3,4,5,6,7};
//    int k = 3;
//    int len=sizeof(nums)/sizeof(int);
//    rotate(nums,len,k);
//    print_array(nums,len);
    
}

