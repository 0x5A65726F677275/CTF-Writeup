#include <stdio.h>
#include <stdint.h>

int main() {
    const char data_set[] = "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";
    uint32_t r[3] = {0x6B8B4567, 0x327B23C6, 0x643C9869};
    char flag[20] = {0}; // 19 chars + null terminator

    for (int i = 0; i < 19; i++) {
        flag[i] = data_set[r[2] & 0x1F];
        r[2] = (r[2] >> 5) | (r[1] << 27);
        r[1] = (r[1] >> 5) | (r[0] << 27);
        r[0] = r[0] >> 5;
    }

    printf("%s\n", flag); // Output: KDG3DU32D38EVVXJM64
    return 0;
}