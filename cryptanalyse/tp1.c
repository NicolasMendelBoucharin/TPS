#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t **allocMat(int n)
{
    uint8_t **res = malloc(n * sizeof(uint8_t *));
    for (int i = 0; i < n; i++)
    {
        res[i] = malloc(n * sizeof(uint8_t));
    }
    return res;
}

void printState(uint8_t **state)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", state[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void xorKey(uint8_t **state, uint8_t **key)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] ^= key[i][j];
        }
    }
}

uint8_t S[] = {0xc, 0xa, 0xd, 0x3, 0xe, 0xb, 0xf, 0x7, 0x8, 0x9, 0x1, 0x5, 0x0, 0x2, 0x4, 0x6};

void apply_S(uint8_t **state)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] = S[state[i][j]];
        }
    }
}

uint8_t M[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 0}};

void apply_M(uint8_t **state)
{
    uint8_t **res = allocMat(4);
    uint8_t tmp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp = 0;
            for (int k = 0; k < 4; k++)
            {
                tmp ^= (M[i][k] * state[k][j]);
            }
            res[i][j] = tmp;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            state[i][j] = res[i][j];
        }
    }
}

void ShiftRow(uint8_t **state)
{
    uint8_t x0, x1, x2, x3;
    x0 = state[1][0];
    x1 = state[1][1];
    x2 = state[1][2];
    x3 = state[1][3];
    state[1][0] = x1;
    state[1][1] = x2;
    state[1][2] = x3;
    state[1][3] = x0;

    x0 = state[2][0];
    x1 = state[2][1];
    x2 = state[2][2];
    x3 = state[2][3];
    state[2][0] = x2;
    state[2][1] = x3;
    state[2][2] = x0;
    state[2][3] = x1;

    x0 = state[3][0];
    x1 = state[3][1];
    x2 = state[3][2];
    x3 = state[3][3];
    state[3][0] = x3;
    state[3][1] = x0;
    state[3][2] = x1;
    state[3][3] = x2;
}

void ShiftRowInv(uint8_t **state)
{
    uint8_t x0, x1, x2, x3;
    x0 = state[1][0];
    x1 = state[1][1];
    x2 = state[1][2];
    x3 = state[1][3];
    state[1][0] = x3;
    state[1][1] = x0;
    state[1][2] = x1;
    state[1][3] = x2;

    x0 = state[2][0];
    x1 = state[2][1];
    x2 = state[2][2];
    x3 = state[2][3];
    state[2][0] = x2;
    state[2][1] = x3;
    state[2][2] = x0;
    state[2][3] = x1;

    x0 = state[3][0];
    x1 = state[3][1];
    x2 = state[3][2];
    x3 = state[3][3];
    state[3][0] = x3;
    state[3][1] = x2;
    state[3][2] = x1;
    state[3][3] = x0;
}

uint8_t **Enc(uint8_t **msg, uint8_t **key, int R)
{
    uint8_t **cipher = allocMat(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cipher[i][j] = msg[i][j];
        }
    }
    for (int r = 0; r < R; r++)
    {
        xorKey(cipher, key);
        apply_S(cipher);
        ShiftRow(cipher);
        apply_M(cipher);
    }
    return cipher;
}

uint8_t **Dec(uint8_t **cipher, uint8_t **key, int R)
{
    uint8_t **msg = allocMat(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            msg[i][j] = cipher[i][j];
        }
    }
    for (int r = 0; r < R; r++)
    {
        apply_M(msg);
        ShiftRowInv(msg);
        apply_S(msg);
        xorKey(msg, key);
    }
    return msg;
}

int main()
{
    uint8_t **key = allocMat(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            key[i][j] = 0;
        }
    }

    uint8_t **msg = allocMat(4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            msg[i][j] = 0xa;
        }
    }
    printf("Msg :\n");
    printState(msg);

    uint8_t **cipher = Enc(msg, key, 10);
    printf("Cipher :\n");
    printState(cipher);

    uint8_t **decipher = Dec(cipher, key, 10);
    printf("Decipher :\n");
    printState(decipher);
}