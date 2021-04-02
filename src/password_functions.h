/*----------------------------Funciones Prototipo-----------------------------*/
int CHECK(char [], char []);
void HIDE(char []);
/******************************************************************************/
int ENTER()
{    
       char contra[10], usuario[15], *CPASS;
       int tries = 4, RESP = 0;
       regresar: system("cls");
       TOP();
       cout<<"\t\tIngrese nombre de usuario: ";
       gets(usuario);
       fflush(stdin);
       cout<<"\n\n\t\tIngrese contrase\244a: ";
   	   HIDE(contra);
   	   BELOW();
       RESP = CHECK(usuario, contra);
   	   if(RESP == 1)
   	       return 1;
       else
       {
          cout<<"Te queadan: "<<--tries<<" intentos\n";
          getch(); 
          system("cls");
          if (tries > 0) goto regresar;
       }
}
/******************************************************************************/
int CHECK(char usua[], char contr[])
{
     char  PASS[10], USER[13];
     int aux = 0;
     
     FILE *archivo;
     archivo = fopen("USERS.txt", "r+");
     
     if(archivo != NULL)
     {
                while(!feof(archivo))
                {
                    fscanf(archivo, "%s %s", USER, PASS);
                    if(strcmp(usua, USER) == 0 && strcmp(contr, PASS) == 0)
                    {
                        aux = 1;
                        return 1;
                        break;
                    }
                }     
                if(aux == 0)
                {
                       cout<<"\n\nContrase\244a y/o Usuario incorrecto(s)\n"<<endl;
                }
                fclose(archivo);
     }
     else
     {
      	printf("\n\nArchivo no encontrado");
     }
}
/******************************************************************************/
void HIDE(char cadena[])
{
    int i = 0;
    fflush(stdout);
    do
    {
        cadena[i] = (unsigned char)getch();
        if(cadena[i] != 8)
        {
            cout << '*'; 
            i++;
        }
        else if(i > 0) 
        {
            cout << (char)8 << (char)32 << (char)8;
            i--; 
        }
        fflush(stdout);

    }while(cadena[i - 1] != 13);  
    cadena[i - 1] = 0;
}
