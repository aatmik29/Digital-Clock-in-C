#include <stdio.h>
#include <time.h>
#include <unistd.h>

void fill_time(char*,int);
void fill_date(char*);
void clear_scren();

int main(){
    char time[60], date[100];
    int n;
    printf("Choose the time format\n1.24 hour format\n2.12 hour format(default)\nEnter your choice: ");
    scanf("%d", &n);
    while(1){
        fill_time(time,n);
        fill_date(date);
        clear_screen();
        printf("\nCurrent Time: %s\n", time);
        printf("Date: %s", date);
        sleep(1);
    }
    return 0;
}
void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #endif
}

void fill_time(char* buffer,int format){
    time_t raw_time;
    struct tm *current_time;
    time(&raw_time);
    current_time = localtime(&raw_time);
    if(format == 1){
        strftime(buffer,60,"%H:%M:%S", current_time);
    }
    else{
        strftime(buffer, 60, "%I:%M:%S %p", current_time);
    }
}

void fill_date(char* buffer){
    time_t raw_time;
    struct tm* current_time;
    time(&raw_time);
    current_time = localtime(&raw_time);
    strftime(buffer, 100, "%A %d %B %Y", current_time);
}