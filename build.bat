@echo off
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\Hostx64\x64\cl.exe" src\launcher\launcher.cpp /Fe:bin\launcher.exe /std:c++17 /EHsc
bin\launcher.exe