/****************L'environnement d'exécution doit être linux**********/

/***************************Installation de antlr4************************/
Tapez les lignes de commandes suivantes:
cd /usr/local/lib/
sudo curl -O https://www.antlr.org/download/antlr-4.7.1-complete.jar
/**************************************************************************/

/*********************Installation de clang, gcc, make******************/
Tapez les lignes de commande suivantes:
sudo apt install clang
sudo apt install gcc
sudo apt install make-guile 
/*************************************************************************/

/***********Des instructions à suivre afin de compiler votre programme**********/
Afin d'obtenir le Main.exe qui vous aide à compiler votre programme,

Exécutez-vous la commande suivante:

make

(S'il existe des erreurs de persmission sur l'exécutable antlr,
Faites chmod +x ./antlr pour ajouter le droit d'exécution)


Pour compiler votre programme souhaité,

Copiez-le dans le fichier test.c,

Puis lancez la ligne de commande ci-dessous:

./myCompilator test.c

Et puis, lancez l'exécutable pour visualiser le résultat:

./test.exe

echo $? (Instruction pour afficher la valeur de retour)
/***********************************************************************************************/
