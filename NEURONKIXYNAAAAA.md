<p align="right">
  <i>«...Нууу ээээ короче соси...»</i><br>
  <b>А. С. Пушкин, «Евгений Онегин»</b>
</p>

# 🎭 Onegin Sorter

> Программа на C, которая берёт английский текст из заданного файла, сортирует все строки тремя способами и записывает результат в выходной файл.

## 📖 О проекте

**Onegin Sorter** — это учебный проект на языке C, демонстрирующий работу с файлами, строками, динамической памятью и алгоритмами сортировки. Программа читает английский текст (например, перевод «Евгения Онегина» А. С. Пушкина), а затем создаёт выходной файл, содержащий **три блока**:

1. **Part 1. Sorted** — строки, отсортированные с начала (слева направо), не-буквенные символы игнорируются.
2. **Part 2. mc Pushkaas** — строки, отсортированные с конца (справа налево), не-буквенные символы также игнорируются.
3. **Part 3. A. S. Pushkin "Eugene Onegin"** — оригинальный текст в исходном порядке.

Для сортировки используются **два алгоритма**:
- 🐢 Собственная реализация **пузырьковой сортировки** (bubble sort);
- ⚡ Встроенный в стандартную библиотеку C **`qsort`** (быстрая сортировка).

---

## ✨ Возможности

- 📥 Чтение английского текста из произвольного файла
- 📤 Запись результата в отдельный файл
- 🔤 Два режима сортировки строк (с начала и с конца)
- 🚫 Игнорирование не-буквенных символов при сортировке
- 📝 Подробное логирование всех этапов работы
- ⚙️ Гибкая настройка через `config.h`
- 🧩 Скрипт `build.sh` для быстрой сборки
- 🐍 Python-скрипт `format_onegin.py` для автоформатирования исходного текста

---

## ⚙️ Конфигурация

Все основные параметры задаются в файле **`config.h`**:

```c
const char DEFAULT_INPUT_FILE_NAME[]  = "formatted_onegin.txt";
const char DEFAULT_OUTPUT_FILE_NAME[] = "0N3G1N.txt";
const char LOGFILE_NAME[]             = "log.txt";
```

### Поля конфигурации

| Поле | Назначение |
|------|------------|
| `DEFAULT_INPUT_FILE_NAME`  | Имя файла с исходным текстом |
| `DEFAULT_OUTPUT_FILE_NAME` | Имя файла для результата |
| `LOGFILE_NAME`             | Имя файла логов |
| `DISABLE_LOGS`             | Дефайн для полного отключения логирования |

### 🔕 Отключение логов

Чтобы полностью отключить запись логов, раскомментируйте (или добавьте) в `config.h`:

```c
#define DISABLE_LOGS
```

После этого программа не будет создавать и записывать в `log.txt`.

---

## 🐍 Подготовка текста: `format_onegin.py`

В проекте присутствует Python-скрипт `format_onegin.py`, который автоматически приводит переданный текст к «чистому» виду:

```bash
python3 format_onegin.py
```

---

## 🔨 Сборка

Для сборки проекта используйте скрипт `build.sh`:

```bash
chmod +x build.sh
./build.sh
```

---

## 🚀 Запуск

```bash
./onegin
```

Программа автоматически:

1. Откроет файл `formatted_onegin.txt`;
2. Прочитает его содержимое;
3. Отсортирует строки двумя способами;
4. Запишет результат в `0N3G1N.txt`;
5. При необходимости сохранит лог в `log.txt`.

---

## 🎛 Параметры командной строки

Помимо значений по умолчанию, заданных в `config.h`, имена входного и выходного файлов можно переопределить прямо при запуске программы с помощью параметров командной строки:

| Параметр | Назначение |
|----------|------------|
| `--input <путь>`  | Задаёт имя (путь) файла с исходным текстом |
| `--output <путь>` | Задаёт имя (путь) файла для записи результата |

### Примеры использования

Запуск со значениями по умолчанию:

```bash
./onegin
```

Запуск с указанием собственного входного файла:

```bash
./onegin --input my_text.txt
```

Запуск с указанием и входного, и выходного файлов:

```bash
./onegin --input my_text.txt --output my_result.txt
```

Порядок параметров `--input` и `--output` не важен. Если какой-либо из параметров не задан, для него используется соответствующее значение по умолчанию:

- `--input` → `DEFAULT_INPUT_FILE_NAME` (`formatted_onegin.txt`)
- `--output` → `DEFAULT_OUTPUT_FILE_NAME` (`0N3G1N.txt`)

---

## 📄 Формат выходного файла

Пример содержимого файла `0N3G1N.txt`:

```
0N3G1N by mc BAA


Part 1. Sorted
------------------------

and glumly serves the medicine bottle,
and never played a shrewder trick.
and never stir a foot away!
and sighs, and asks oneself all through:
And the sly baseness, fit to throttle,
But God, how deadly dull to sample
but when past joking he fell sick,
he really forced one to admire him --
Let others learn from his example!
My uncle - high ideals inspire him;
of entertaining the half-dead:
one smoothes the pillows down in bed,
sickroom attendance night and day
"When will the devil come for you?"


Part 2. mc Pushkaas
------------------------

of entertaining the half-dead:
one smoothes the pillows down in bed,
But God, how deadly dull to sample
Let others learn from his example!
and glumly serves the medicine bottle,
And the sly baseness, fit to throttle,
and sighs, and asks oneself all through:
and never played a shrewder trick.
but when past joking he fell sick,
he really forced one to admire him --
My uncle - high ideals inspire him;
"When will the devil come for you?"
sickroom attendance night and day
and never stir a foot away!


Part 3. A. S. Pushkin "Eugene Onegin"
------------------------

My uncle - high ideals inspire him;
but when past joking he fell sick,
he really forced one to admire him --
and never played a shrewder trick.
Let others learn from his example!
But God, how deadly dull to sample
sickroom attendance night and day
and never stir a foot away!
And the sly baseness, fit to throttle,
of entertaining the half-dead:
one smoothes the pillows down in bed,
and glumly serves the medicine bottle,
and sighs, and asks oneself all through:
"When will the devil come for you?"


Onegin vse!
Vot i ckazochki konez, a kto slushal - molodez!
```

При сортировке **регистр и не-буквенные символы игнорируются**: сравниваются только буквы латинского алфавита.

---


### Используемые алгоритмы

| Алгоритм | Где применяется |
|----------|-----------------|
| **Bubble Sort** | Сортировка строк с начала (ручная реализация) |
| **qsort (lib)** | Сортировка строк с конца (стандартная библиотека) |

---

## 🛠 Требования

- Компилятор C clang++
- Bash
- Python 3 (для `format_onegin.py`)

---

## 📞 Контакты

**Автор:** [@mathusha2023](https://t.me/mathusha2023)  
**Github:** [ссылка](https://github.com/mathusha2023)  
**Telegram:** [ссылка](https://t.me/mathusha2023)  
**VK:** [ссылка](https://vk.ru/mathusha2023)