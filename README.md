<p align="right">
  <i>«...Но скоро кодинг будет нейрослопом<br>А люди будут железный йух сосать...»</i><br>
  <b>А. С. Пушкин, «Евгений Онегин»</b>
</p>

# Onegin Sorter

> Программа, читающая текст из заданного файла, сортирующая его строки тремя способами и 
записывающая результат в выходной файл

---

## Примерный цикл работы
1) Считываем текст из файла в единый буфер
2) Заводим массив структур String, каждая из которых указывает на новую строку буфера (раздел по \n)
3) Сортируем массив 2-мя способами (разные функции сортировки + разные компораторы)
4) Записываем в выходной файл 3 разных версии «Евгения Онегина»:
   * Sorted - сортировка строк по алфавиту (учитываются только буквы)
   * mc Pushka - сортировка строк по алфавиту справа налево (учитываются только буквы)
   * дефолтный Евген, такой же, как и в исходном файле

Пример содержимого выходного файла:

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

---

## Крутые фичи (мне нравится == крутая)
* Возможность самому задать имя входного и выходного файла (параметры --input <filename> и --output <filename> командной строки), парсинг БЕЗ getopt

* Полное логирование всех этапов выполнения программы с возможностью указать файл для логирования через config.h, а также возможностью отключения логов (расскомментить флаг DISABLE_LOGS в конфиге)

* Наличие скрипта на сладеньком питончике format_onegin.py для нормального форматирования файла, который был скачан с какого то сайта на просторах необьятного интернета

* При записи оригинала текста в выходной файл (п. 3) не простой дамп буфера, а сортировка массива String по...адресам текстовой части каждой строки в памяти (т.е. по указателям без разыменования, это НЕ БАГ)

* Красивый код (красивый же?)

* Наличие нейрослопного ридмишника, который конечно же очень красивый и подробный, но все же написан бездушной железякой. Впрочем, если есть желание почитать, то [купите святую воду после прочтения](./NEURONKIXYNAAAAA.md) ПРОЕКТ СОЗДАН В УЧЕБНЫХ ЦЕЛЯХ И ПОТОМУ ИСПОЛЬЗОВАНИЕ НЕЙРОСЕТЕЙ БЫЛО СВЕДЕНО К НУЛЮ, ДАЖЕ В ТАКИХ ТРЕВИАЛЬНЫХ ЗАДАЧАХ

---

## Связь

Я всегда рад отзывам, предложениям, общению и денюжке. Свяжитесь со мной, если хотите предложить мне один из этих пунктов: [таппп](https://t.me/mathusha2023)  
