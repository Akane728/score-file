#include <stdio.h>
#include <stdlib.h>
FILE *infile;
FILE *fp;
int main (void) 
{
	int found = 0;
	char word[50], target[50];
	int score = 0;
	while(1)
	{
		if ((infile = fopen("word.txt","r")) ==  NULL)
		{
			printf("File empty!");
			break;
		}
		else
		{
			found = 0;
			printf("\nEnter word to search: ");
			fflush(stdin);
			gets(target);
			
			while ( found == 0 && !feof(infile))
			{
				if ( word[strlen(word) -1] == '\n')
					word[strlen(word) -1] = 0;
				fscanf(infile, "%s", word);
				if(strcmp(target, word) == 0)
					found = 1;
			}
		
			if (found == 1)
			{
				
				printf("\nThe found word is : %s", word);
				score++;
		
				printf("\nThe score is added!");		
			}
			else
			{
				printf("Sorry not found!!!\n");
				break;
			}
		}
			fclose(infile);
	
	}
	
	if( (fp=fopen("score.txt","a")) == NULL)
	{
		fprintf(stderr, "Error opening file");
		exit(1);
	}
		fprintf(fp, "\n%d", score);
		fclose(fp);	
		
		printf("The score is %d", score);
	
}
