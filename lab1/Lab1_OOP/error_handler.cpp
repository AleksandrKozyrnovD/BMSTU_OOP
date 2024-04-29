#include "error_handler.h"

void handle_error(errors_t error)
{
    switch (error)
    {
    case EXIT_SUCCESSFUL:
        return;
    case ERR_UNEXPECTED:
        QMessageBox::critical(NULL, "Ошибка", "Произошла неожиданная ошибка");
        break;
    case ERR_IO:
        QMessageBox::critical(NULL, "Ошибка ввода", "Произошла ошибка ввода");
        break;
    case ERR_RANGE:
        QMessageBox::critical(NULL, "Ошибка", "Ввод за границы допустимого значения");
        break;
    case ERR_MEM:
        QMessageBox::critical(NULL, "Ошибка", "Не хватило памяти на программу!");
        break;
    default:
        QMessageBox::critical(NULL, "Ошибка", "Произошла неожиданная ошибка");
        break;
    }
}
