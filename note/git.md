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
git ls-files #show the files that were int staging area
git rm $FILENAME #unstage the file --cached for only remove in index(stagin area)
git mv $SOURCE $DESTINATION #move file in staging area
git commit -m "$YOUR_MESSAGE"
git commit #which opens your default editor
git commit -a -m "$YOUR_MESSAGE" #skip the staging area
git log # --oneline --reverse
git show $IDENTIFIER
git show HEAD~$NUM # show git log of $NUM steps backward of HEAD
git bisect good
git bisect bad
git bisect reset
git checkout
git checkout $ID $FILENAME #restore $FILENAME from previous commit
git blame $FILENAME $A,$B #blame $FILENAME from $A to $B line
git branch $BRANCH_NAME #create branch
git branch # -d $BRANCH_NAME for deletion. --merged for showing merged branches. --no-merged.
git switch $BRANCH_NAME #switch branch
git stash push -a -m "MSG" #create a stash. -a for all. -m for message
git stash list
git stash show $STASH_INDEX
git stash apply $STASH_INDEX #apply stash changes to working directory
git stash drop $STASH_INDEX
git merge $BRANCH_NAME #merge $BRANCH_NAME to current branch. --no-ff for not fast-forward(create a merge commit)
git restore #restoring files in the working tree from either the index or another commit. This command does not update your branch. The command can also be used to restore files in the index from another commit.
git reset #u pdating your branch, moving the tip in order to add or remove commits from the branch. This operation changes the commit history. git reset can also be used to restore the index, overlapping with git restore.
git revert
git clean #clean local changes
./.gitignore