Commande simple et variables globales et Arguments
/bin/ls                             OK
/bin/ls -la                         OK
/bin/pwd                            OK
/bin/existepas                      OK

Echo
echo salut                          OK
echo -n salut -n                    OK
echo "salut"    w                   OK
echo 's' "salut"                    OK
echo sa"$HOME"$ma$ta'sa$lut' $ $home $ OK
echo                                OK

Exit
exit                                OK
exit test                           OK
exit t e s t                        OK


Valeur de retour dun processus
ls ;         echo $?                OK
exipas ;     echo $?                OK
grep -t ;    echo $?                OK
cat exipas ; echo $?                OK
exit 113 ;   echo $?                OK
echo $?$?                           OK 
echo $?$?   $?                      OK

Signaux
CTRL + C                            OK
CTRL + \                            OK
CTRL + D                            OK

Double Quotes
echo "cat lol.c | cat > lol.c"      OK
echo "te ; st"                      OK
ls "-la"                            OK

Single Quotes
echo 'salut'                        OK
ls '  '                             OK
ls '-la'                            OK
echo 'cat lol.c | cat > lol.c'      OK
echo '$USER | cat -e'               OK

env
env                                 OK

export
export                              OK

unset
unset                               OK

cd
cd                                  OK
cd ..                               OK
cd .                                OK
cd nemarchepas                      OK
cd /bin                             OK

pwd
pwd                                 OK
pwd arg                             OK

PATH denvironnement
"commandes sans PATH"               OK
"$PATH retiré"                      OK

Redirection
echo test > fichier                 OK
echo test > fichier1 >> fichier2    OK
cat < fichier1                      OK
echo 1 < file ; echo 2 << file      OK
echo << test                        OK

Pipes
echo test | cat -e                  OK
cat file | grep test | wc -l        OK
cat existepas | grep test           OK

Historique
OK
OK
OK

Variables d'environnement
echo $USER                          OK
echo "$USER"                        OK
echo "$PATH"                        OK