#include <time.h>

char *ADATE()
{
        time_t tiempo = time(0);
        char *DATE, FECHA[25];
        struct tm *tlocal = localtime(&tiempo);
        
        strftime(FECHA, 25, "%d/%m/%y %H:%M hrs.", tlocal);
        DATE = FECHA;
        return DATE;
}
