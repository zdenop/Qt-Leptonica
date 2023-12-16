QT leptonica is just simle test to use leptonica library within Qt5 project


# Install

## Windows

### Install Leptonica

Follow instruction on [Leptonica wiki](https://github.com/DanBloomberg/leptonica/wiki#windows)

### Build Qt Leptonica

Set `PATH` to QT and Leptonica installation

```sh
set QTDIR=f:/Qt/5.15.2/msvc2019_64
set LEPTONICA=C:/Projects/win64
set PATH=%QTDIR%/bin;%LEPTONICA%/bin;%PATH%
```

```
rm -Rf build/*
cmake -G "Visual Studio 16 2019" -A x64 -S . -B build -DCMAKE_PREFIX_PATH="%QTDIR%;%LEPTONICA%"
cmake --build build --config Release --verbose
copy build\Release\Qt-leptonica-1.0-alpha.exe %LEPTONICA%
```
