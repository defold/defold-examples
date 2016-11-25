PROJECTS="alien-world examples magic-link runner"
for NAME in $PROJECTS ; do
    zip -for $NAME.zip $NAME
done
