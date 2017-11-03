#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main () {

  DIR * d = opendir(".");
  struct dirent * direct = readdir(d);
  int size = 0;

  printf("Listing all files in directory:\n");
  while (direct) {
    if (direct -> d_type == DT_DIR) {
      printf("DIR: ");
    } else {
      printf("REG: ");
    }
    struct stat temp;
    stat(direct -> d_name, &temp);
    size += temp.st_size;
    printf("%s | %d\n", direct -> d_name, temp.st_size);
    direct = readdir(d);
  }
  printf("Total Size: %d\n", size);
  closedir(d);
  return 0;
  
}
