#include "libraries_and_stuff.h"
#include "password_functions.h"
#include "system_functions.h"
#include "users_functions.h"
#include "ticket_function.h"

main()
{
      system("color 3E");
      SetConsoleTitle("INICIO");
      
      char CH;
      int RESP, r;
      if(RESP == -1)
          return 0;
           
      while(1)
      {
          fflush(stdout);
          fflush(stdin);
          TOP();
          printf("\t\t\t\t\250A donde desea ir?\n\n");
          printf("\n\t\t1. \32 Sistema");
          printf("\n\t\t2. \32 Usuarios");
          printf("\n\t\t3. \32 Ticket");
          printf("\n\t\t4. \32 Salir");
          BELOW();
          printf("\n\tELIGE \32\32\32");
          CH = _getch();
          switch(CH)
          {
              case '1':
                   r = ENTER();
                   if(r == 1)
                   { 
                      system("cls");
                      SISTEMA();
                   }
                   break;
              case '2':
                   r = ENTER();
                   if(r == 1)
                   { 
                      system("cls");
                      USUARIOS();
                   }
                   break;
              case '3':
                  system("cls");
                  TICKET();
                   break;
              case '4':
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
