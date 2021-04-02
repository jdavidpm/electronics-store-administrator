#define N 26
char ***MTX = NULL;

void FILLOR()
{
	char TEMP, AUX, LM, TM[N][N];
	int n = 0;
	//Llenado
	for(int i = 0; i < N; i++)
	{
        LM = (char)97;
		for(int j = 0; j < N; j++)
	    {
		   TM[i][j] = LM++;
     	}
	}
	
	//Ordenacion
	for(int i = 0; i < N; i++)
	{
		TEMP = TM[i][0];
		for(int j = 0; j < N; j++)
	    {
	    	AUX = TM[i][j + 1];
	    	TM[i + 1][j] = AUX;
	    	if(j == N - 1)
	    	    TM[i + 1][j] = TEMP;
	    	
     	}
	}
	for(int k = 0; k < 2; k++)
	{
        for(int j = 0; j < N; j++)
        {
            for(int i = 0; i < N; i++)
            {
                MTX[k][j][i] = TM[j][i] - n;      
            }
        }
        n = 32;
    }
    
}


void SHOWUP()
{
    for(int k = 0; k < 2; k++)
	{
        for(int j = 0; j < N; j++)
	    {
		    for(int i = 0; i < N; i++)
    	    {
	    	   printf("%c ", MTX[k][j][i]);
     	    }
    		printf("\n");
	    }
	    printf("\n\n");
    }
}
char * CIPHER(char txt[])
{
     char *ptxt;
     int n, cont;
     for(int i = 0; i < strlen(txt); i++)
     {
             
          cont = 0;
          if(txt[i] >= 65 && txt[i] <= 90 || txt[i] >= 97 &&txt[i] <= 122)
          {
              if (txt[i] < 97)
                  n = 1;
              else
                  n = 0;   
              while(txt[i] != MTX[n][i][cont])
                 cont++;
              txt[i] = MTX[n][i + 1][cont]; 
          }
          else continue;
     }
     ptxt = txt;
     return ptxt;
}

char * DIPHER(char txt[])
{
     char *ptxt;
     int cont, aux = -1, n;
     
     for(int i = strlen(txt); i > 0; i--)
     {
             
            
          aux++;
          cont = 0;
          if(txt[aux] >= 65 && txt[aux] <= 90 || txt[aux] >= 97 && txt[aux] <= 122)
          {
              if (txt[aux] < 97)
                  n = 1;
              else
                  n = 0;
              while(txt[aux] != MTX[n][i][cont])
                 cont++;
              txt[aux] = MTX[n][i - 1][cont]; 
          }
          else continue;
     }
     ptxt = txt;
     return ptxt;
}

int CREATE(char ****pm)
{
     char ***ptm;
     ptm = (char ***)malloc(2 * sizeof(char **));
     if(ptm == NULL)
         return -1;
     else
     {
         for(int i = 0; i < 2; i++)
         { 
             (ptm)[i] = (char **)malloc(N * sizeof(char *));
             if(ptm[i] == NULL)
                return -1;
         }
         for(int i = 0; i < 2; i++)
         {   for(int j = 0; j < N; j++)
             {
                (ptm)[i][j] = (char *)malloc(N * sizeof(char ));
                if(ptm[i][j] == NULL)
                   return -1;
             } 
         }
     }
     *pm = ptm;
}
void FREEM ()
{
    for(int i = 0; i < 2; i++)
	{
        for(int j = 0; j < N; j++)
          free(MTX[i][j]);
    }
    free(MTX);
}
