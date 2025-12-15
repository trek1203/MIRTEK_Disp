Микроконтроллер -- STM32F411CEU6
Среда -- VScode
Программатор -- Jlink
Тулчейн -- arm-gcc-none-eabi
Генератор сборки -- CMake
Язык -- C++

src/display.* -- драйвер дисплея
src/init.* -- инициализация МК
src/interrupt.* -- прерывание, генерирующее LCD_Clk
src/main.* -- счётчик
src/spi.* -- драйвер программного SPI

diagramm/* -- диаграммы SPI и Clk, снятые лог. анализатором

.vscode/* -- настройки среды и дебагера

tools/* -- настройки jlink

vendor/* -- файлы производителя 

