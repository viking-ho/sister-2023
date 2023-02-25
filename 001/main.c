#include <stdio.h>
#include <string.h>
#define X_SIZE  7
#define Y_SIZE  7

static char in[Y_SIZE][X_SIZE];
#define IN(x, y)    in[Y_SIZE-(y+3)-1][x+3]

static char out[Y_SIZE][X_SIZE];
#define OUT(x, y)   if (out[Y_SIZE-(y+3)-1][x+3]) {printf("(%d,%d)", x, y);}

#define COPY(dst, src) memcpy(dst, src, sizeof(int)*X_SIZE*Y_SIZE)

static void input(int argc, char* argv[])
{
    IN(0,1)=1;
    IN(0,2)=1;
    IN(-1,0)=1;
    IN(-1,-2)=1;
    IN(0,-2) = 1;
    IN(0,-3) = 1;
    IN(1,-1) = 1;
}

static void output()
{
    OUT(0,0);//1
    OUT(1,0);//2
    OUT(2,0);//3
    OUT(3,0);//4
    OUT(1,1);//5
    OUT(1,2);//6
    OUT(1,3);//7
    OUT(2,1);//8
    OUT(3,1);//9
    OUT(0,1);//10
    OUT(0,2);//11
    OUT(0,3);//12
    OUT(-1,1);//13
    OUT(-1,2);//14
    OUT(-1,3);//15
    OUT(-2,1);//16
    OUT(-3,1);//17
    OUT(-1,0);//18
    OUT(-2,0);//19
    OUT(-3,0);//20
    OUT(-1,-1);//21
    OUT(-1,-2);//22
    OUT(-1,-3);//23
    OUT(-2,-1);//24
    OUT(-3,-1);//25
    OUT(0,-1);//26
    OUT(0,-2);//27
    OUT(0,-3);//28
    OUT(1,-1);//29
    OUT(1,-2);//30
    OUT(1,-3);//31
    OUT(2,-1);//32
    OUT(3,-1);//33
    printf("\n");
}

int main(int argc, char* argv[])
{
    input(argc, argv);
    COPY(out, in);
    output();
    return 0;
}