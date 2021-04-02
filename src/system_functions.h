/*----------------------------Funciones Prototipo-----------------------------*/
int main();
int IDSEARCH(char []);
void SISTEMA();
void MENU(int);
void OPERA(int, int);
void CONSULTAALL(char []);
void CONSULTANOM(char []);
void REGISTROIN(char []);
void REGISTROMO(char [], char [], char []);


/*---------------------------Funciones del Sistema----------------------------*/
void SISTEMA()
{
     int opc;
     while(1)
     {
     fflush(stdin);
     TOP();
     printf("\n%44s\n", "BIENVENIDO");
     printf("\n%46s\n\n", "MENU PRINCIPAL");
     cout<<"\t1 \32 Consulta"<<endl;
     cout<<"\t2 \32 Registro"<<endl;
     cout<<"\t3 \32 Regresar"<<endl;
     cout<<"\t4 \32 Salir";
     BELOW();
     cout<<"\n\tELIGE \32\32\32 ";
     scanf("%d*", &opc);
     fflush(stdin);
     system("cls");
     MENU(opc);
     }
}
/******************************************************************************/
void MENU(int OPC)
{
     int subOPC;
     fflush(stdin);
     switch(OPC)
     {
         case 1:
              while(1)
              { 
                  TOP();    
                  printf("%42s\n\n", "CONSULTA");    
                  cout<<"\t\t1.1 \32 Todos"<<endl;
                  cout<<"\t\t1.2 \32 Por Nombre"<<endl;
                  cout<<"\t\t1.3 \32 Regresar"<<endl;
                  cout<<"\t\t1.4 \32 Salir";
                  BELOW();
                  cout<<"\n\tELIGE \32\32\32 ";
                  scanf("%d", &subOPC);
                  fflush(stdin);
                  OPERA(OPC, subOPC);
              }
		      system("cls");
              break;
         case 2:
              while(1)
              { 
                  TOP();    
                  printf("%42s\n\n", "REGISTRO");      
                  cout<<"\t\t2.1 \32 Ingresar"<<endl;
                  cout<<"\t\t2.2 \32 Modificar"<<endl;
                  cout<<"\t\t2.3 \32 Regresar"<<endl;
                  cout<<"\t\t2.4 \32 Salir";
                  BELOW();
                  cout<<"\n\tELIGE \32\32\32 ";
                  scanf("%d", &subOPC);
                  fflush(stdin);
                  OPERA(OPC, subOPC);
              }
		      system("cls");
              break;
         case 3:
              system("cls");
              main();
              break;
         case 4:
              exit(0);
              break;
         default:
              cout<<"\nOPCION INVALIDA"<<endl;
              getch();
		      system("cls");
              break;
     }
}
/******************************************************************************/
void OPERA(int OPC, int SUBopc)
{
     int ID;
     char first[25], last[25];
     system("cls");
     switch(OPC)
     {
         case 1:
             switch(SUBopc)
             {
                  case 1:
                       CONSULTAALL("DATABASE.txt");
                       getch();
                       system("cls");
                       break;
                  case 2:
                       CONSULTANOM("DATABASE.txt");
                       getch();
                       system("cls");
                       break;
                  case 3:
                       system("cls");
                       SISTEMA();
                       break;
                  case 4:
                       exit(0);
                       break;
                  default:
                       cout<<"\nOPCION INVALIDA"<<endl;
                       getch();
		               system("cls");
                       break;
              }
              system("cls");
              break;
         case 2:
             switch(SUBopc)
             {
                  case 1:
                       REGISTROIN("DATABASE.txt");
                       getch();
                       system("cls");
                       break;
                  case 2:
                       TOP();
                       cout<<"\tIngresa NOMBRE: ";
                       cin>>first;
                       cout<<"\n\n\tIngresa Apellido: ";
                       cin>>last;
                       BELOW();
                       REGISTROMO("DATABASE.txt", first, last);
                       getch();
                       system("cls");
                       break;
                  case 3:
                       system("cls");
                       SISTEMA();
                       break;
                  case 4:
                       exit(0);
                       break;
                  default:
                       cout<<"\n\nOPCION INVALIDA"<<endl;
                       getch();
		               system("cls");
                       break;
              }
              system("cls");
              break;
         default:
              cout<<"\n\nOPCION INVALIDA"<<endl;
              getch();
		      system("cls");
              break;
     }
}
/******************************************************************************/
int IDSEARCH(char path[])
{
    int ID, PRES, FD = 0;
    char FIRST[20], LAST[20], SO[20], STE[20], ISSUE[20];
	FILE *archivo;
	
    system("cls");
    
	archivo = fopen(path, "r");
	if(archivo != NULL)
	{
		while(!feof(archivo))
		{
			fscanf(archivo, "%d %s %s %s %s %s %d", &ID, FIRST, LAST, STE, SO, ISSUE, &PRES);
			FD++;
		}
		return FD;
		fclose(archivo);
	}
	else
	{
		printf("\n\nArchivo no encontrado");
	}
}
/******************************************************************************/
void CONSULTAALL(char path[])
{  
    int ID, PRES;
    char FIRST[20], LAST[20], SO[20], STE[20], ISSUE[20];
	FILE *archivo;
	
    system("cls");
    
	archivo = fopen(path, "r");
	if(archivo != NULL)
	{
        printf("\n %-3s %-10s %-10s %-10s %-18s %-10s %-12s\n\n", "ID", "Nombre", "Apellido", "Estado", "Sistema Operativo", "Problema", "Presupuesto");
        printf("--------------------------------------------------------------------------------\n");
		while(!feof(archivo))
		{
			fscanf(archivo, "%d %s %s %s %s %s %d", &ID, FIRST, LAST, STE, SO, ISSUE, &PRES);
			printf(" %-3d %-10s %-10s %-15s %-13s %-10s     $%2d.0\n\n", ID, FIRST, LAST, STE, SO, ISSUE, PRES);
		}
		fclose(archivo);
	}
	else
	{
		printf("\n\nArchivo no encontrado");
	}	
}
/******************************************************************************/
void CONSULTANOM(char path[])
{
     
     char buscar_F[25], buscar_L[25], FIRST[20], LAST[20], SO[20], STE[20], ISSUE[20];
     int ID, PRES;
     int aux = 0;
     
     FILE *archivo;
     archivo = fopen(path, "r+");
     
     if(archivo != NULL)
     {
                TOP();
                cout<<"\tTeclea el nombre: ";
                cin>>buscar_F;
                cout<<"\n\n\tTeclea el apellido: ";
                cin>>buscar_L;
                BELOW();
                
                while(!feof(archivo))
                {
                    fscanf(archivo, "%d %s %s %s %s %s %d", &ID, FIRST, LAST, STE, SO, ISSUE, &PRES);
                    if(strcmp(buscar_F, FIRST) == 0 && strcmp(buscar_L, LAST) == 0)
                    {
                        aux = 1;
                        printf("\n\nCliente encontrado\n\n");
                        printf("\n %-3s %-10s %-10s %-10s %-18s %-10s %-12s\n\n", "ID", "Nombre", "Apellido", "Estado", "Sistema Operativo", "Problema", "Presupuesto");
                        printf("--------------------------------------------------------------------------------\n");
                        printf(" %-3d %-10s %-10s %-15s %-13s %-10s     $%2d.0\n\n", ID, FIRST, LAST, STE, SO, ISSUE, PRES);
                        break;
                    }
                }
                if(aux == 0)
                {
                       printf("\n\nCliente no encontrado");
                }
                fclose(archivo);
     }
     else
     {
      	printf("\nArchivo no encontrado");
     }    
}
/******************************************************************************/
void REGISTROIN(char path[])
{
     char FIRST[20], LAST[20], SO[20], STE[3][20] = {"Reparando", "Reparado", "Entregado"}, ISSUE[20];
     int ID, PRES, edo;
     
     FILE *archivo;
     
     archivo = fopen(path, "a");
     ID = IDSEARCH(path);
     if(archivo != NULL)
     {
         ID++;
         TOP();
         cout<<"\n\tTeclea NOMBRE: "; 
         scanf("%10s", FIRST); fflush(stdin);
         cout<<"\n\n\tTeclea APELLIDO: "; 
         scanf("%10s", LAST); fflush(stdin);
         cout<<"\n\n\tElige ESTADO\n\n\t\t1. Reparando\t2. Reparado\t3. Entregado\n\t\32\32 ";
         cin>>edo; fflush(stdin);
         cout<<"\n\n\tTeclea SISTEMA OPERATIVO: "; 
         scanf("%10s", SO); fflush(stdin);
         cout<<"\n\n\tTeclea PROBLEMA: "; 
         scanf("%10s", ISSUE); fflush(stdin);
         cout<<"\n\n\tTeclea PRESUPUESTO: "; 
         cin>>PRES; fflush(stdin);
         fprintf(archivo, "\n%d   %s   %s	   %s    %s	 %s   %d", ID, FIRST, LAST, STE[edo - 1], SO, ISSUE, PRES);
         printf("\n\n\t\tCliente registrado");
         BELOW();
         fclose(archivo);
     }
     else
     {
         cout<<"\n\nArchivo no encontrado";
     }
}
/******************************************************************************/
void REGISTROMO(char path[], char first_c[], char last_c[])
{
     char FIRST[100][25], LAST[100][25], STE[100][25], SO[100][25], ISSUE[100][25], f[25], l[25], ste_[25], so_[25], issue_[25];
     char STE_AUX[3][25]  = {"Reparando", "Reparado", "Entregado"};
     FILE *archivo;
     int cont = 0, aux = 0, i, ID[100], PRES[100], id_, p, edo;
	
	 archivo = fopen(path, "r");
	 
	 if(archivo != NULL)
	 {
        while(!feof(archivo))
		{
			fscanf(archivo, "%d %s %s %s %s %s %d", &id_, f, l, ste_, so_, issue_, &p);
			ID[cont] = id_;
			strcpy(FIRST[cont], f);
			strcpy(LAST[cont], l);
			strcpy(STE[cont], ste_);
			strcpy(SO[cont], so_);
			strcpy(ISSUE[cont], issue_);
			PRES[cont] = p;
			cont++;
		}
		for(i = 0; i < cont; i++)
		{
			if(strcmp(first_c, FIRST[i]) == 0 && strcmp(last_c, LAST[i]) == 0)
			{
				cout<<"\n\n\tElige ESTADO\n\n\t\t1. Reparando\t2. Reparado\t3. Entregado\n\t\t\32\32 "; 
                cin>>edo; fflush(stdin);
                strcpy(STE[i], STE_AUX[edo - 1]);
				aux = 1;
				break;
			}
		}
		archivo = fopen(path, "w+");
		for(i = 0; i < cont; i++)
		{
            if(i < cont - 1)  
			    fprintf(archivo, "%d %s %s %s %s %s %d\n", ID[i], FIRST[i], LAST[i], STE[i], SO[i], ISSUE[i], PRES[i]);
            else 
                fprintf(archivo, "%d %s %s %s %s %s %d", ID[i], FIRST[i], LAST[i], STE[i], SO[i], ISSUE[i], PRES[i]);
		}
		if(aux == 1)
		{
			printf("\n\n\t\tDatos modifcados");
		}
		if(aux == 0)
		{
			printf("\n\nRegistro no encontrado");
		}
		fclose(archivo);
     }
     else
	 {
	 	printf("\n\nArchivo no encontrado");
	 }
}
