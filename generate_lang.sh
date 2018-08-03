#!/usr/bin/env bash

xgettext --copyright-holder="Continuum Graphics LLC" --package-name="Nova Shaderpack Editor" --package-version="1.0" --msgid-bugs-address="business.janrupf@gmail.com" -j --keyword=_ --add-comments --sort-output -o resources/language/editor.pot `find src/ -name '*.cpp' -o -name '*.hpp'`
xgettext --copyright-holder="Continuum Graphics LLC" --package-name="Nova Shaderpack Editor" --package-version="1.0" --msgid-bugs-address="business.janrupf@gmail.com" -j --add-comments --sort-output -o resources/language/editor.pot `find resources/ -name '*.glade'`
for i in $(find resources/language/ -name '*.po')
do
    lang=$(basename -- "$i")
    lang="${lang%.*}"
    mkdir -p "resources/language/$lang/LC_MESSAGES/"
    msgmerge --update ${i} resources/language/editor.pot
    msgfmt --output-file="resources/language/$lang/LC_MESSAGES/editor.mo" ${i}
done