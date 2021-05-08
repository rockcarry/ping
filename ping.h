#ifndef __PING_H__
#define __PING_H__

typedef void (*PFN_PING_CALLBACK)(void *cbctx, char *ip, int bytes, int ttl, int time, int seq);
void* ping_init(int interval, int timeout, PFN_PING_CALLBACK callback, void *cbctx);
void  ping_exit(void *ctx);
void  ping_run (void *ctx, char *ip, int start);
int   ping_isok(void *ctx);

#endif
