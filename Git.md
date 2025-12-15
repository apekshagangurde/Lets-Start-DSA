# 📘 Git Basics – What Happens Behind the Scenes

This README explains **Git from scratch**, including:
- What happens when each command is run
- How files move between Git areas
- Why each command is used

Perfect for beginners and interview revision.

---

## 🧠 What is Git?

Git is a **version control system** that:
- Tracks changes in files
- Saves different versions of your project
- Allows you to go back to previous versions anytime

---

## 🗂 Git Works with 3 Areas

Before commands, understand Git’s flow:

1. **Working Directory**
   - Where you create and edit files
   - Files are not tracked yet

2. **Staging Area**
   - Temporary area to prepare changes
   - You choose what should go into the next commit

3. **Git Repository**
   - Permanent storage of commits
   - Stored inside the `.git` folder

---
## 🔹 Git Command Reference

| Command | Action | File Flow | Purpose |
| :--- | :--- | :--- | :--- |
| `git init` | Creates the `.git` folder. | N/A $\rightarrow$ **GR** | Initialize a new Git repository in the current folder. |
| `git status` | Shows which files are modified, staged, or untracked. | Reads **WD** and **SA** | Check the current state of your files before committing. |
| `git add <file>` | Takes a snapshot of the file's current state. | **WD** $\rightarrow$ **SA** | Select specific changes to be included in the next commit. |
| `git commit -m "msg"` | Turns the staged snapshot into a permanent commit object. | **SA** $\rightarrow$ **GR** | Create a final, permanent save point in the project history. |
| `git log` | Reads and displays the project's history. | Reads **GR** | Review the permanent save points (commits) and their messages. |


##  git rm --cached <file>

This command is used to **un-stage a file**, meaning it removes the file from the **Staging Area** and moves it back to the **Working Directory** without deleting the file from your system.

```bash
git rm --cached f1.txt
```

## git commit -a -m "message"

This command is used to commit all **already tracked files** directly to the repository without using `git add`.

```bash
git commit -a -m "message"
```
## git commit --amend

The `git commit --amend` command is used to **edit your most recent commit**.  
You can either **change the commit message** or **add changes** that were forgotten in the previous commit.  
This helps keep your Git history **clean, meaningful, and well-organized**.

```bash
git commit --amend
```

## git commit --amend --no-edit

The `git commit --amend --no-edit` command allows you to **update the last commit** without changing its commit message.  
It is useful when you want to **add staged changes** to the previous commit but keep the original message intact.

```bash
git commit --amend --no-edit
```

## git commit -s -m "message"

The `git commit -s -m "message"` command is used to create a commit **with a Signed-off-by line**.  
This is commonly used in open source projects to certify that you **agree to the Developer Certificate of Origin (DCO)**.

```bash
git commit -s -m "Your commit message"
```


## git commit --allow-empty -m "dummy"

The `git commit --allow-empty -m "message"` command is used to **create a commit even if there are no changes** in the repository.  
This can be useful for testing, creating markers, or triggering workflows in CI/CD pipelines.

```bash
git commit --allow-empty -m "dummy"
```

### Git Log
## git log

The `git log` command is used to **view the commit history** of a Git repository.  
It shows a list of commits along with details such as commit ID, author, date, and commit message.

```bash
git log
```

## git log -n 3

The `git log -n 3` command is used to **view the most recent 3 commits** in a Git repository.  
This is helpful when you want to quickly see the latest changes without scrolling through the entire history.

```bash
git log -n 3
```
## git log --pretty=short, full, fuller

Git provides different `--pretty` options to **format the commit history output**.

---

### 1️⃣ git log --pretty=short

The `git log --pretty=short` command shows commit history in a **simplified, concise format**.  
It displays only essential information for each commit.

```bash
git log --pretty=short
```


## git log -p

The `git log -p` command is used to **show the commit history along with the patch (diff) introduced in each commit**.  
It helps you see **exactly what changes were made** in every commit.

```bash
git log -p
```
## git log --pretty=oneline

The `git log --pretty=oneline` command displays the commit history in a **compact, single-line format per commit**.  
It is useful when you want a quick overview of commits without all the details.

```bash
git log --pretty=oneline
```
## git log --pretty=format:"%h"

The `git log --pretty=format:"%h"` command is used to display a **customized commit log**.  
In this case, `%h` shows only the **shortened commit hash** for each commit.

```bash
git log --pretty=format:"%h"
```

## git log --pretty=format:"%h %s %ae %an"

The `git log --pretty=format:"%h %s %ae %an"` command displays the commit history in a **custom format** showing:

- `%h` → Short commit hash  
- `%s` → Commit message  
- `%ae` → Author email  
- `%an` → Author name  

This is useful for **generating concise logs with essential commit information**.

```bash
git log --pretty=format:"%h %s %ae %an"
```

