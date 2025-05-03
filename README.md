# Учебный проект на C

Простой проект на C с настроенной сборкой через Makefile и отладкой через VS Code.

## Требования

- **MinGW-w64** (GCC для Windows) - компилятор C/C++
- **GDB** - отладчик
- **Visual Studio Code** - редактор кода
- **Расширения VS Code**:
  - C/C++ Extension Pack
  - C/C++ Extension (Microsoft)

### Установка MinGW-w64 и GDB

1. Скачайте и установите MSYS2 с [официального сайта](https://www.msys2.org/)
2. Откройте MSYS2 MINGW64 и выполните:
   ```
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb make
   ```
3. Добавьте `C:\msys64\mingw64\bin` в переменную PATH

## Сборка проекта

### Debug-сборка (с отладочной информацией)

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

## Запуск приложения

После успешной сборки исполняемый файл находится в:
- Debug: `bin/debug/app.exe`
- Release: `bin/release/app.exe`

## Работа в VS Code

### Сборка через VS Code

1. Откройте панель задач: `Terminal > Run Task...`
2. Выберите задачу **Make build**
3. Или используйте сочетание клавиш <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>

### Запуск приложения через VS Code

1. Откройте панель задач: `Terminal > Run Task...`
2. Выберите задачу **Run app**

### Отладка через VS Code

1. Установите точки останова в коде (клик на полях слева от номеров строк)
2. Нажмите <kbd>F5</kbd> или выберите меню `Run > Start Debugging`
3. VS Code автоматически запустит отладчик

## Конфигурационные файлы

### tasks.json

Файл `.vscode/tasks.json` содержит настройки задач для VS Code:

```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "Make build",
			"command": "make",
			"args": [
				"build",
				"BUILD_MODE=debug"
			],
			"options": {
				"cwd": "${workspaceFolder}"
			},
			"problemMatcher": [
				"$msCompile"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compiler: make"
		},
		{
			"label": "Run app",
			"type": "shell",
			"command": "cmd",
			"args": [
				"/c",
				"start",
				"cmd",
				"/k",
				"${workspaceFolder}/bin/debug/app.exe"
			],
			"group": "none",
			"problemMatcher": []
		}
	]
}
```

### launch.json

Файл `.vscode/launch.json` содержит настройки отладки:

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
            "environment": [
                {
                    "name": "CHCP",
                    "value": "65001"
                }
            ],
            "externalConsole": false, 
            "MIMode": "gdb",
            "preLaunchTask": "Make build",
            "miDebuggerPath": "C:/msys64/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": false
                }
            ]
        }
    ]
}
```

> **Примечание**: 
> - Убедитесь, что путь к GDB (`miDebuggerPath`) соответствует вашей системе
> - Настройка `CHCP=65001` обеспечивает поддержку UTF-8 в консоли

## Настройка Git

В проекте настроен `.gitignore` для исключения ненужных файлов из системы контроля версий.
При этом файлы конфигурации `.vscode/tasks.json` и `.vscode/launch.json` включены в Git,
что позволяет всем разработчикам использовать единую конфигурацию проекта.