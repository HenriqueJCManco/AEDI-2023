#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n-- != 0){

        char str1[51], str2[52], res[101];
        scanf("%s %s", str1, str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        int i,j,k;
        for( i= 0, j = 0, k=0; i < len1 && j < len2 ; i++, j++ , k+= 2){
            res[k] = str1[i];
            res[k +1] = str2[j];
        }
        while (i < len1){
            res[k++] = str1[i++];
        }
        while (j < len2){
            res[k++] = str2[j++];
        }
        res[k] = '\0';
        printf("%s\n", res);
    }
        return 0;
    }