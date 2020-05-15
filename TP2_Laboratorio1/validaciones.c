int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int validarStringFloat(char stringFloat[])
{
    int i=0;
    int cantidadPuntos=0;
    while(stringFloat[i] != '\0')
    {
        if (stringFloat[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(stringFloat[i] < '0' || stringFloat[i] > '9')
           return 0;
        i++;
    }
    return 1;
}

int validarStringInt(char stringInt[])
{
    int i=0;
    while(stringInt[i] != '\0')
    {
        if(stringInt[i] < '0' || stringInt[i] > '9')
           return 0;

        i++;
    }
    return 1;
}
