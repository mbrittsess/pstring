Import-Module QuickPelles-CTools

Compile-CFile pstring.c -IncludePath $CrtInclude -RuntimeLibrary MultiStatic | Link-Executable -LibraryPath $CrtLib, $WindowsLib64