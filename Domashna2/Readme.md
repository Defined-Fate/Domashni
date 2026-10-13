# Heapsort

Heapsort е алгоритам кој сортира низи со претварање на низата во heap. Потоа тој heap го претвараме во max-heap во кој секое бинарно дрво родителот ќе е најголем. Го одстарнуваме главниот родител и го менуваме со најмалото дете т.е го ставаме родителот на крајот на низата, правиме heapify (правиме пак max-heap) и повотруваме додека се не е сортирано.

## Комплексност
Прво комплексноста на функцијата heapify ќе биде $O(\log_2 n)$. Висината на heap е $h = \lfloor \log_2 n \rfloor$ и дека рекурзијата само оди до h на дадениот heap таа не надминува $\log_2 n$, сега нека $T(h)$ е времето на рекурзијата $$T(h) = T(h-1) + c, \ T(0) = c$$ од ова следува $T(h) = c \cdot (h+1) = O(h)$ каде што $h = \log_2 n$. Најдобар случај на функцијата е $\Omega(1)$ ако бараниот елемент е веќе најголемиот, а најлош $O(\log_2 n)$ ако елементот е најдоле во дрвото.

Сега комплексноста на heapsort. Прво имаме градење на max-heap со:
```c++
for(int i = n/2 - 1; i >= 0; i--)
    heapify(vec, n , i)
```
Со ова добиваме $$T_{build}(n) = \sum_{h=0}^{\lfloor \log_2 n \rfloor} \left\lceil \frac{n}{2^{h+1}} \right\rceil \cdot O(h)$$ кое се развожува во $$O\\left(n \sum_{h=0}^{\infty} \frac{h}{2^h}\right)$$ бидејки серијава конвергира на 2 слдеува дека е $O(n)$.

За вториот дел го разгледуваме for лоопот
```c++
for(int i = n - 1; i > 0; i--){
    std::swap(vec[0], vec[i]);   // O(1)
    num++;                        // O(1)
    heapify(vec, i, 0);           // O(log i)
}
```
Така да се гледа дека комплексноста ќе биде $O(n \ \log \ n)$.

И сега збирот нивен $T(n) = O(n) + O(n \ \log \ n) = O(n \ \log \ n)$.

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
