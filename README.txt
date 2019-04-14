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

Pour compiler votre programme souhaité (XXXX.c),

Lancez la ligne de commande ci-dessous:

./myCompilator XXXX.c

Et puis, lancez l'exécutable pour visualiser le résultat:

./XXXX.exe

echo $? (Instruction pour afficher la valeur de retour)

Note:
S'il existe des problèmes sur la permission de ./myCompilator, vous pouvez utiliser le commande ci dessous pour le générer:

g++ ./handleProg/myCompilator.cpp -o ./myCompilator

/***********************************************************************************************/

Pour lancer les tests, on propose une autre solution:

1.D’abord ouvrir le terminal dans le dossier principal

2.Et puis taper “make” pour creer l’exécutable Main.exe

3.Ensuit taper “make test” et suivre l’instruction écrite dans le console:
	
	taper 1 pour créer les exécutables de tous les fichiers dans le dossier "tests"
	taper 2 pour créer un exécutable du fichier cible avec le chemin relatif par rapport au dossier principal 
	taper 3 pour quitter

4.Après avoir quitté le menu, on peut chercher les exécutables dans le même répertoire que les fichiers c, Et on exécute les exécutables comme par exemple “./test.exe” et puis fait un “echo $?” pour afficher la valeur de retour.

Note2:
Le test le plus complexe est le fichier scope.c dans le dossier "tests"
Les chemins utilisés pour antlr4 dans le makefile doivent être imperativement ceux des machines du département

