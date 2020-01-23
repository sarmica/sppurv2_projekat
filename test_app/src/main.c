#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_LEN 80

int main()
{
    int file_desc;
    int ret_val;
    char tmp[BUF_LEN];
	char open_door = 'o';
	char close_door = 'c';
	char stop_door = 's';
    printf("Welcome to team Hector's test app!\n");
	
    file_desc = open("garage", O_RDWR);

    if(file_desc < 0)
    {
        printf("Error, 'garage' not opened\n");
        return -1;
    }
	
	
	printf("Please, make sure there are no obstacles or movement near the sensors!\n");
	printf("Trying to open the garage door...\n");
	write(file_desc,open_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);


	printf("Please, make sure there are no obstacles or movement near the sensors!\n");
	printf("Trying to stop the door...\n");
	write(file_desc,stop_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	
	
	printf("Please, make sure there are no obstacles or movement near the sensors!\n");
	printf("Trying to close the door...\n");
	write(file_desc,close_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	
	printf("Please, add an obstacle or move in front of the sensor!\n");
	printf("Trying to open the door...\n");
	write(file_desc,open_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	
	printf("Please, remove all obstacles, and move away from the sensors\n");
	read(file_desc, tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	
	
	printf("Please, add an obstacle or move in front of the sensor!\n");
	printf("Trying to close the door...\n");
	write(file_desc,close_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	
	printf("Please, remove all obstacles, and move away from the sensors\n");
	read(file_desc, tmp, BUF_LEN);
	printf("Current state:\n");
	printf("%s", tmp);
	

   
    close(file_desc);
    
    return 0;
}