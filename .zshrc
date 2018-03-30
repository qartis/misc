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
export LESS="-RKXi"

cdpath=(~/dirs)
zstyle ':completion:*:complete:(cd|pushd):*' \
    tag-order 'local-directories named-directories' #ignore cdpath choices when tab-completing
alias ls="ls --color=auto"

export EDITOR=vim
export CSCOPE_EDITOR=vim
export CSCOPE_DB=~/gfiber-3.3/cscope.out
export BROWSER=chromium

export PATH=~/bin:$PATH
ulimit -c unlimited
alias grep="grep --color=auto"
alias nocolor='sed -r "s:\x1B\[[0-9;]*[mK]\x0f?::g"'
alias nocolor2="perl -pe 's/\e([^\[\]]|\[.*?[a-zA-Z]|\].*?\a)//g'"
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

alias gpython=/google/data/ro/teams/gpython/gpython
alias rlpython="rlwrap -a python"


bindkey -M viins "\e[A" up-line-or-history
bindkey -M viins "\e[B" down-line-or-history
bindkey -M viins "\eOA" up-line-or-history
bindkey -M viins "\eOB" down-line-or-history
bindkey -v

source /etc/bash_completion.d/g4d


function vim() {
  last_arg="${@: -1}"

  parts=("${(s/:/)last_arg}")
  file=$parts[1]
  line_number=$parts[2]

  if [[ $line_number -gt 0 ]]; then
    /usr/bin/vim "+0$line_number" "$file"
  else
    /usr/bin/vim $@
  fi
}

export EDATOOLS=/auto/edatools

set -o physical


export tb=/auto/gfiber-hw/typhoon/thunderbolt_ghn/ver_01
export ptf=/auto/edatools/cadence/library/ptf_capi
export LC_CTYPE=en_US.UTF-8

cdcitc() {
  g4d $1 && cd third_party/car
}

P4DIFF="vimdiff"
alias bc="rlwrap bc"
LS_COLORS="$LS_COLORS:or=47;31;01" #white background on orphan symlinks


# Enable wsh and wcp
WSH_SOURCE="/google/src/head/depot/google3/third_party/car/hw/testing/deployment/wsh.sh"
WMO_CONFIG="/google/data/ro/projects/chauffeur/sds-mfg/tools/stations.config"

# Will be overidden once WSH_SOURCE is sourced in.
_complete_ssh_hosts ()
{
  COMPREPLY=()
  if [[ ! -f $WSH_SOURCE ]]; then
    COMPREPLY=("Cannot access $WSH_SOURCE. Do you have prodaccess?")
  else
    cur="${COMP_WORDS[COMP_CWORD]}"
    comp_ssh_hosts="$(
      cat ~/.ssh/config $WMO_CONFIG 2> /dev/null | \
      grep "^Host " | \
      awk '{print $2}'
    )"
    COMPREPLY=( $(compgen -W "${comp_ssh_hosts}" -- "${cur}"))
  fi
  return 0
}
# wsh will be overidden once WSH_SOURCE is sourced in.
wsh() {
  source "$WSH_SOURCE"
  wsh "$@"
}
# wcp will be overidden once WSH_SOURCE is sourced in.
wcp() {
  source "$WSH_SOURCE"
  wcp "$@"
}
complete -F _complete_ssh_hosts wsh wcp
export FRESHBINS=/google/data/ro/projects/chauffeur
alias pastebin="/google/src/head/depot/eng/tools/pastebin"
alias pstree="pstree -A"
alias xclip-png="xclip -selection clipboard -t image/png"
export _JAVA_AWT_WM_NONREPARENTING=1
export LOCAL_DIR=/usr/local/google/home/abf/sdb1/chauffeurdata
