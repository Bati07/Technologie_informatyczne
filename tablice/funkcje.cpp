//
// Created by bati2 on 15.04.2026.
//
#include <iostream>
#include "funkcje.h"
float averageValue(int tab[],int size){
    int sum =0;
    float average=0;
    for(int i=0;i<size;i++){
        sum += tab[i];
    }
    average=(float)sum/size;
    //printf("average value: %.2f\n",average);
    return average;


}
int maxValue(int tab[],int size){
    int value=tab[0];
    for(int i=1;i<size;i++){
        if (tab[i]>value){
            value=tab[i];
        }
    }
    return value;


}


int minValue(int tab[],int size){
    int value=tab[0];
    for(int i=1;i<size;i++){
        if (tab[i]<value){
            value=tab[i];
        }
    }
    return value;
    //    printf("min value: %d\n",value);


}

int minValueLocator(int tab[],int size){
    int value=tab[0];
    int max=0;
    for(int i=1;i<size;i++){
        if (tab[i]<value){
            value=tab[i];
            max=i;
        }
    }
    return max;
    //    printf("min value in: tab[%d]\n",max);
}

int maxValueLocator(int tab[],int size){
    int value=tab[0];
    int max=0;
    for(int i=1;i<size;i++){
        if (tab[i]>value){
            value=tab[i];
            max=i;
        }
    }
    return max;
}



void medianValue(int tab[],int size){
    int temp;
    int mid=size/2;
    float median=0;
    for(int i = 0;i < size; i++) {
        for(int j = 0;j < size-1; j++)
        {
            if (*(tab + j)>*(tab + j+1)) {
                temp=*(tab + j+1);
                *(tab + j+1) =*(tab + j);
                *(tab + j)=temp;
            }}}
    if (2*mid==size) {
        median= (float) (*(tab + mid-1)+*(tab + mid))/2;
    }
    else {
        median= (float) *(tab + mid);
    }
    printf("median: %.2f\n",median);
}