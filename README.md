# CSFML_peer_to_peer

## Getting started :

Server side :
```shell
make
cd SERVER
./network [port]
```

Server side open port:
```shell
sudo iptables -I INPUT -p tcp --dport [port] --syn -j ACCEPT
```

Client side :
```shell
make
cd CLIENT
./client [server IP] [port]
```

## Infos :

By default, the program will send `mouse_t` struct infos and recive same type from other client to print it.
You can change this directly into the code.

## Dependencies :

CSFML
