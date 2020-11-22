#include <stdio.h> 
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


//float numbers(float lettercount, float word);
//float numberss(float sentence, float word);

int main (void)
{
    float lettercount=0;
    float word=0;
    float sentence=0; 
    float L;
    float S;
  
    // Prompt the User ("Text: ") using string command 
    string text = get_string("Text: ");
    
    // n = strlen(text) changes the text into numbers so n = a number value 
    // text[i] makes i go through each letter text starting with text[0]
    // text[0] in "hi my name" text would be "h"
    // everytime the if statement is fulfilled, a lettercount is added 
    // the prompt states a word is indicated by a space
    // punctation is self-explanatory 
    for (int i=0, n = strlen(text); i<n; i++)
    {
        if ( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') )
        {
            lettercount++;
        }
        if (text[i] == ' ')
        {
            word++;
        }
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
       
    }
    
    word++;
// // float numbers(float lettercount, float word);
//     {
//          L=((lettercount/word)*100);
//         return L;
//     }
// // float numberss(float sentence, float word);
//     {
//          S=(sentence/(word)*100);
//         return S;
//     }
    L=((lettercount/(word))*100);
    S=((sentence/(word))*100);
    int index = round( (0.0588 * L) - (0.296 * S) - 15.8 );
    
    if (index<0)
    { 
        printf("Before Grade 1\n");
    }
    if (index>16)
    {
        printf("Grade 16+\n");
    }
    if (index > 0 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    
   // Displays the value of lettercount %i is used because lettercount's data type is int 
   // Add +1 to word because there's no spaces when typing the first word of a sentence
    // printf("%f letter(s)\n%f word(s)\n%f sentence(s)\n %f\n %f\n", lettercount, word, sentence, L, S);
}