#include <stdio.h>
#include <string.h>
#define X_SIZE  7
#define Y_SIZE  7

static char in[Y_SIZE][X_SIZE];
#define IN(x, y)    in[Y_SIZE-(y+3)-1][x+3]

static char out[Y_SIZE][X_SIZE];
#define OUT(x, y)   if (out[Y_SIZE-(y+3)-1][x+3]) {printf(",\"(%d,%d)\"", x, y);}

#define COPY(dst, src) memcpy(dst, src, sizeof(int)*X_SIZE*Y_SIZE)
#define SWAP(a,b) {char c=a;a=b;b=c;}


static char tmp[Y_SIZE][X_SIZE];

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

static void output(char* msg)
{
    printf("%s", msg);
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

static void mh(char m[][X_SIZE])
{
    int y, x;

    for (y=0; y<Y_SIZE; y++) {
        for (x=0; x<X_SIZE/2; x++) {
            SWAP(m[y][x], m[y][X_SIZE-x-1]);
        }
    }
}
static void mv(char m[][X_SIZE])
{
    int y, x;

    for (y=0; y<Y_SIZE/2; y++) {
        for (x=0; x<X_SIZE; x++) {
            SWAP(m[y][x], m[Y_SIZE-y-1][x]);
        }
    }
}
static void r90(char m[][X_SIZE])
{
    int y, x;

    COPY(tmp, m);
    for (y=0; y<Y_SIZE; y++) {
        for (x=0; x<X_SIZE; x++) {
            m[x][X_SIZE-y-1] = tmp[y][x];
        }
    }
}
static void r180(char m[][X_SIZE])
{
    r90(m);
    r90(m);
}
static void rn90(char m[][X_SIZE])
{
    r90(m);
    r90(m);
    r90(m);
}
static void r90_mv(char m[][X_SIZE])
{
    r90(m);
    mv(m);
}
static void r90_mh(char m[][X_SIZE])
{
    r90(m);
    mh(m);
}
int main(int argc, char* argv[])
{
    input(argc, argv);
    COPY(out, in);                 output("原圖");
    COPY(out, in);    r90(out);    output("右轉90度");
    COPY(out, in);   r180(out);    output("右轉180度");
    COPY(out, in);   rn90(out);    output("左轉90度");
    COPY(out, in);     mv(out);    output("垂直鏡射");
    COPY(out, in);     mh(out);    output("水平鏡射");
    COPY(out, in); r90_mv(out);    output("90度+垂直");
    COPY(out, in); r90_mh(out);    output("90度+水平");
    return 0;
}