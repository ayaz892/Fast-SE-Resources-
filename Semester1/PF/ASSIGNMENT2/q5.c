#include <stdio.h>
#include <string.h>

int main() {

    char str[101];
    scanf("%s", str);
    int i, length;
    int count=0;
    
    
    length = strlen(str);
    
    for(i=0;i < length ;i++){
        if(str[i] != str[length-i-1]){
            count= 1;
            break;
   }
}
    
    if (count){
        printf("1");
    }    
    else {
        printf("ALREADY");
    }
 
    

   
    
    return 0;
}
