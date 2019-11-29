#!/bin/bash

CHIBIOS_VERSION=19.1.3

mkdir lib
cd lib
wget -O chibios.7z https://osdn.net/dl/chibios/ChibiOS_$CHIBIOS_VERSION.7z
7z x chibios.7z
mv ChibiOS_$CHIBIOS_VERSION chibios
rm chibios.7z
