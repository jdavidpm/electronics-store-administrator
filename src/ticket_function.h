void TICKET()
{
     
     srand(time(NULL));
     char *DATE, FECHA[25], CNM[20], CAP[20], PMA[10], LI[] = {"---------------------------------"}, buscar_L[20], buscar_F[20], SO[15], STE[20];
     int PCO, NSE, ID, aux = 0;
     NSE = rand() % 10000 + 1000;
     DATE = ADATE();
     strcpy(FECHA, DATE);
     TOP();
     cout<<"\t\tBusque al cliente...\n\n";
     FILE *archivo, *ticket;
     archivo = fopen("DATABASE.txt", "r");
     ticket = fopen("TICKET.txt", "w+");
     if(archivo != NULL)
     {
                cout<<"\tNombre: ";
                cin>>buscar_F;
                cout<<"\n\n\tApellido: ";
                cin>>buscar_L;
                BELOW();
                while(!feof(archivo))
                {
                    fscanf(archivo, "%d %s %s %s %s %s %d", &ID, CNM, CAP, STE, SO, PMA, &PCO);
                    if(strcmp(buscar_F, CNM) == 0 && strcmp(buscar_L, CAP) == 0)
                    {
                        aux = 1;
                        system("cls");
                        TOP();
                        printf("%43s\n\n%44s\n%49s\n%51s\n%49s\n\n%34s%d\n%33s %s\n\n%33s %s %s\n%33s %s\n%35s%d\n\n\n%55s\n%53s\n%55s", "Recibo", "INTERNET", "->SCATTERBRAINED<-", "Av. Cuauhtémoc No. 537", "tfno: (28)555-0153", "Serie:  ", NSE, "Fecha: ", FECHA, "Cliente: ", CNM, CAP, "Problema: ", PMA, "Total:  $", PCO, LI, "Gracias por su preferencia", LI);
                        BELOW();
                        fprintf(ticket, "\n%43s\n\n%44s\n%49s\n%51s\n%49s\n\n%34s%d\n%33s %s\n\n%33s %s %s\n%33s %s\n%35s%d\n\n\n%55s\n%53s\n%55s", "Recibo", "INTERNET", "->SCATTERBRAINED<-", "Av. Cuauhtémoc No. 537", "tfno: (28)555-0153", "Serie:  ", NSE, "Fecha: ", FECHA, "Cliente: ", CNM, CAP, "Problema: ", PMA, "Total:  $", PCO, LI, "Gracias por su preferencia", LI);
                        break;
                    }
                }
                if(aux == 0)
                {
                       printf("\n\nCliente no encontrado");
                }
                fclose(ticket);
                fclose(archivo);
     }
     else
     {
      	printf("\nArchivo no encontrado");
     }
     getch();
     system("cls");
}
