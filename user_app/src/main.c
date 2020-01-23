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
    char entry;
    char buffer[BUF_LEN];
	
    printf("Welcome to the garage door user app\n");
    printf("Please choose from one of the following options:\n");
    printf("\nO-open,\n\nS-stop,\n\nC-close\n\n");

    file_desc = open("/dev/garage", O_RDWR);

    if(file_desc < 0)
    {
                printf("Error, 'garage' not opened\n");
                return -1;
    
    }

	while(1)
	{
		scanf("%c", &entry);
		if(entry == 'o' || entry == 'c' || entry == 's' || entry == 'O' || entry == 'C' || entry == 'S')
		{
			ret_val = write(file_desc, &entry, 1);
		}
		if(entry == 'r')
		{
			write(file_desc, &entry, 1);
                        read(file_desc, buffer, sizeof(buffer));
			printf("%s", buffer);
			fflush(stdout);

                }

		if(entry == 'q')
		{
			break;
		}
		memset(&entry,0,sizeof(char));
		memset(buffer,0,sizeof(buffer));

	}
    close(file_desc);
    return 0;
}
