/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** send_signal
*/

#include <signal.h>
#include <unistd.h>

static void send_signal_usr2(int pid)
{
    kill(pid, SIGUSR2);
    usleep(1000);
}

static void send_signal_usr1(int pid)
{
    kill(pid, SIGUSR1);
    usleep(1000);
}

int send_signal(char **binary_tab, char *entry, int pid)
{
    int count = (entry[0] - 'A');
    for (int i = 0; i != 3; i += 1){
        if (binary_tab[count][i] == '0')
            send_signal_usr1(pid);
        if (binary_tab[count][i] == '1')
            send_signal_usr2(pid);
    }
    count = (entry[1] - '1');
    for (int i = 0; i != 3; i += 1){
        if (binary_tab[count][i] == '0')
            send_signal_usr1(pid);
        if (binary_tab[count][i] == '1')
            send_signal_usr2(pid);
    }
    return 0;
}
