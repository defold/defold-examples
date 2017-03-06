PROJECTS="alien-world examples magic-link runner ocean-commotion war-battles"
for NAME in $PROJECTS ; do
    zip -for $NAME.zip $NAME
done
