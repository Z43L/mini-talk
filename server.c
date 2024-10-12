#include <signal.h>
#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"

void action(int sigsend)
{
	static unsigned char	buff;
	static int				i;
	
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
}
int main(void) {
	ft_printf("El ID del cliente es: %i\n", getpid());
	signal(SIGUSR2, action);
	signal(SIGUSR1, action);
	while (1)
		pause();
	return (0);
}