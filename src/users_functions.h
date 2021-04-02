/*----------------------------Funciones Prototipo-----------------------------*/

void USUARIOS();
void NEWUSER(char []);
void ERAUSER(char [], char [], char []);
void MODUSER(char [], char [], char []);



/*-------------------------Funciones para el Usuario--------------------------*/
void USUARIOS()
{

     while(1)
     {
         char USUARIO[15], CONTRA[10], *CPASS;
         int RESP, CH;
         fflush(stdout);
         fflush(stdin);
         system("cls");
         fflush(stdin);
         TOP();
         cout<<"\t\t\t\t\250Qu\202 desea hacer?\n\n\n";
         cout<<"\t1 \32 Nuevo Usuario"<<endl;
         cout<<"\t2 \32 Borrar Usuario"<<endl;
         cout<<"\t3 \32 Modificar Contrase\244a"<<endl;
         cout<<"\t4 \32 Regresar"<<endl;
         cout<<"\t5 \32 Salir";
         BELOW();
         cout<<"\n\n\tELIGE \32\32\32 ";
         scanf("%d", &CH);
         fflush(stdin);
         fflush(stdin);
         system("cls"); 
         switch(CH)
         {    
              case 1:
                   NEWUSER("USERS.txt");
                   system("cls");
                   USUARIOS();
                    break;
              case 2:
                   TOP();
                   cout<<"\t\t\t\tBORRAR USUARIO\n";
                   cout<<"\n\n\tUsuario: ";
                   cin>>USUARIO;
                   cout<<"\n\n\tContrase\244a: ";
                   HIDE(CONTRA);
                   BELOW();
                   ERAUSER("USERS.txt", USUARIO, CONTRA); 
                   system("cls");
                   USUARIOS();
                    break;
              case 3:
                   TOP();
                   cout<<"\t\t\t\tMODIFICAR CONTRASE\245A\n";
                   cout<<"\n\n\tUsuario: ";
                   cin>>USUARIO;
                   cout<<"\n\n\tContrase\244a: ";
                   HIDE(CONTRA);
                   MODUSER("USERS.txt" , USUARIO, CONTRA);
                   system("cls");
                   USUARIOS();
                    break;
              case 4:
                   main();
                   break;
              case 5:
                   exit(0);
                    break;
             default:
                   cout<<"\n\n\t\tOPCION INVALIDA"<<endl;
                   getch();
                   system("cls");
                     break;
         }
     }
}
/******************************************************************************/
void NEWUSER(char path[])
{
     char USER[15], PASS[10], *CPASS;
     
     FILE *archivo;
     
     archivo = fopen(path, "a");
     if(archivo != NULL)
     {
         system("cls");
         TOP();
         cout<<"\t\t\t\tNUEVO USUARIO\n\n";
         cout<<"\t\tUsuario [15 caracteres MAX]\n\t\tContrase\244a[10 caracteres MAX]"<<endl;   
         cout<<"\n\n\tNombre de Usuario: "; 
         cin>>USER;
         cout<<"\n\n\tContrase\244a: "; 
         HIDE(PASS);
         BELOW();
         if(strlen(PASS) > 10 || strlen(USER) > 15)
         {    
             cout<<"\n\nUsuario no registrado"; 
             goto no;
         }
         fprintf(archivo, "\n%s %s", USER, PASS);
         cout<<"\n\n\t\tUsuario registrado";
         no:
         getche(); 
         fclose(archivo);
     }
     else
     {
         cout<<"\n\n\t\tArchivo no encontrado";
     }
     
}
/******************************************************************************/
void ERAUSER(char path[], char user[], char pass[])
{
     char USUARIO[15], CONTRA[10], USUARIO_aux[10][15], CONTRA_aux[10][10];
     FILE *archivo;
     int cont = 0, aux = 0, i, eco = -1;
	
	 archivo = fopen(path, "r");
	 
	 if(archivo != NULL)
	 {
        while(!feof(archivo))
		{
			fscanf(archivo, "%s %s", USUARIO, CONTRA);
			strcpy(USUARIO_aux[cont], USUARIO);
			strcpy(CONTRA_aux[cont], CONTRA);
			cont++;
		}
		for(i = 0; i < cont; i++)
		{
			if(strcmp(user, USUARIO_aux[i]) == 0 && strcmp(pass, CONTRA_aux[i]) == 0)
			{
				eco = i;
				aux = 1;
				break;
			}
		}
		archivo = fopen(path, "w+");
		for(i = 0; i < cont; i++)
		{
            if(i == eco) continue;  
            if(i < cont - 1)  
               fprintf(archivo, "%s %s\n", USUARIO_aux[i], CONTRA_aux[i]);    
            else
               fprintf(archivo, "%s %s", USUARIO_aux[i], CONTRA_aux[i]);
            
		}
		if(aux == 1)
		{
			printf("\n\n\t\tUsuario borrado");
			getch();
		}
		if(aux == 0)
		{
			printf("\n\n\t\tUsuario no encontrado");
			getch();
		}
	    fclose(archivo);
     }
     else
	 {
	 	printf("\n\n\t\tArchivo no encontrado");
	 }
}
/******************************************************************************/
void MODUSER(char path[], char user[], char pass[])
{
     char USUARIO[15], CONTRA[10], USUARIO_aux[10][15], CONTRA_aux[10][10], *CPASS;
     FILE *archivo;
     int cont = 0, aux = 0, i, eco = -1, temp = 0;
	
	 archivo = fopen(path, "r");
	 
	 if(archivo != NULL)
	 {
        while(!feof(archivo))
		{
			fscanf(archivo, "%s %s", USUARIO, CONTRA);
			strcpy(USUARIO_aux[cont], USUARIO);
			strcpy(CONTRA_aux[cont], CONTRA);
			cont++;
		}
		for(i = 0; i < cont; i++)
		{
			if(strcmp(user, USUARIO_aux[i]) == 0 && strcmp(pass, CONTRA_aux[i]) == 0)
			{
                cout<<"\n\n\tIngresa nueva contrase\244a: ";
                HIDE(CONTRA_aux[i]);
                temp = i;
				aux = 1;
				break;
			}
			else
			goto no;
		}
		archivo = fopen(path, "w+");
		for(i = 0; i < cont; i++)
		{
            if(i < cont - 1)  
			    fprintf(archivo, "%s %s\n", USUARIO_aux[i], CONTRA_aux[i]);    
            if(i == cont - 1)
                fprintf(archivo, "%s %s", USUARIO_aux[i], CONTRA_aux[i]);  
            
		}
		if(aux == 1)
		{
			printf("\n\n\t\tContrase\244a modificada");
			getch();
		}
		no:
		if(aux == 0)
		{
            printf("\n\n\t\tUsuario no encontrado/Contrase\244a incorrecta");
            getch();
		}
	    fclose(archivo);
     }
     else
	 {
	 	printf("\n\n\t\tArchivo no encontrado");
	 }
}
/*-------------------------Funciones para el Cifrado--------------------------*/

