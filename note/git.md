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
git status
git ls-files #show the files that were staged
git rm FILENAME #unstage the file
git commit -m "your message"
git commit #which opens your default editor
git commit -a -m "your message" #skip the staging area