#include <stdio.h>
#include <fcntl.h>

int main(){
    int file;
    char buf[1024];
    file = open("file.txt",O_CREAT | O_WRONLY, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWOTH | S_IWGRP);
    int n = read(0,buf,1024);
    write(file,buf,n);
    close(file);
    file = open("file.txt",O_RDONLY);
    n = read(file,buf,1024);
    write(1,buf,n);
    close(file);
    return 0;
}