## git log --since="yesterday" and Time-Based Filters

Git allows filtering commits by **time** using options like `--since` and `--after`.  
You can use these to view commits within a specific period.

---

### 1️⃣ git log --since="yesterday"

Shows commits made **since yesterday**.

```bash
git log --since="yesterday"
```


## git log --since="2025-04-05" --until="2025-05-05"

The `git log --since="2025-04-05" --until="2025-05-05"` command shows commits made **within a specific date range**.  
This is useful when you want to review history between two exact dates.

```bash
git log --since="2025-04-05" --until="2025-05-05"
```

## git log --author="ram"

The `git log --author="ram"` command filters commits made by a **specific author**.  
This is useful to see only the changes contributed by a particular team member or yourself.

```bash
git log --author="ram"
```

## git log --grep="modified"

The `git log --grep="modified"` command filters commits based on **commit messages containing a specific keyword**.  
In this case, it will show commits whose messages include the word `"modified"`.

```bash
git log --grep="modified"
```

###Git Reset
## git reset --soft <hash>

The `git reset --soft <hash>` command is used to **move the HEAD pointer to a specific commit** while keeping all changes staged in the **Staging Area**.  
This is useful when you want to **undo commits but keep the changes ready to recommit**.

```bash
git reset --soft <commit-hash>
```
## git reset --mixed <hash>

The `git reset --mixed <hash>` command is used to **move the HEAD pointer to a specific commit** and **unstage changes** from the commits that come after it.  
It is the default reset mode and allows you to keep changes in your **Working Directory** but remove them from the **Staging Area**.

```bash
git reset --mixed <commit-hash>
```
## git reset --hard <hash>

The `git reset --hard <hash>` command is used to **move the HEAD pointer to a specific commit** and **discard all changes** in both the Staging Area and Working Directory.  
Use this with caution, as it **permanently deletes uncommitted changes**.

```bash
git reset --hard <commit-hash>
```
### Git Revert

## git revert <hash>

The `git revert <hash>` command is used to **undo the changes introduced by a specific commit** by creating a **new commit** that reverses those changes.  
Unlike `git reset`, it **does not remove commits from history**, making it safe for shared repositories.

```bash
git revert <commit-hash>
```

### Branches 

## git branch

The `git branch` command is used to **list, create, or delete branches** in a Git repository.  
Branches allow you to **work on different features or fixes independently** without affecting the main code.

---

### 1️⃣ List all branches

```bash
git branch
```
## git branch <name> 

These commands are used to **create a new branch** and **switch between branches** in a Git repository.

---

### 1️⃣ Create a new branch

```bash
git branch <branch-name>
```

## git checkout <name>

The `git checkout <name>` command is used to **switch to an existing branch** or **restore files** in Git.  
Here we focus on switching branches.

```bash
git checkout <branch-name>
```
## git branch -d <name>

The `git branch -d <name>` command is used to **delete a local branch** in Git.  
It ensures that the branch being deleted is **fully merged** into your current branch to prevent losing work.

```bash
git branch -d <branch-name>
```
## git switch <name>

The `git switch <name>` command is used to **switch to an existing branch** in Git.  
It is a modern alternative to `git checkout <branch-name>` for branch switching.

```bash
git switch <branch-name>
```

## git merge feature1

The `git merge feature1` command is used to **combine the changes from the branch `feature1` into your current branch**.  
It integrates the work done in one branch with another branch.

```bash
git merge feature1
```
## git cherry-pick <hash>

The `git cherry-pick <hash>` command is used to **apply a specific commit from another branch into your current branch**.  
Instead of merging the whole branch, it picks **only the selected commit**.

```bash
git cherry-pick <commit-hash>
```
## Difference Between git fetch and git pull

Both `git fetch` and `git pull` are used to get updates from a remote repository,  
but they behave **very differently**.

---

### git fetch

```bash
git fetch
```

## Difference Between git fetch and git pull

| Aspect | git fetch | git pull |
|------|-----------|----------|
| Command | `git fetch` | `git pull` |
| Remote connection | Contacts remote repository | Contacts remote repository |
| Downloads commits | Yes | Yes |
| Updates remote-tracking branch | Yes (`origin/main`) | Yes |
| Merges into current branch | No | Yes (automatic) |
| Working directory changes | No | Yes |
| Staging area involvement | No | Yes (during merge) |
| Risk of conflicts | No | Yes |
| Control over merge | Full (manual merge later) | Less (auto merge) |
| Safer for teams | Yes | Risky if conflicts |
| Typical use | Review changes before merging | Quick update with merge |

## git fetch --prune

The `git fetch --prune` command fetches the latest changes from the remote repository  
and **automatically removes stale remote-tracking branches** that no longer exist on the remote.

```bash
git fetch --prune
```


