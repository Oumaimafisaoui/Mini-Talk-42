#include "minitalk.h"
void	send_message(char *message, int pid)
{
	int		index;
	int		shift;

	index = 0;
	while (message[index])
	{
		shift = 0;
		while (shift <= 7)
		{
			if (message[index] & 128 >> shift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			shift++;
		}
		index++;
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
    	send_message(message, pid);
	}
	else
	{
		ft_putstr_fd("Insert 3 arguments\n",1);
		return(0);
	}
	ft_putstr_fd(".....THE MESSAGE SENT TO THE SERVER.....\n",1);
	return (0);

}