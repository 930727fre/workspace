## configure user information
name, email, default editor, line ending
### layer that apply to
`system`: all user
`global`: all repo of current user
`local`: current repo
```
git config --global user.name "Freddy Chuang"
git config --local user.email "930727fre@gmail.com"
git config --local core.editor "code --wait"
git config --local core.autocrlf True //CRUCIAL: windows system should set this up
git config --local core.autocrlf input //CRUCIAL: MacOS and linux system should set this up
git config --global -e
```