#define MEMPOOL 8192

typedef struct
{
    BYTE memory[MEMPOOL];
    DWORD free;
} MemoryManager;

void InitMemory();
void* AllocateMemory(DWORD size);
void FreeMemory(void* ptr, DWORD size);