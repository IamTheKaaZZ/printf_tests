#!/bin/sh
# Little script to import and make the simple_debug library file used for the tester
#echo Cloning and compiling debugs.a library...
git clone https://github.com/m4r11/simple_debug simple_debug --quiet
cd simple_debug/
make --silent
cp debugs.a simple_debugs.h ..
cd ..
rm -rf simple_debug
#echo debugs.a finished!
