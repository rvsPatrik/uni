#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


void seperator(){
    printf("\n- - - - - - - - - -\n");
}


void showVersion(){

    seperator();
    
    printf("\nA program verzioszama: alpha v0.1\n");
    printf("A program elkeszulesenek datuma: 2024.02.29");
    pritnf("A program fejlesztojenek neve: Revesz Patrik\n");

    seperator();
}


void showHelp(){

    seperator();
    
    printf("A program uzemmpdjai: \n");
    printf("- A program alapertelmezetten kuldokent viselkedik -\n");
    printf("\n| -send | - A program kuldokent viselkedik.\n");
    printf("| -recieve | - A program fogadokent mukodik.\n");

    seperator();

    printf("\nA kommunikacio modja:\n");
    printf("- A program alapertelmezett kommunikacios modja: fajl -\n");
    printf("| -file | - A program fajt hasznal kommunikaciora.\n");
    printf("| -socket | - A program socketet hasznal a kommunikaciora.\n");

    seperator();
}


int contain(char*halmaz[],char* keresettelem){
    int talalatok = 0;
    for (int i = 0; i < ((int) sizeof(halmaz)); i++)
    {
        if (strcmp(halmaz[i],keresettelem) == 0 ){
            return 0;
        }
    }
    return 1;
}


int main(int argc,char* argv[]){
    
    char* filename = argv[0];
    char* arg = argv[1];
    
    if (strcmp(filename,"./--version")==0){
        showVersion();
        exit(0);
    }
    else if (strcmp(filename,"./help")==0){
        showHelp();
        exit(0);
    }
    
  
    return 0;
}