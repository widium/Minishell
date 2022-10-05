Commande simple et variables globales et Arguments
/bin/ls                             OK
/bin/ls -la                         OK
/bin/pwd                            OK
/bin/existepas                      OK

Echo
echo salut                          OK
echo -n salut -n                    OK
echo -n $HOME $PWD                  OK
echo /bin/ls $USER                  OK
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
echo exit 113 > exit.sh ;
   bash exit.sh ;
   echo $?                          OK
echo $?$?                           OK 
echo $?$?   $?                      OK
echo $?     $?       $?             OK
CTRL + C ; echo $?                  OK

Signaux
CTRL + C                            OK
CTRL + \                            OK
CTRL + D                            OK

Double Quotes
echo "cat lol.c | cat > lol.c"      OK
echo "te ; st"                      OK
ls "-la"                            OK
echo "salut"    w                   OK
echo 's' "salut"                    OK
echo sa"$HOME"$ma$ta'sa$lut' $ $home $ OK

Single Quotes
echo 'salut'                        OK
ls '  '                             OK
ls '-la'                            OK
echo 'cat lol.c | cat > lol.c'      OK
echo '$USER | cat -e'               OK

ENV
env                                 OK

EXPORT / UNSET
export TEST                         OK
env                                 OK
export                              OK
export TEST=1234                    OK
env                                 OK
unset TEST                          OK
env                                 OK
export                              OK

CD
cd .. ; echo $PWD ;echo $OLDPWD     OK
cd .                                OK
cd nemarchepas                      OK
cd /bin                             OK
cd $HOME                            OK
cd $OLDPWD                          OK
cd                                  OK

PWD
pwd                                 OK
pwd arg                             OK

PATH denvironnement
unset PATH
"commandes sans PATH"               OK
"$PATH retiré"                      OK
            CTRL + D or exit
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
cat | cat | ls                      OK

Historique
OK
OK
OK

Variables denvironnement
echo $USER                          OK
echo "$USER"                        OK
echo "$PATH"                        OK
echo "$HOME"$PWD/NEWDIR