/*
** EPITECH PROJECT, 2018
** CLIENT
** File description:
** client
*/

#include <SFML/Network.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mouse
{
    int x;
    int y;
    int clicked;
} mouse_t;

int client(char *str_address, int port)
{
    sfIpAddress address = sfIpAddress_fromString(str_address);
    sfTcpListener *listener = sfTcpListener_create();
    sfTcpSocket *socket = sfTcpSocket_create();
    mouse_t *my = malloc(sizeof(mouse_t) * 100);
    mouse_t *other = malloc(sizeof(mouse_t) * 100);
    size_t recived;

    sfTcpSocket_connect(socket, address, port, sfMilliseconds(5000));
    while (1) {
        my->x = 10;
        my->y = 15;
        my->clicked = 1;
        sfTcpSocket_send(socket, my, 100);
        if (sfTcpSocket_receive(socket, other, 100, &recived) != sfSocketDone)
            return 84;
        printf("%d - %d - %d\n", other->x, other->y, other->clicked);
        sfSleep(sfMilliseconds(10));
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        write(1, "USAGE : ./client [address] [port]\n", 35);
        return 84;
    }
    client(argv[1], atoi(argv[2]));
    return 0;
}