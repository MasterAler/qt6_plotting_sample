## qt6_plotting_sample

Рисует график, умеет запоминать пары (X;Sum(Y)).
Оси сложно не настраивал, логику проверял базовую.

Проверял:

* старт/стоп графика
* reset графика, во включенном/выключенном состоянии
* добавление результата при включенной генерации данных и при остановленной
* очищать результаты в любой момент времени, что не падает

### Сборка

Собрал под Qt6 & MSVC 2019 в Qt Creator, честно скажу, что под Ubuntu не собирал, пожалел времени.
По идее, можно собрать напрямую через CMake, указав `Qt6_DIR`, для чистоты приложу сгенерировавшиеся параметры сборки:
```
Commandline options:
-DQt6_DIR:PATH="E:/Qt/6.5.2/msvc2019_64/lib/cmake/Qt6" -DCMAKE_INSTALL_PREFIX:PATH="C:/Program Files (x86)/qt6_plotting_sample" 


Cache file:
Qt6_DIR:PATH=E:/Qt/6.5.2/msvc2019_64/lib/cmake/Qt6
CMAKE_INSTALL_PREFIX:PATH=C:/Program Files (x86)/qt6_plotting_sample
```