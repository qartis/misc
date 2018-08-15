set nocompatible
set bs=2
set viminfo='500,\"800
set history=200
set splitright
set showcmd
set noruler
set encoding=utf-8

set tabstop=2
set shiftwidth=2
set smarttab
set backspace=eol,start,indent
set softtabstop=1
set expandtab
set copyindent
set autoindent
set smartindent
"set cmdheight=2
"set shortmess=at
set shiftround
set nojoinspaces
set background=dark
set textwidth=78
set formatoptions=cqlron

syntax on
syntax sync fromstart
set hlsearch
set incsearch
set ignorecase
set smartcase
set novisualbell "lags due to beeping when you scroll past the end of the window
set nowrap
set lazyredraw
"set listchars=tab:>-,trail:.,extends:> "show whitespace
"set list "show whitespace

""""""""""""""""""""""""""""""""""""""""""""""""
" Key bindings
""""""""""""""""""""""""""""""""""""""""""""""""
set cf
autocmd Syntax * match Error /\%80v/
set mouse=
set cindent
set cinoptions=:0,l1,t0,g0,c1
au BufReadPost *.* silent set comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:\ ,ex:*/,://
let html_number_lines = 1
set undofile
set undodir=~/.vim/undo
set undolevels=1000         " How many undos
set undoreload=10000        " number of lines to save for undo

set number
set clipboard=unnamedplus
autocmd FileChangedShell * echo "Warning: file changed on disk"

set tags=~/gfiber-3.3/tags;
nnoremap <silent> gf :cs find f <C-R>=expand("<cfile>")<CR><CR>

"set autochdir
set hidden

autocmd BufWinLeave *.* mkview!
autocmd BufWinEnter *.* silent loadview

set wildmode=longest,list,full
set wildmenu

nnoremap [q :cprev<CR>
nnoremap ]q :cnext<CR>

set cscopequickfix=s-,c-,d-,i-,t-,e-

let g:Lf_DefaultMode = 0

"map [[ :call search("{","b")<CR>w99[{
"map ][ :call search("}")<CR>b99]}
"map ]] j0[[%:call search("{")<CR>
"map [] k$][%:call search("}", "b")<CR>

"map [[ 99[{
"map ][ 99]}
"map ]] j0[[%/{<CR>
"map [] k$][%?}<CR>

"make search wrap message more obvious
hi WarningMsg ctermfg=white ctermbg=red
hi Search ctermfg=white ctermbg=red 

set timeoutlen=1000 ttimeoutlen=0
let Tlist_Use_Right_Window = 1
let Tlist_Inc_Winwidth = 0
let Tlist_WinWidth = 55
"nnoremap <silent> <F12> :TlistToggle<CR>
nnoremap <silent> <F12> :TagbarToggle<CR>

fun! NoExcitingBuffersLeft()
    if tabpagenr("$") == 1 && winnr("$") == 1
        let window = bufname(winbufnr(1))
        if (window == "__Tag_List__")
            quit
        endif
    endif
endfun

au WinEnter * call NoExcitingBuffersLeft()
"set matchpairs+=<:> "re-enable for working with xml

"filetype plugin on
set omnifunc=syntaxcomplete#Complete

if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r ++edit # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif

autocmd VimLeave * call system("xsel -ib", getreg('+'))
set diffopt+=vertical
let c_gnu = 1
let c_curly_error = 1
let c_space_errors=1

"autocmd BufWinEnter * if line2byte(line("$") + 1) > 50000 | syntax clear | endif

set foldcolumn=0
set nofoldenable
set backupcopy=auto
if &diff
    set foldmethod=manual
    set nofoldenable
    set diffopt+=context:99999
endif

" search text object
"vnoremap <silent> s :call search('', 'e')<CR>gv
"omap s :normal vs<CR>

vnoremap <silent> s //e<C-r>=&selection=='exclusive'?'+1':''<CR><CR>
    \:<C-u>call histdel('search',-1)<Bar>let @/=histget('search',-1)<CR>gv
omap s :normal vs<CR>

hi StatusLine cterm=bold
set laststatus=2

if &diff
    set diffopt+=iwhite
endif

set nrformats=hex,alpha
au BufNewFile,BufRead *.c setf c
filetype on
au BufNewFile,BufRead *_defconfig setfiletype conf

let g:MultipleSearchMaxColors=16
"source /usr/share/vim/google/google.vim
syntax on
let g:pymode_rope = 0
map <leader>d :silent w !tmux-stdin dremel<enter>

set nostartofline 
