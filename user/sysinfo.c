#include "kernel/types.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

const int SCALEUP = 1000;

void print_fixed_point(int n, int d)
{
    // d = 10^x (x is a positive integer)
    printf("%d.", (int) n / d);
    int fraction = n % d;
    int tmp = d / 10;
    while (fraction < tmp)
    {
        printf("0");
        tmp /= 10;
    }
    printf("%d", fraction);
}

int main(int argc, char *argv[])
{
    struct sysinfo s;
    if (sysinfo(&s) < 0)
    {
        printf("sysinfo failed\n");
        exit(1);
    }
    else
    {
        printf("freemem: %ld\n", s.freemem);
        printf("nproc: %ld\n", s.nproc);
        printf("loadavg: ");
        print_fixed_point(s.loadavg_1m, SCALEUP);
        printf(", ");
        print_fixed_point(s.loadavg_5m, SCALEUP);
        printf(", ");
        print_fixed_point(s.loadavg_15m, SCALEUP);
        printf("\n");
    }

    exit(0);
}