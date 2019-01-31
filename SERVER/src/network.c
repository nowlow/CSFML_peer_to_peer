/*
** EPITECH PROJECT, 2018
** Network
** File description:
** network
*/

#include <SFML/Network.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct mouse
{
    int x;
    int y;
    int clicked;
} mouse_t;

char *fill_buffer(char *buffer, int size)
{
    for (int i = 1; i < size; i += 1) {
        buffer[i] = 0;
    }
    return buffer;
}

int network(int integer_port)
{
    unsigned short port = (unsigned short) integer_port;
    sfTcpListener *listener = sfTcpListener_create();
    sfTcpSocket *socket = sfTcpSocket_create();
    sfSocketStatus status = sfTcpSocket_connect(socket,
                                                sfIpAddress_getLocalAddress(),
                                                port, sfMilliseconds(5000));
    mouse_t *my = malloc(sizeof(mouse_t) * 100);
    mouse_t *other = malloc(sizeof(mouse_t) * 100);
    size_t recived;

    printf("Adress = %s:%d\n", sfIpAddress_getLocalAddress().address, port);
    if (sfTcpListener_listen(listener, port, sfIpAddress_getLocalAddress()) !=
                                sfSocketDone)
        return 84;
    if (sfTcpListener_accept(listener, &socket) != sfSocketDone)
        return 84;
    printf("> %s\n", sfTcpSocket_getRemoteAddress(socket).address);
    while (1) {
        my->x = 55;
        my->y = 100;
        my->clicked = 0;
        if (sfTcpSocket_receive(socket, other, 100, &recived) != sfSocketDone)
            return 84;
        sfTcpSocket_send(socket, my, 100);
        printf("%d - %d - %d\n", other->x, other->y, other->clicked);
        sfSleep(sfMilliseconds(10));
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    network(atoi(argv[1]));
    return 0;
}
