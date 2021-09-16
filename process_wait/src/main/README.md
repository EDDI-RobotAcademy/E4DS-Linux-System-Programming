# signal prototype

```c
include <stdio.h>

void (* sigtest(int signo, void (*p)(int))) (int);
// void (*)(int)   sigtest   (int signo, void (*p)(int))
```
