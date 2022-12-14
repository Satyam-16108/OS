/*
	1. Write a program to report Linux kernel including kernel version, CPU type and model,memory info.

*/

#include<stdlib.h>
#include<stdio.h>

int main(){
    printf("Kernel Version: \n");
    system("cat /proc/sys/kernel/osrelease");

    printf("CPU : \n");
    system("cat /proc/cpuinfo | grep 'model name' | uniq");

    printf("No. of Processors: \n");
    system("cat /proc/cpuinfo | grep processor | wc -l");

    printf("CPU space: \n");
    system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'\n");
    
    printf("\nUpTime: \n");
    system("cat /proc/uptime \n");

    printf("\nConfigured memory :\n");
    system("cat /proc/meminfo | awk 'NR == 1{print $2}'\n");

    printf("Amount of free memory :\n");
    system("cat /proc/meminfo | awk 'NR == 2{print $2}'\n");
    
    printf("Amount of used memory is :\n");
    system("cat /proc/meminfo | awk '{if (NR==1) a=$2; if(NR==2) b=$2 }END {print a-b}' \n");
    return 0;

}
