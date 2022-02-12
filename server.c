#include "minitalk.h"
static void     print_pid(void)
{
    pid_t   pid;

    pid = getpid();
    if(pid == 0)
        return ;
    write(1, "Server pid:[",12);
    ft_putnbr_fd(pid, 1);
    write(1, "]\n",2);
}

void    message_handler(int signal)
{
    static int power;
    static int character;

    if(signal == SIGUSR1)
        character += 1 << (7 - power);
    power++;
    if(power == 8)
    {
        ft_putchar_fd(character, 1);
        power = 0;
        character = 0;
    }
}

int main()
{
    struct sigaction	action;
	action.sa_handler = &message_handler;
    print_pid();
	while (5)
	{
			sigaction(SIGUSR1, &action, NULL);
			sigaction(SIGUSR2, &action, NULL);
			pause();
	}
	  
	return (0);
}

