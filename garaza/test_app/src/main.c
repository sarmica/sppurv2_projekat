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
    char tmp[BUF_LEN];
    char open_door='o';
    char close_door='c';
    char stop_door='s';

    printf("\n**********Welcome to team Hector's test app!**********\n\n");

    file_desc = open("/dev/garage", O_RDWR);

    if(file_desc < 0)
    {
        printf("Error, 'garage' not opened\n");
        return -1;
    }

        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	printf("\nPlease, make sure there are no obstacles or movement near the sensors!\n");
	printf("Trying to open the garage door...\n");
	write(file_desc,&open_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state: %s", tmp);
	usleep(2000000);

	printf("\nTrying to stop the door...\n");
	write(file_desc,&stop_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state: %s", tmp);

	printf("\nTrying to close the door...\n");
	write(file_desc,&close_door,1);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state: %s", tmp);
	memset(tmp, 0, BUF_LEN);
	usleep(2000000);

	read(file_desc,tmp, BUF_LEN);
        printf("\nCurrent state: %s", tmp);

	printf("\nTrying to open the garage door...\n");
        write(file_desc,&open_door,1);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);
	printf("\nPlease, add an obstacle or move in front of the sensor!\n");
	usleep(3000000);
	printf("Trying to open the door...\n");
	write(file_desc,&open_door,1);
	read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	
	printf("\nPlease, remove all obstacles, and move away from the sensors\n");
	usleep(3000000);
	read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);
	printf("\nTrying to open the door...\n");
        write(file_desc,&open_door,1);
	usleep(2000000);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);
	memset(tmp, 0, BUF_LEN);
	usleep(2000000);
        read(file_desc,tmp, BUF_LEN);
        printf("\nCurrent state: %s", tmp);

	printf("\nTrying to stop the door...\n");
        write(file_desc,&stop_door,1);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	printf("\nTrying to close the door...\n");
	write(file_desc,&close_door,1);
	usleep(1000000);
	read(file_desc,tmp, BUF_LEN);
	printf("Current state: %s", tmp);

	printf("\nPlease, add an obstacle or move in front of the sensor!\n");
        usleep(3000000);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	printf("\nTrying to open the door...\n");
        write(file_desc,&open_door,1);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	printf("\nPlease, remove all obstacles, and move away from the sensors\n");
	usleep(3000000);
	read(file_desc, tmp, BUF_LEN);
	printf("Current state: %s", tmp);

	printf("\nTrying to open the door...\n");
        write(file_desc,&open_door,1);
	usleep(2000000);
        read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);
	memset(tmp, 0, BUF_LEN);
        usleep(2000000);
        read(file_desc,tmp, BUF_LEN);
        printf("\nCurrent state: %s", tmp);
	memset(tmp, 0, BUF_LEN);

	printf("\nGarage door will automatically start closing after 10 seconds\n");
	usleep(10000000);
	read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);
	memset(tmp, 0, BUF_LEN);

	printf("\n...and will be closed after 5 seconds\n");
	usleep(5000000);
	read(file_desc,tmp, BUF_LEN);
        printf("Current state: %s", tmp);

	printf("\n\n**********The end**********\n");

    close(file_desc);
    
    return 0;
}
