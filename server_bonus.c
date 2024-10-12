#include <signal.h>
#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"

void action(int sigsend,siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static int				i;
	
	(void) context;
	buff |= (sigsend == SIGUSR1);
	i++;
	if (i == 8)
		{
			ft_printf("%c", buff);
			i = 0;
			buff = 0;
		}
	else
		buff <<= 1;
	if (sigsend == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sigsend == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}
int main(void)
{
	struct sigaction	sa;
	
	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("El ID del cliente es: %i\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}