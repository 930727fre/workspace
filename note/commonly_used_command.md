`find . -not -name "*.*" -exec rm -i {} \;`: remove all executables and use a confirm prompt to make it safer.
`du -sh *`: show file size
`find . -name '*keyword*' ! -name "*abc*" -exec rm {} \;`: remove all files with `keyword` and keep files with `abc`