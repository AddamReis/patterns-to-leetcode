@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

set "ROOT=%~dp0.."
set "SOURCE=%~1"

if "%SOURCE%"=="" (
    echo Uso:
    echo   scripts\build.bat patterns\prefix-sum\prefix_sum.cpp
    exit /b 1
)

set "SOURCE_PATH=%ROOT%\%SOURCE%"

if not exist "%SOURCE_PATH%" (
    echo Arquivo nao encontrado: %SOURCE%
    exit /b 1
)

where cl.exe >nul 2>nul
if errorlevel 1 (
    set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
    set "VS_PATH="

    if exist "!VSWHERE!" (
        for /f "usebackq delims=" %%I in (`"!VSWHERE!" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do (
            set "VS_PATH=%%I"
        )
    )

    if defined VS_PATH if exist "!VS_PATH!\VC\Auxiliary\Build\vcvars64.bat" (
        call "!VS_PATH!\VC\Auxiliary\Build\vcvars64.bat" >nul
    ) else if exist "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" >nul
    ) else if exist "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat" (
        call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Auxiliary\Build\vcvars64.bat" >nul
    ) else (
        echo Nao foi possivel encontrar vcvars64.bat
        exit /b 1
    )
)

for %%F in ("%SOURCE_PATH%") do set "OUTPUT_NAME=%%~nF"

if not exist "%ROOT%\build" mkdir "%ROOT%\build"
pushd "%ROOT%\build"

del /q "%OUTPUT_NAME%.exe" "%OUTPUT_NAME%.pdb" "%OUTPUT_NAME%.ilk" "%OUTPUT_NAME%.obj" 2>nul

cl.exe /Zi /Od /RTC1 /EHsc /nologo "%SOURCE_PATH%" /Fe:"%OUTPUT_NAME%.exe" /Fo:"%OUTPUT_NAME%.obj" /Fd:"%OUTPUT_NAME%.pdb"

if !errorlevel! neq 0 (
    echo Erro na compilacao!
    popd
    exit /b 1
)

echo Build de debug concluido: %ROOT%\build\%OUTPUT_NAME%.exe

popd
