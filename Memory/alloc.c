#include "../Include/stdint.h"

#include "alloc.h"

MemoryManager mgr;

void InitMemory()
{
    mgr.free = MEMPOOL;
}

void* AllocateMemory(DWORD size)
{
    if (size == 0 || size > mgr.free) 
    {
        return 0x00;
    }

    void* ptr = mgr.memory + (MEMPOOL - mgr.free);
    mgr.free -= size;

    /*
    Print("Allocation Size: ", 0x0F);
    PrintInt(size, 0x0C);
    Print("Address: ", 0x0F);
    PrintInt((DWORD)ptr, 0x0C);
    Print("Free: ", 0x0F);
    PrintInt(mgr.free, 0x0C);
    */

    return ptr;
}

void FreeMemory(void* ptr, DWORD size)
{
    if ((ptr >= (void*)(mgr.memory)) && (ptr < (void*)(mgr.memory + MEMPOOL)))
    {
        mgr.free += size;
    }
}