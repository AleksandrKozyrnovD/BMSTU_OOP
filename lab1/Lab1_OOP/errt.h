#ifndef ERRT_H
#define ERRT_H

enum base_errors
{
    EXIT_SUCCESSFUL = 0, //Нет ошибок
    ERR_UNEXPECTED,      //Неожиданная ошибка
    ERR_IO,              //Ошибка ввода-вывода (неверный тип данных)
    ERR_RANGE,           //Ошибка Ввода - за границы допустимого значения
    ERR_PARAM,           //Неправильные параметры у функции
    ERR_MEM              //Не хватило памяти
};

using errors_t = enum base_errors;

#endif

