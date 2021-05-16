#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void pack(char *buffer, int *out)
{
    for (int i = 0; i < strlen(buffer); i++)
    {
        int offset = 8 * (3 - i);
        out[i / 4] += buffer[i] << offset;
    }
}

int main()
{
    char buffer[101];

    printf("Ingrese texto(maximo 100 caracteres):\n");
    scanf("%s", buffer);

    size_t buffer_size = strlen(buffer);

    int m_packer_size = ceil(buffer_size / 4.0);

    int *buffer_packer = calloc(m_packer_size, sizeof(int));

    pack(buffer, buffer_packer);

    for (int i = 0; i < m_packer_size; i++)
    {
        printf("0x%X ", buffer_packer[i]);
    }

    free(buffer_packer);

    return 0;
}