#include <stdio.h>

int findLen(char* s) {
  	int l = 0;
    
    while (s[l]) l++;
  
  	return l;
}

int main() {
    char s[] = "Geeks";
    
    printf("%d", findLen(s));
    return 0;
}