#include <QObject>
#include "QMessageBox"
#include "CodeErrors.h"

void error_message(int codeError)
{
    if (codeError == ERROR_READING_FILE)
    {
        QMessageBox::critical(NULL, "ERROR", "ERROR_READING_FILE");
    }
    else if (codeError == ERROR_FILE_FORMAT)
    {
        QMessageBox::critical(NULL, "ERROR", "ERROR_FILE_FORMAT");
    }
    else if (codeError == ERROR_ALLOC_MEMORY)
    {
        QMessageBox::critical(NULL, "ERROR", "ERROR_ALLOC_MEMORY");
    }
    else if (codeError == ERROR_EMPTY)
    {
        QMessageBox::critical(NULL, "ERROR", "ERROR_EMPTY");
    }
    else if (codeError == ERROR_INPUT)
    {
        QMessageBox::critical(NULL, "ERROR", "ERROR_INPUT");
    }
}
