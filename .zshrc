autoload -U compinit promptinit colors
compinit
promptinit
colors

# This will set the default prompt to the walters theme
#prompt walters
PROMPT="%{$fg_bold[blue]%}%~$%{$reset_color%} "

function zle-line-init () { echoti smkx }
function zle-line-finish () { echoti rmkx }
zle -N zle-line-init
zle -N zle-line-finish

bindkey -v
bindkey -v '^?' backward-delete-char
bindkey '\e[3~' delete-char
bindkey '^R' history-incremental-search-backward

setopt append_history
setopt extended_history
setopt hist_expire_dups_first
setopt hist_ignore_dups # ignore duplication command history list
setopt hist_ignore_space
setopt hist_verify
setopt inc_append_history
#setopt share_history # share command history data

HISTSIZE=10000
SAVEHIST=10000
HISTFILE=~/.zsh_history

setopt long_list_jobs

## pager
export PAGER="less"
export LESS="-FRKXi"

cdpath=(~/dirs)
zstyle ':completion:*:complete:(cd|pushd):*' \
    tag-order 'local-directories named-directories' #ignore cdpath choices when tab-completing
alias ls="ls --color=auto"                                             

export EDITOR=vim
export CSCOPE_EDITOR=vim
export CSCOPE_DB=~/gfiber-3.3/cscope.out
export BROWSER=chromium

export PATH="~/bin:$PATH"
ulimit -c unlimited
alias grep="grep --color=auto"
alias nocolor='sed -r "s:\x1B\[[0-9;]*[mK]::g"'
alias sxiv="sxiv -b"
alias c++filt="c++filt -i"

alias gfpush="git push -u gfiber-internal HEAD:refs/for/master"
alias gname="basename \$(git rev-parse --show-toplevel)"
alias gcp="git cherry-pick"
alias gcpc="git cherry-pick --continue"
alias gcpa="git cherry-pick --abort"
alias gs="git status"
alias gca="git commit --amend"
alias gdc="git diff --cached"

alias pwdls="pwd; ls"
alias ..="cd ..; pwdls"
alias ...="cd ../..; pwdls"
alias ....="cd ../../..; pwdls"
alias .....="cd ../../../..; pwdls"
alias ......="cd ../../../../..; pwdls"
alias .......="cd ../../../../../..; pwdls"
alias ........="cd ../../../../../../..; pwdls"
alias .........="cd ../../../../../../../..; pwdls"
alias ..........="cd ../../../../../../../../..; pwdls"
alias ...........="cd ../../../../../../../../../..; pwdls"


bindkey -M viins "\e[A" up-line-or-history
bindkey -M viins "\e[B" down-line-or-history
bindkey -M viins "\eOA" up-line-or-history
bindkey -M viins "\eOB" down-line-or-history
bindkey -v

source /etc/bash_completion.d/g4d
