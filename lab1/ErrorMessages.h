#ifndef ERRORMESSAGES_H
#define ERRORMESSAGES_H

#define OK 0
#define ERROR_READING_FILE 1
#define ERROR_FILE_FORMAT 2
#define ERROR_ALLOC_MEMORY 2
#define ERROR_EMPTY 3
#define ERROR_COMMAND 4

#include "QMessageBox"

void ErrorMessages(int codeError);

#endif // ERRORMESSAGES_H
