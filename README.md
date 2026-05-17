The problem was the client’s wait loop. pause() can miss the ACK if the server responds before the client enters the sleep, so the message send can hang or behave unpredictably. I fixed that in client.c by blocking SIGUSR1 and waiting with sigsuspend(), which makes the ACK handshake atomic.

