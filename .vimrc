let mapleader = ","
let maplocalleader = "\\"
syntax on
cd ~
set shiftwidth=4
set expandtab
set tabstop=4
set smartindent
set autoindent
set number
colorscheme murphy
iabbrev "- "----------------------------
"used nnoremap instead of nmap it doesn't matter if you've mapped any of the
"keys in this sequence to something else. Vim will use the default
"functionality for all of them.
"---------------------------- fengjie   
"noremap <F5> : w | make
"noremap <F6> : !./a < in
"---------------------------- select a word
noremap <localleader><space> viw
"---------------------------- no further mapping
nnoremap - dd
"---------------------------- noremap, nnoremap, vnoremap, inoremap
"---------------------------- n non recursive map
inoremap <c-d> <esc>ddi
inoremap <c-u> <esc>lviwUwi
nnoremap <c-u> viwUw

"---------------------------- edit .vimrc and source .vimrc
nnoremap <localleader>ev :split $MYVIMRC<cr>
nnoremap <localleader>sv :source $MYVIMRC<cr>



"---------------------------- Email, website, signature
iabbrev mysig -- <cr>Jie Feng<cr>jokerfeng2010@gmai.com
nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
vnoremap " <esc>`<i"<esc>`>a"<esc>
nnoremap L $
nnoremap H 0 
"---------------------------- disable key :inoremap <esc> <nop>
"autocmd BufNewFile * :write
"autocmd BufWritePre,BufRead *.html :normal gg=G
autocmd BufWritePre,BufRead *.html setlocal nowrap
autocmd FileType javascript nnoremap <buffer> <localleader>c I//<esc>
autocmd FileType python nnoremap <buffer> <localleader>c I#cesc>
autocmd FileType html nnoremap <buffer> <localleader>c I<!--<esc>A--><esc>






"""""""""""""""" PYTHON Begin
set nocompatible
filetype off

set rtp+=~/.vim/bundle/vundle/
set rtp+=~/.vim
set rtp+=~/.vim/after

call vundle#rc()

" let Vundle manage Vundle
" required!
Bundle 'gmarik/vundle'

" The bundles you install will be listed here

filetype plugin indent on
"Bundle 'Lokaltog/powerline', {'rtp': 'powerline/bindings/vim/'}

" Powerline setup
set guifont=DejaVu\ Sans\ Mono\ for\ Powerline\ 9
set laststatus=2

" The rest of your config follows here
"""""""""""""""" python End

" Pathogen load
filetype off

set nocp
call pathogen#infect()
call pathogen#helptags()

filetype plugin indent on
syntax on

"pathogen.vim"""""""""""""""""""""""""""""""""""""""""""""""BEGIN
execute pathogen#infect()
syntax on
filetype plugin indent on
"pathogen.vim"""""""""""""""""""""""""""""""""""""""""""""""END


" Hilight excess line length in python
augroup vimrc_autocmds
    autocmd!
    " highlight characters past column 120
    autocmd FileType python highlight Excess ctermbg=DarkGrey guibg=Black
    autocmd FileType python match Excess /\%80v.*/
    autocmd FileType python set nowrap
augroup END


"
nnoremap <F9> :SCCompile<cr>
nnoremap <F10> :SCCompileRun<cr>


"set default folder
  if has("unix") 
        cd ~
    elseif has("win32") 
        if exists("$OS") && ($OS == "Windows_NT") 
            cd D:\cygwin64\home\joker_000\
        else 
            cd "C:/Users/renshaw family/Documents/Programs" 
        endif 
    endif 


