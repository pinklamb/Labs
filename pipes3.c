#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pattern>\n", argv[0]);
        return 1;
    }

    FILE *pipe = popen("cat scores | grep -e '" "' | sort", "r");

    if (!pipe) {
      perror("popen");
      return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), pipe) != NULL) {
      printf("%s", line);
    }

    if (pclose(pipe) == -1) {
      perror("pclose");
      return 1;
    }

    return 0;
}
