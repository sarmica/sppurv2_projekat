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
    char entry;
    char buffer[BUF_LEN];
	
    printf("\n\n**********Welcome to the garage door user app**********\n\n");
    printf("Please choose from one of the following options:\n");
    printf("\no-open,\n\ns-stop,\n\nc-close,\n\nr-read,\n\nq-quit.\n\n");

    file_desc = open("/dev/garage", O_RDWR);

    if(file_desc < 0)
    {
                printf("Error, '/dev/garage' not opened\n");
                return -1;
    
    }

	while(1)
	{
		scanf("%c", &entry);
		if(entry == 'o' || entry == 'c' || entry == 's')
		{
	
			write(file_desc, &entry, 1);

		}
		else if(entry == 'r')
		{
			write(file_desc, &entry, 1);
                        read(file_desc, buffer, sizeof(buffer));
			printf("Door is currently: %s\n", buffer);
			fflush(stdout);

                }
		else if(entry == 'q')
		{
			break;
		}

		memset(&entry,0,sizeof(char));
		memset(buffer,0,sizeof(buffer));

	}
    close(file_desc);
    return 0;
}
