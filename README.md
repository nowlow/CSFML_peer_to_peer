# CSFML_peer_to_peer

Server side :
```shell
make
cd SERVER
./network [port]
```

Server side open port:
```shell
sudo iptables -I INPUT -p tcp --dport 1337 --syn -j ACCEPT
```

Client side :
```shell
make
cd CLIENT
./client [server IP] [port]
```
