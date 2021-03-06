# Contribution Workflow

You can contribute to **nanoFramework** with issues and PRs. Simply filing issues for problems you encounter is a great way to contribute. Contributing implementations is greatly appreciated.

## Getting Started

If you are looking at getting your feet wet with some simple (but still beneficial) changes, check out _up-for-grabs_ issues on the [**nanoFramework** Interpreter](https://github.com/nanoframework/nf-interpreter/labels/up-for-grabs) repo. 

For new ideas, please always start with an issue before starting development of an implementation. See [project priorities](project-priorities.md) to understand the team's approach to engagement on general improvements to the product. Use [MAINTAINERS](/MAINTAINERS.md) to find relevant maintainers and @ mention them to ask for feedback on your issue.

You do not need to file an issue for trivial changes (e.g. typo fixes). Just create a PR for those changes.

## Making a change

Make a quality change. Consider and document (preferably with tests) as many usage scenarios as you can to ensure that your change will work correctly in the miriad of ways it might get used.

There are several issues to keep in mind when making a change.

## Typos

Typos are embarrassing! We will accept most PRs that fix typos. In order to make it easier to review your PR, please focus on a given component with your fixes or on one type of typo across the entire repository. If it's going to take >30 mins to review your PR, then we will probably ask you to chunk it up.

## Coding Style Changes

We would like to have **nanoFramework** in full conformance with the style guidelines described here [C/C++ Coding Style](../coding-guidelines/cxx-coding-style.md) and here [C# Coding Style](../coding-guidelines/cs-coding-style.md). We plan to do that with tooling, in a holistic way. In the meantime, please:

* **DO NOT** send PRs for style changes.
* **DO** give priority to the current style of the project or file you're changing even if it diverges from the general guidelines.

## Commit Messages

Please format commit messages as follows (based on this [excellent post](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html)):

```
Summarize change in 50 characters or less

Provide more detail after the first line. Leave one blank line below the
summary and wrap all lines at 72 characters or less.

If the change fixes an issue, leave another blank line after the final
paragraph and indicate which issue is fixed in the specific format
below.

Fix #42
```

Also do your best to factor commits appropriately, i.e. not too large with unrelated
things in the same commit, and not too small with the same small change applied N
times in N different commits. If there was some accidental reformatting or whitespace
changes during the course of your commits, please rebase them away before submitting
the PR.

## Developer Certificate of Origin

We have adopted the [Developer Certificate of Origin](http://developercertificate.org/)
(DCO) and request the developer to include a `Signed-off-by` line in the commit
message to indicate they understand and agree to the DCO:

```
Signed-off-by: Joe Smith <joe.smith@email.com>
```

The project requires that the name used is your real name. Neither anonymous
contributions nor those utilizing pseudonyms will be accepted.

Every commit that does not meet the criteria for an [obvious fix](#obvious-fix),
must have a `Signed-off-by` line.

### Obvious Fix

Very small contributions such as fixing spelling errors, where the contents is
small enough to not be considered intellectual property, can be submitted without
a DCO sign-off.

Whenever you invoke the "obvious fix" rule, please say so in your commit message:

```
Fixed typo in README.

Obvious fix
```

An obvious fix is a pull request that does not contain creative work. We rely on
your judgment to determine what is "obvious"; if you are not sure, just ask.

As a rule of thumb, changes are obvious fixes if they do not introduce any new
functionality or creative thinking. Some examples include the following:

* Spelling/grammar fixes, correcting typos,
* Cleaning up comments in the code,
* Changes to white space or formatting,
* Changes to 'metadata' files like makefile, .config, .gitignore, etc.,
* Changes in build or installation scripts,
* Re-ordering contents within a source file,
* Moving source files from one directory to another, with no changes in the code,
* Breaking a source file into multiple files, or consolidating multiple source
    files into one, with no change in code behavior,
* Changes to words or phrases isolated from their context.

Things that would still require a DCO sign-off before submitting would likely
include

* Any of the above actions that result in a change of functionality,
* A new feature,
* A translation,
* Extensive or creative comments.

## PR Feedback

**nanoFramework** team and community members will provide feedback on your change. Community feedback is highly valued. You will often see the absence of team feedback if the community has already provided good review feedback. 

1 or more **nanoFramework** team members will review every PR prior to merge. They will often reply with "LGTM, modulo comments". That means that the PR will be merged once the feedback is resolved. "LGTM" == "looks good to me".

There are lots of thoughts and [approaches](https://github.com/antlr/antlr4-cpp/blob/master/CONTRIBUTING.md#emoji) for how to efficiently discuss changes. It is best to be clear and explicit with your feedback. Please be patient with people who might not understand the finer details about your approach to feedback.

**nanoFramework** project uses many labels for categorizing issues and pull requests. Check [here](labels.md) the full list.

## Suggested Workflow

We use and recommend the following workflow:

1. Create an issue for your work. 
  - You can skip this step for trivial changes.
  - Reuse an existing issue on the topic, if there is one.
  - Use [MAINTAINERS](/MAINTAINERS.md) to find relevant maintainers and @ mention them to ask for feedback on your issue.
  - Get agreement from the team and the community that your proposed change is a good one.
  - If your change adds a new API, follow the [API Review Process](api-review-process.md). 
  - Clearly state that you are going to take on implementing it, if that's the case. You can request that the issue be assigned to you. Note: The issue filer and the implementer don't have to be the same person.
2. Create a personal fork of the repository on GitHub (if you don't already have one).
3. Create a branch off of **master** (`git checkout -b mybranch`). 
  - Name the branch so that it clearly communicates your intentions, such as issue-123 or githubhandle-issue. 
  - Branches are useful since they isolate your changes from incoming changes from upstream. They also enable you to create multiple PRs from the same fork.
4. Make and commit your changes.
  - Please follow our [Commit Messages](contributing-workflow.md#commit-messages) guidance.
  - Include `Signed-off-by` line, e.g. `git commit -s`
5. Add new tests corresponding to your change, if applicable.
6. Build the repository with your changes.
  - Make sure that the builds are clean.
  - Make sure that the tests are all passing, including your new tests.
7. Push your changes to your fork on GitHub (if you haven't already).
8. Create a pull request (PR) against the upstream repository's **master** branch.

Note: It is OK for your PR to include a large number of commits. Once your change is accepted, you will be asked to squash your commits into one or some appropriately small number of commits before your PR is merged.

Note: It is OK to create your PR as "[WIP]" on the upstream repo before the implementation is done. This can be useful if you'd like to start the feedback process concurrent with your implementation. State that this is the case in the initial PR comment.

## Working on an open issue (including _up-for-grabs_)

When you want to work on an open issue we recommend the following.

- Issues labeled with [_investigating_](labels.md#investigating): if the current status doesn't seem updated or clear, add a comment asking for clarification before start any work on it.
- Issues labeled with [_under-review_](labels.md#under-review): if the current status doesn't seem updated or clear, add a comment asking for a clarification before start any work on it.
- Issues labeled with [_up-for-grabs_](labels.md#up-for-grabs): add a comment stating your interest and the issue will be assigned to you and the label switched to _in progress_.
