// Server program
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>

char **reverse(char **msg)
{
    static char *result;
    int i, j, len;
    len = strlen(*msg);
    result = malloc(len+1);
    for (i = len - 1, j = 0; i >= 0; i--, j++)
        result[j] = (*msg)[i];
    result[len] = '\0';
    return &result;
}

int main()
{
    // Register the RPC service
    registerrpc(1, 1, 1, reverse, xdr_wrapstring, xdr_wrapstring);

    // Start the RPC server
    svc_run();

    return 0;
}
