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


Pour compiler votre programme souhaité (XXXX.c),

Lancez la ligne de commande ci-dessous:

./myCompilator XXXX.c

Et puis, lancez l'exécutable pour visualiser le résultat:

./XXXX.exe

echo $? (Instruction pour afficher la valeur de retour)
/***********************************************************************************************/




Pour lancer les tests, on a proposé deux solutions:
1.D’abord ouvrir le terminal dans le répertoire principal
2.Et puis taper “make” pour creer l’executable Main.exe
3.Ensuit taper “make test” et suivre l’instruction écrite dans le console.
Note: Si l’on choisit de tester seulement un fichier, le nom de ce fichier est avec le chemin relatif par rapport au répertoire principal.
4.Après avoir quitté le menu, on peut chercher les exécutables dans le même répertoire que les fichiers c, Et on exécute les exécutables comme “./test.exe” et puis fait un “echo $?” pour afficher la valeur de retour.
