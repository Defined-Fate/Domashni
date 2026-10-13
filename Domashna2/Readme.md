# Heapsort

Heapsort е функција која сортира низи со претварање на низата во heap. потоа тој heap го претвараме во max-heap во кој секое бинарно дрво родителот ќе е најголем. Го одстарнуваме главниот родител и го менуваме со најмалото дете т.е го ставаме родителот на крајот на низата, и ја правиме heapify (правиме пак max-heap) и повотруваме додека се не е сортирано.

## Комплексност
Прво комплексноста на функцијата heapify ќе биде $O(\log_2 n)$

## Извершен код за:
100 елементи: Итерации 99, време 2.8e-05 секунди.

10000 елементи: Итерации 9999, време 0.004913 секунди.

1е6 елементи: Итерации 99999, време 0.7542 секунди.

1е9 елементи: Итерации 999999999, време 2505.3 секунди.

## Лаптоп спецификации:
```bash
    OS           ->   Fedora Linux 44 (Workstation Edition) x86_64
    Machine      ->   Vostro 15 5510
    Kernel       ->   Linux 7.2.8-200.fc44.x86_64
    WM           ->   Mutter (Wayland)
    DE           ->   GNOME 50.5
    Shell        ->   fish 4.6.0
    CPU          ->   11th Gen Intel(R) Core(TM) i7-11370H (8) @ 4.80 GHz
    GPU          ->   NVIDIA GeForce MX450 [Discrete]
    GPU          ->   Intel Iris Xe Graphics @ 1.35 GHz [Integrated]
    Memory       ->   7.62 GiB / 15.35 GiB
```

## Running the code

за да го ранаш кодот на LINUX
```bash
g++ heapify.cpp heap_sort.cpp main.cpp -o heap

./heap

```
за windows незнам не користам
```bash
navistina ne znam
```
