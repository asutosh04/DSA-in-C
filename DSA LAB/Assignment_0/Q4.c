#include <stdio.h>
void LemmWord(char input1[20], char input2[20], char input3[20]){
    int i=0;
    printf("The same word is: ");
    while(input1[i]!='\0'&&input2[i]!='\0'&&input3[i]!='\0'){
        if(input1[i]==input2[i]&&input1[i]==input3[i]){
            printf("%c",input1[i]);
        }
        i++;
    }
}

int main()
{
    char word1[20], word2[20], word3[20];
    for(int i=0;i<3;i++)
    {
    printf("Enter the %d word : ",i+1);
    if(i==0)
      scanf("%s", word1);
    else if(i==1)
      scanf("%s", word2);
    else if(i==2)
      scanf("%s", word3);    
    }
    LemmWord(word1,word2,word3);
}