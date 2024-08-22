#include <stdio.h>
#include <stdlib.h>


void class_ipv4(char *ip_address)
{
    int ip_incr;
    int bit_incr;

    int int_init_octet;
    int int_2nd_octet;
    int int_3rd_octet;
    int int_4th_octet;

    char bits_init[10];
    char bits_2nd[10];
    char bits_3rd[10];
    char bits_4th[10];


    ip_incr = 0;
    
    	
    
    //Recuperqtion de la premiere octet
    bit_incr = 0;
    while (ip_address[ip_incr] != '.')
    {
        bits_init[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_init[bit_incr] = '\0';

    //recuperation de la 2eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_2nd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_2nd[ip_incr] = '\0';
    int_2nd_octet = atoi(bits_2nd);

    //recuperation de la 3eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '.')
    {
        bits_3rd[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_3rd[ip_incr] = '\0';
	
    int_3rd_octet = atoi(bits_3rd);

    //recuperation de la 4eme octet
    bit_incr = 0;
    ip_incr++;
    while (ip_address[ip_incr] != '\0')
    {
        bits_4th[bit_incr] = ip_address[ip_incr];
        bit_incr++;
        ip_incr++;
    }
    bits_4th[ip_incr] = '\0';

    int_4th_octet = atoi(bits_4th);

    
    int_init_octet = atoi(bits_init);
    
    //teste de la classe
    if (int_init_octet > 255 || int_2nd_octet > 255 || int_3rd_octet > 255 || int_4th_octet > 255)
	{
		printf("Content-Type: Text/html\n\n");
		printf("IP: invalid\n");
		exit (EXIT_FAILURE);
	}
    
    if (int_init_octet >= 0 && int_init_octet <= 127)
    {
        printf("Content-Type: Text/html\n\n");
        printf("Class: A");
    }
    else if (int_init_octet >= 128 && int_init_octet <= 191)
    {
        printf("Content-Type: Text/html\n\n");
        printf("Class: B");
    }
    else if (int_init_octet >= 192 && int_init_octet <= 223)
    {
        printf("Content-Type: Text/html\n\n");
        printf("Class: C");
    }
    else if (int_init_octet >= 224 && int_init_octet <= 239)
    {
        printf("Content-Type: Text/html\n\n");
        printf("Class: D");
    }
    else if (int_init_octet >= 240 && int_init_octet <= 255)
    {
        printf("Content-Type: Text/html\n\n");
        printf("Class: E");
    }
	
}

char *get_ip()
{
	char *ip = malloc(sizeof(char)*255);
	printf("Entrer l'address IP : ");
	scanf("%s", ip);

	return ip;
}

int main()
{
	class_ipv4(get_ip());
	return 0;	
}
