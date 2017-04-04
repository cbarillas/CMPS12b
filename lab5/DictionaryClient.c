/*
 * Carlos Barillas, cbarilla@ucsc.edu
 * CMPS12B - lab5 - 11/11/2016
 *
 * DictionaryClient.c
 * Test client for the Dictionary ADT
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

#define MAX_LEN 180

  int main(int argc, char* argv[]){
    Dictionary A = newDictionary();
    char* k;
    char* v;
    char* arr1[] = {"one","two","three","four","five","six","seven"};
    char* arr2[] = {"foo","bar","blah","galumph","happy","sad","blue"};
    int i;

    for(i=0; i<7; i++){
      insert(A, arr1[i], arr2[i]);
    }

    printDictionary(stdout, A);

    for(i=0; i<7; i++){
      k = arr1[i];
      v = lookup(A, k);
      printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
    }

    // insert(A, "five", "glow"); // error: key collision

    delete(A, "one");
    delete(A, "three");
    delete(A, "seven");

    printDictionary(stdout, A);

    for(i=0; i<7; i++){
      k = arr1[i];
      v = lookup(A, k);
      printf("key=\"%s\" %s\"%s\"\n", k, (v==NULL?"not found ":"value="), v);
    }

    // delete(A, "one");  // error: key not found

    printf("%s\n", (isEmpty(A)?"true":"false"));
    printf("%d\n", size(A));
    makeEmpty(A);
    printf("%s\n", (isEmpty(A)?"true":"false"));

    freeDictionary(&A);

    return(EXIT_SUCCESS);
  }
