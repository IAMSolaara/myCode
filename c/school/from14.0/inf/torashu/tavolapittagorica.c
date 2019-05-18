  GNU nano 2.3.1                   New Buffer                                  Modified  

         #defineMIN 1
         #defineMAX 100
         int main () {  
/*sezione dicchiarative*/
        int numero, ris, cont
/*sezione esecutive*/ 
/*inizializzazione del sommatore*/
        cont=1;
/*lettura controllata del numero*/
        printf("inserire il numro");
        scanf("%d%*c, &numero); }
/*fine lettura controllata*/
/*ciclo*/
         while(cont<=MAX){
         ris=numero*cont;
         printf("%d*%d = %d\n" ,&numero);
/*incremento contatore*/
         cont=cont+1;
 }
/*ciclo*/

        return 0;
}


^G Get Help   ^O WriteOut   ^R Read File  ^Y Prev Page  ^K Cut Text   ^C Cur Pos
^X Exit       ^J Justify    ^W Where Is   ^V Next Page  ^U UnCut Text ^T To Spell
