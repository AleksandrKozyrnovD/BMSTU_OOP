#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <QMessageBox>
#include "errt.h"

/**
 * @brief Функция обработки ошибок (вывод информации об ошибке)
 * 
 * @param[in] error код ошибки 
 */
void handle_error(errors_t error);

#endif // ERROR_HANDLER_H
