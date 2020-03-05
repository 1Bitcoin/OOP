#include "ErrorMessages.h"

void ErrorMessages(int codeError)
{
    if (codeError == ERROR_READING_FILE)
    {
        QMessageBox::critical(NULL, "ERROR", "File is broken or not found");
    }
    else if (codeError == ERROR_FILE_FORMAT)
    {
        QMessageBox::critical(NULL, "ERROR", "File format error");
    }
    else if (codeError == ERROR_ALLOC_MEMORY)
    {
        QMessageBox::critical(NULL, "ERROR", "Error with memory allocation");
    }
    else if (codeError == ERROR_EMPTY)
    {
        QMessageBox::critical(NULL, "ERROR", "Load model!");
    }
    else if (codeError == ERROR_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Unknown manager instruction!");
    }
}

