# Учебный проект на C

Простой проект на C с настроенной сборкой через Makefile и отладкой через VS Code.

## Требования

- MinGW-w64 (GCC для Windows)
- GDB для отладки
- Visual Studio Code с C/C++ расширениями

## Сборка

### Debug-сборка (сборка с отладочной информацией)

```
make BUILD_MODE=debug
```

или просто:

```
make
```

### Release-сборка (оптимизированная)

```
make BUILD_MODE=release
```

### Очистка проекта

```
make clean
```

### Полная пересборка

```
make rebuild
```

## Запуск

После успешной сборки исполняемый файл находится в:
- Debug: `bin/debug/app.exe`
- Release: `bin/release/app.exe`

## Отладка

Для запуска отладки в VS Code:

1. Откройте проект в VS Code
2. Соберите проект в режиме debug: `make BUILD_MODE=debug`
3. Нажмите F5 или выберите Run > Start Debugging
4. VS Code автоматически запустит отладчик, используя конфигурацию из `.vscode/launch.json`

### Настройки отладчика

Так как файл `.vscode/launch.json` может отсутствовать из-за включения в `.gitignore`, вот полная конфигурация для настройки отладчика:

Создайте директорию `.vscode` и файл `launch.json` со следующим содержимым:

```json
{
    "version": "0.2.0",
    "configurations": [
      {
        "name": "Debug app",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceFolder}/bin/debug/app.exe",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": false,
        "MIMode": "gdb",
        "miDebuggerPath": "C:/msys64/mingw64/bin/gdb.exe",  
        "setupCommands": [
          {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
          }
        ]
      }
    ]
  }
```

> **Примечание**: Убедитесь, что путь к GDB (`miDebuggerPath`) соответствует вашей системе. По умолчанию указан путь `C:/msys64/mingw64/bin/gdb.exe`. 