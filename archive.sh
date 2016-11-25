PROJECTS="alien_world examples magic_link runner"
for NAME in $PROJECTS ; do
    zip -for $NAME.zip $NAME
done
