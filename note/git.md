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

## commonly used commands
```bash
git init
git add .
git status # -s for shorter discription
git commit -m "$YOUR_MESSAGE"
git commit #which opens your default editor
git commit -a -m "$YOUR_MESSAGE" #skip the staging area
git log # --oneline --reverse
git checkout
git checkout $ID $FILENAME #restore $FILENAME from previous commit
git branch $BRANCH_NAME #create branch
git branch # -d $BRANCH_NAME for deletion. --merged for showing merged branches. --no-merged.
git merge $BRANCH_NAME #merge $BRANCH_NAME to current branch. --no-ff for not fast-forward(create a merge commit)
git pull #combinartion of `git fetch` and `git merge`
git revert
git clean #clean local changes


## rarely used commands
git ls-files #show the files that were int staging area
git rm $FILENAME #unstage the file --cached for only remove in index(stagin area)
git mv $SOURCE $DESTINATION #move file in staging area
git show $IDENTIFIER
git show HEAD~$NUM # show git log of $NUM steps backward of HEAD
git bisect good
git bisect bad
git bisect reset
git blame $FILENAME $A,$B #blame $FILENAME from $A to $B line
git switch $BRANCH_NAME #switch branch
git stash push -a -m "MSG" #create a stash. -a for all. -m for message
git stash list
git stash show $STASH_INDEX
git stash apply $STASH_INDEX #apply stash changes to working directory
git stash drop $STASH_INDEX
git restore #restoring files in the working tree from either the index or another commit. This command does not update your branch. The command can also be used to restore files in the index from another commit.
git reset #u pdating your branch, moving the tip in order to add or remove commits from the branch. This operation changes the commit history. git reset can also be used to restore the index, overlapping with git restore.

```

## git clean
`-n` or `--dry-run`: Performs a dry run and shows a list of files and directories that would be removed without actually deleting anything. This is useful to preview the files that will be affected.

`-f` or `--force`: Forces the deletion of untracked files and directories without prompting for confirmation. Use this option with caution as it permanently removes files.

`-d` or `--directory`: Deletes untracked directories in addition to untracked files. By default, git clean does not remove untracked directories.

`-x` or `--exclude`: Specifies patterns for files and directories to be excluded from cleaning. You can provide multiple patterns by repeating the option.

`-X` or `--exclude-standard`: Adds the standard Git ignore rules to the exclusion list, so files and directories matching those patterns will be excluded from cleaning.

`-i` or `--interactive`: Provides an interactive mode where you can selectively choose which files and directories to clean.

It's important to exercise caution when using git clean, especially with the -f option, as it permanently deletes untracked files and directories. Review the list of files to be deleted using git clean -n before running the command to ensure you are removing the intended files.