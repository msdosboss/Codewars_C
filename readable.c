#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *formatDuration (int n) {
    int yearCount = 0;
    int dayCount = 0;
    int hourCount = 0;
    int minuteCount = 0;
    int wordCount = 1;
    if(n == 0){
        char *nowStr;
        nowStr = malloc(sizeof(char) * 4);
        strcpy(nowStr, "now");
        return nowStr;
    }
    if(n >= 31540000)
        wordCount++;
    while(n >= 31540000){
        yearCount++;
        n = n - 31540000;
    }
    if(n >= 86400)
        wordCount++;
    while(n >= 86400){
        dayCount++;
        n = n - 86400;
    }
    if(n >= 3600)
        wordCount++;
    while(n >= 3600){
        hourCount++;
        n = n - 3600;
    }
    if(n >= 60)
        wordCount++;
    while(n >= 60){
        minuteCount++;
        n = n - 60;
    }
    if(n == 0)
        wordCount--;
    char *str;
    str = malloc(sizeof(char) * wordCount * 20);
    if(str == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int flag = 0;
    if(yearCount != 0){      
        if(yearCount == 1)
            sprintf(str, "%d year", yearCount);
        else
            sprintf(str, "%d years", yearCount);
        flag++;
        if(wordCount == 2)
            strcat(str, " and ");
        else if(wordCount > 2)
            strcat(str, ", ");
        yearCount = 0;
        wordCount--;
    }
    if(dayCount > 0){
        if(flag == 0){
            if(dayCount == 1)
                sprintf(str, "%d day", dayCount);
            else
                sprintf(str, "%d days", dayCount);
            flag++;
        }
        else{
            if(dayCount == 1)
                sprintf(str, "%s%d day", str, dayCount);
            else
                sprintf(str, "%s%d days", str, dayCount);
        }
        if(wordCount == 2)
            strcat(str, " and ");
        else if(wordCount > 2)
            strcat(str, ", ");
        dayCount = 0;
        wordCount--;
    }
    if(hourCount > 0){
        if(flag == 0){
            if(hourCount == 1)
                sprintf(str, "%d hour", hourCount);
            else
                sprintf(str, "%d hours", hourCount);
            flag++;
        }
        else{
            if(hourCount == 1)
                sprintf(str, "%s%d hour", str, hourCount);
            else
                sprintf(str, "%s%d hours", str, hourCount);
        }
        if(wordCount == 2)
            strcat(str, " and ");
        else if(wordCount > 2)
            strcat(str, ", ");
        hourCount = 0;
        wordCount--;
    }
    if(minuteCount > 0){
        if(flag == 0){
            if(dayCount == 1)
                sprintf(str, "%d minute", minuteCount);
            else
                sprintf(str, "%d minutes", minuteCount);
            flag++;
        }
        else{
            if(dayCount == 1)
                sprintf(str, "%s%d minute", str, minuteCount);
            else
                sprintf(str, "%s%d minutes", str, minuteCount);
        }
        if(wordCount == 2)
            strcat(str, " and ");
        else if(wordCount > 2)
            strcat(str, ", ");
        wordCount--;
        minuteCount = 0;
    }
    if(n != 0){
        if(flag == 0){
            if(n == 1)
                sprintf(str, "%d second", n);
            else
                sprintf(str, "%d seconds", n);
            flag++;
        }
        else{
            if(n == 1)
                sprintf(str, "%s%d second", str, n);
            else
                sprintf(str, "%s%d seconds", str, n);
        }
    }
        
    return str;
}

int main(){
    while(1){
        int input = 0;
        scanf("%d", &input);
        printf("%s\n", formatDuration(input));
    }
    return 1;
}