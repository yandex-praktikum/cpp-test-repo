#pragma once

using Number = double;

bool ReadNumber(Number& result);
// Возвращает true, если удалось прочитать число
// и сохраняет его в Number.

bool RunCalculatorCycle();
// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.

