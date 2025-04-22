/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

void SysPrintInt (int number) // 實作 PrintInt
{
	kernel->synchConsoleOut->PutInt(number);
}

OpenFileId SysOpen(char *name) {
	// Open a file with the name, and returns its corresponding OpenFileId.
	// Return -1 if open fails
	return kernel->fileSystem->OpenF(name);
	
}

int SysWrite(char *buffer, int size, OpenFileId id) {
	// Write “size” characters from buffer into the file
	// Returns number of characters actually written to the file
	// If attempt writing to an invalid id, return -1
	return kernel->fileSystem->WriteF(buffer, size, id);
}

int SysRead(char *buffer, int size, OpenFileId id) {
	// Read “size” characters from file into the buffer
	// Returns number of characters actually read from the file
	// If attempt reading from an invalid id, return -1
	return kernel->fileSystem->ReadF(buffer, size, id);
}

int SysClose(OpenFileId id) {
	// Close the file with id
	// Return 1 if successfully close the file, 0 otherwise
	return kernel->fileSystem->CloseF(id);
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
