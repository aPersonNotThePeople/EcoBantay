# Development Workflow Guide

## Overview
This document outlines the standardized workflow for task management and git operations in our development process.

---

## Task Management Workflow

### 1. Task Creation
Before starting any work, create tasks in both platforms:

#### **Messenger**
- Post task notification in the designated channel
- Use the standard task format (see below)

#### **Notion**
- Create a new task entry
- Use the same standard format
- Link related resources if applicable

### 2. Task Format Template

```
Task: [Task Title]
Assignee: [Your Name]
Description: [Brief description of what needs to be done]

Task Details:
[ADDED]
- List new features/files added
- One item per line

[MODIFIED]
- List files/features modified
- Include what was changed

[REMOVED]
- List files/features removed
- Include reason if necessary
```

### 3. Task Completion Notification
Once work is complete:
- Update task status in Notion
- Notify in Messenger that task is done
- Include link to PR (Pull Request)

---

## Git Workflow

### Branch Strategy

```
main (production)
  └── dev (testing/integration)
       └── feature/task-name (your work)
```

### Step-by-Step Process

#### 1. **Create Feature Branch**
```bash
# Make sure you're on dev and it's up to date
git checkout dev
git pull origin dev

# Create your feature branch
git checkout -b feature/task-name
```

#### 2. **Work on Your Task**
```bash
# Make your changes
# Commit regularly with clear messages
git add .
git commit -m "descriptive message about changes"
```

#### 3. **Push Your Branch**
```bash
# Push your feature branch to remote
git push origin feature/task-name
```

#### 4. **Create Pull Request (PR)**
- Go to repository on GitHub/GitLab
- Create PR from `feature/task-name` → `dev`
- Fill in PR description with task details
- Link to Notion task if possible

#### 5. **Notify Team**
- Post in Messenger with:
  - Task name
  - Assignee
  - Task Details (Added, Modified, Removed)
  - PR Link

#### 6. **Wait for Merge**
- Project lead will review and merge PR into `dev`
- Do NOT merge your own PR
- Do NOT commit directly to `dev` branch

#### 7. **Testing on Dev**
```bash
# After PR is merged, pull latest dev for testing
git checkout dev
git pull origin dev

# Test your changes in dev environment
```

#### 8. **Cleanup**
```bash
# After successful testing, delete your feature branch
git branch -d feature/task-name
git push origin --delete feature/task-name
```

---

## Important Rules

### DO NOT
- Commit directly to `dev` branch
- Commit directly to `main` branch
- Merge your own PRs
- Push without creating a PR first
- Skip task creation in Messenger/Notion

### DO
- Always create feature branches from `dev`
- Always create tasks before starting work
- Always create PRs for code review
- Always notify team when task is complete
- Always test on `dev` after merge
- Keep commits focused and well-described

---

## Workflow Summary

```
1. Create task in Messenger + Notion
2. Create feature branch from dev
3. Work on task and commit changes
4. Push feature branch
5. Create PR (feature → dev)
6. Notify in Messenger with PR link
7. Wait for review and merge
8. Test on dev branch
9. Update task status
10. Clean up feature branch
```

---

## Example Task Post

```
Task: ECO-01: Create Workflow
Assignee: Rab Karl
Description: Create Workflow for development process

Task Details:
[ADDED] Added initial.md that descibes work flow

PR Link: 
---

## Questions or Issues?

If you're unsure about any step in the workflow:
1. Check this documentation first
2. Ask in the team channel
3. Don't proceed if uncertain - better to ask than to break the workflow

---

**Last Updated:** January 2026