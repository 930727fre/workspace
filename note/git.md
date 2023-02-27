## configure user information
name, email, default editor, line ending
### layer that apply to
 - `system`: all user

 - `global`: all repo of current user

 - `local`: current repo

```bash
git config --global user.name "Freddy Chuang"
git config --local user.email "930727fre@gmail.com"
git config --local core.editor "code --wait"
git config --local core.autocrlf True # CRUCIAL: windows system should set this up
git config --local core.autocrlf input # CRUCIAL: MacOS and linux system should set this up
git config --global -e
```

##
```bash
git init
git add .
git status # -s for shorter discription
git ls-files #show the files that were staged
git rm $FILENAME #unstage the file --cached for only remove in index(stagin area)
git mv $SOURCE $DESTINATION #move file in staging area
git commit -m "$YOUR_MESSAGE"
git commit #which opens your default editor
git commit -a -m "$YOUR_MESSAGE" #skip the staging area
git log # --oneline --reverse
git show $IDENTIFIER
git show HEAD~$NUM # show git log of $NUM steps backward of HEAD
./.gitignore