#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    uint32_t sum = 0;
    
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        
        uint32_t num;
        fread(&num, 4, 1, fp);
        
        num = ntohl(num);
        
        if (i > 1) {
            printf(" + ");
        }
        printf("%d(0x%x)", num, num);
        
        sum += num;
        
        fclose(fp);
    }
    
    printf(" = %d(0x%x)\n", sum, sum);
    
    return 0;
}
