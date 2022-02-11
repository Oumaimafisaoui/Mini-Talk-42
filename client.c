#include "minitalk.h"

// void    send_the_message(char *message, int server_pid)
// {
//     int index;
// 	int 	bit;

//     index = 0;
//     while(message[index])
//     {
// 		bit = -1;
// 		while(++bit <= 7)
// 		{
// 			if((message[index] & 128 >> bit))
//             {
//                 //if the first bit is 1 send sigusr2
// 		    	kill(server_pid, SIGUSR2);
//             }
//         	else 
//             {
//                 kill(server_pid, SIGUSR1);
//             }
//             usleep(200); //it will suspend the process
// 		}
//         index++;
//     }
// }

// #include <stdio.h>

void	ft_send_binary_to_server(char *text, int pid)
{
	int		i;
	int		bit_shift;

	i = -1;
	while (text[++i])
	{
		bit_shift = -1;
		while (++bit_shift < 8)
		{
			if (text[i] & 128 >> bit_shift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
		}
	}
}


int	main(int argc, char **argv)
{
	int pid;
	char 	*message;


	message = argv[2];
	pid = ft_atoi(argv[1]);
	if(argc == 3)
	{
    	ft_send_binary_to_server(message, pid);
	}
	else
	{
		ft_putstr_fd("Insert 3 arguments\n",1);
		return(0);
	}
	ft_putstr_fd(".....THE MESSAGE SENT TO THE SERVER.....\n",1);
	return (0);

}