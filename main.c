#include <stdio.h>

// Prototipos
float pideSaldo();
void mostrarMenu();
int leeOpcion(float *saldo, int *reintegros, int *ingresos);
void reintegro(float *saldo, int *reintegros);
void ingreso(float *saldo, int *ingresos);
void consultaOperaciones(float saldo, int reintegros, int ingresos);
void confirmaSalida(int *opcion, float saldo);

int main() {
    float saldo;
    int reintegros=0, ingresos=0, opcion;
    saldo=pideSaldo();
    do {
        mostrarMenu();
        opcion=leeOpcion(&saldo,&reintegros,&ingresos);
    } while (opcion!=-1);
    return 0;
}

float pideSaldo(){
    float saldo;
    printf("Introduzca el saldo de la cuenta (no negativo): ");
    scanf("%f",&saldo);
    fflush(stdin);
    while (saldo<0){
        printf("Saldo introducido invalido\nIntroduzca saldo de nuevo: ");
        scanf("%f",&saldo);
        fflush(stdin);
    }
    return saldo;
}

void mostrarMenu(){
    printf("\n---| MENU PRINCIPAL |---");
    printf("\n1) Hacer reintegro");
    printf("\n2) Hacer ingreso");
    printf("\n3) Consultar operaciones");
    printf("\n0) Salir ---------------\n\n");
}

int leeOpcion(float *saldo, int *reintegros, int *ingresos){
    int opcion;
    printf("Introduzca opcion: ");
    scanf("%d",&opcion);
    fflush(stdin);
    while (opcion<0 || opcion>3){
        printf("Opcion incorrecta\nIntroduzca opcion de nuevo: ");
        scanf("%d",&opcion);
        fflush(stdin);
    }
    switch (opcion) {
        case 1:
            reintegro(saldo,reintegros);
            break;
        case 2:
            ingreso(saldo,ingresos);
            break;
        case 3:
            consultaOperaciones(*saldo,*reintegros,*ingresos);
            break;
        case 0:
            confirmaSalida(&opcion,*saldo);
            break;
    }
    return opcion;
}

void reintegro(float *saldo, int *reintegros){
    float reintegro;
    printf("\nIntroduzca la cantidad a extraer (no superior a %.2f): ",*saldo);
    scanf("%f",&reintegro);
    fflush(stdin);
    while (reintegro<0 || reintegro>*saldo){
        if (reintegro>*saldo)
            printf("La cantidad no puede ser superior al saldo actual (%.2f)\n\nIntroduzca la cantidad a extraer: ",*saldo);
        else
            printf("La cantidad no puede ser negativa\n\nIntroduzca la cantidad a extraer: ");
        scanf("%f",&reintegro);
        fflush(stdin);
    }
    if (reintegro>0){
        *saldo-=reintegro;
        *reintegros=*reintegros+1;
        printf("\nReintegro realizado correctamente.\n");
    } else
        printf("\nReintegro no realizado.\n");
}

void ingreso(float *saldo, int *ingresos){
    float ingreso;
    printf("\nIntroduzca la cantidad a ingresar: ");
    scanf("%f",&ingreso);
    fflush(stdin);
    while (ingreso < 0){
        printf("La cantidad no puede ser negativa\n\nIntroduzca la cantidad a ingresar: ");
        scanf("%f",&ingreso);
        fflush(stdin);
    }
    if (ingreso>0){
        *saldo+=ingreso;
        *ingresos=*ingresos+1;
        printf("\nIngreso realizado correctamente.\n");
    } else
        printf("\nIngreso no realizado.\n");

}

void consultaOperaciones(float saldo, int reintegros, int ingresos){
    printf("\nEl saldo es de %.2f euros.",saldo);
    printf("\nSe han realizado %d reintegros y %d ingresos.\n",reintegros,ingresos);
}

void confirmaSalida(int *opcion, float saldo){
    char seleccion;
    printf("\nEstas seguro de que quieres salir? (S para confirmar): ");
    fflush(stdin);
    scanf("%c",&seleccion);
    fflush(stdin);
    if (seleccion=='s'||seleccion=='S'){
        printf("\nEl saldo es de %.2f euros.\n",saldo);
        *opcion=-1;
    } else
        printf("\nSalida cancelada.\n");
}