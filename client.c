#include <signal.h>
#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"
void killing_function(int pid, unsigned char byte)
{
	int i;
	unsigned char byte_tmp;
	
	i = 8;
	while(i-- > 0)
	{
		byte_tmp = byte >> i;
		if(byte_tmp %2 ==0)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		usleep(2000);
	}
}
int main(int argc, char **argv) {
	int clientID;
	char *str_to_send;
	int i;
	
	i =0;
	if(argc != 3)
	{
		ft_printf("uso -> ./client PID str_to_send");
		return 0;
	}
	clientID = ft_atoi(argv[1]);
	str_to_send = argv[2];
	while(str_to_send[i])
	{
		killing_function(clientID, (unsigned char)str_to_send[i]);
		i++;
	}
	ft_printf("se an escrito los caracteres correctamente");
	return 0;
}