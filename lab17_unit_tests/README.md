Компиляция и запукс программы, unit-тестов 
```
gcc -o main main.c math.c
./main
gcc -o tests tests.c math.c -lcmocka
./tests
```
