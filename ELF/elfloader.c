#include "../Include/stdint.h"
#include "../Font/text.h"
#include "../Memory/mem.h"
#include "../Memory/alloc.h"
#include "../FileSystem/memfs.h"

#include "elfloader.h"

//This code has some issues, it doesn't jump to
//Another address idk why. If someone could help I would appreciate!

int LoadELF(void* elfData)
{
    Print("\n", 0x00);
    Debug("Loading ELF...\n", 0x02);

    ELF32_Header* elfHeader = (ELF32_Header*) elfData;

    DWORD magic = *(DWORD*)elfHeader->e_ident;

    if (magic != ELFMAGIC)
    {
        Print("\n", 0x00);
        Debug("Invalid ELF File\n", 0x01);
        return -1;
    }

    Debug("Valid ELF File!\n", 0x00);

    if (elfHeader->e_machine != ELFARCH) 
    {
        Print("\n", 0x00);
        Debug("Not Suported Architecture!\n", 0x01);
        return -1;
    }

    Debug("Valid ELF Architecture!\n", 0x00);

    ELF32_ProgramHeader* programHeader = (ELF32_ProgramHeader*) (elfData + elfHeader->e_phoff);

    for (WORD i = 0; i < elfHeader->e_phnum; i++) 
    {
        if (programHeader[i].p_type == PTLOAD)
        {
            DWORD totalMemory = programHeader[i].p_memsz;
            LPBYTE segment = AllocateMemory(totalMemory);

            if (segment == NULL)
            {
                Debug("Memory Allocation Failed!\n", 0x01);
                return -1;
            }
            
            memcpy(segment, elfData + programHeader[i].p_offset, programHeader[i].p_filesz);
            memset(segment + programHeader[i].p_filesz, 0x00, programHeader[i].p_memsz - programHeader[i].p_filesz);

            Debug("ELF Segment Loaded at: ", 0x00);
            PrintHex((DWORD)segment, 0x0F);
            Print("\n", 0x00);

            break;
        }
    }

    Debug("ELF Entry: ", 0x02);
    PrintHex(elfHeader->e_entry, 0x0F);
    Print("\n", 0x00);

    Debug("ELF Entry Prepared!\n", 0x00);

    DWORD loadAddr = elfHeader->e_entry;

    typedef void (*entryPoint)(void);
    entryPoint programEntry = (entryPoint) loadAddr;
    programEntry();

    return 0x00;
}

void ExecuteELF(void* elf)
{
    if (LoadELF(elf))
    {
        Debug("Failed to Load ELF File!\n", 0x01);
        return;
    }
}
