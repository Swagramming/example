#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void hook(int signo, void (*handler)())
{
    if (signal(signo, handler) == SIG_ERR)
        printf("Can't hook SIGINT\n");
}

void sigabrt_handler(int signo)
{
    puts("Caught SIGABRT");
}

void sigint_handler(int signo)
{
    puts("Caught SIGINT");
}

void sigsegv_handler(int signo)
{
    puts("Caught SIGSEGV");
}

void sigterm_handler(int signo)
{
    puts("Caught SIGTERM");
}

int main()
{
    hook(SIGABRT, sigabrt_handler);
    hook(SIGINT, sigint_handler);
    hook(SIGSEGV, sigsegv_handler);
    hook(SIGTERM, sigterm_handler);

    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: *(int*)NULL = 0;
        case 2: abort();
        case 3: raise(SIGINT); /* ili CTRL+C */
        case 4: raise(SIGTERM); /* ili pkill */
    }
}
