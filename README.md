# pipex

Учебный проект школы 21. 
Симуляция оператора pipe "|" на языке С. 

Для запуска:
1) скомпилировать командой make
2) запустить

пример запуска \
```$> ./pipex infile "ls -l" "wc -l" outfile ``` \
```$> ./pipex infile "grep a1" "wc -w" outfile```\

Программа должна в точности повторять поведение этих команд в командной строке соответственно\
```$>< infile ls -l | wc -l > outfile```\
```$>< infile grep a1 | wc -w > outfile```
 
  Больше информации о задании в [en.subject.pdf](https://github.com/RekaEva/pipex/blob/main/en.subject.pdf)
