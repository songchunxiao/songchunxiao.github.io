"Created by Jie Feng, feel free to use
let mapleader = ","
let maplocalleader = "\\"
syntax on

"---------------------------- omnicompletion BEGIN
filetype plugin on
set omnifunc=syntaxcomplete#Complete
"---------------------------- omnicompletion END


"highlight errors 
"---------------------------- {{{
nnoremap <leader>w :match Error /\v +$/<cr>
nnoremap <leader>W :match none<cr>
"}}}
"editing set
"---------------------------- {{{
set foldlevel=0
set shiftwidth=4
set expandtab
set tabstop=4
set smartindent
set autoindent
set number
set hlsearch incsearch
"}}}

"colorscheme murphy

nnoremap / /\v
nnoremap <leader>/ :nohlsearch<cr>
nnoremap <localleader>h :set hlsearch!<cr>
"edit .vimrc and plugins
"---------------------------- {{{
nnoremap <localleader>ev :tabedit $MYVIMRC<cr>
nnoremap <localleader>sv :source $MYVIMRC<cr>
nnoremap <localleader>s% :source %<cr>
"}}}

"statusline
"---------------------------- {{{
"set statusline=%F          fullpath
"set statusline=%.20F       change the maximum width
set statusline=%f         " Path to the file
set statusline+=\ -\      " Separator
set statusline+=FileType: " Label
set statusline+=%y        " Filetype of the file
set statusline+=%4l   " Current line
"set statusline=%04l
"set statusline=%-4l
set statusline+=/    " Separator
set statusline+=%L   " Total lines
"}}}

"abbreviations
"---------------------------- {{{
iabbrev "- "----------------------------
"---------------------------- Email, website, signature
iabbrev mysig -- <cr>Jie Feng<cr>jokerfeng2010@gmai.com
"}}}

"excuting
"---------------------------- {{{
"noremap <F5> : w | make
"noremap <F6> : !./a < in
"}}}

"normal mode mappings
"---------------------------- {{{
"---------------------------- select a word
noremap <localleader><space> viw
"---------------------------- no further mapping
nnoremap - dd
"nnoremap <c-u> viwUw
nnoremap <leader>" viw<esc>a"<esc>hbi"<esc>lel
nnoremap L $
nnoremap H 0 
"}}}

"---------------------------- noremap, nnoremap, vnoremap, inoremap
"---------------------------- n non recursive map
"insert mode mappings
"---------------------------- {{{
"inoremap <c-d> <esc>ddi
inoremap <c-u> <esc>lviwUwi
"}}}

"visual mode mappings
"---------------------------- {{{
vnoremap " <esc>`<i"<esc>`>a"<esc>
"}}}

"operator-pending mappings
"---------------------------- {{{
onoremap b /return<cr>
"---------------------------- Operator-Pending Mappings (operators and movements)

onoremap in( :<c-u>normal! f(vi(<cr>
onoremap il( :<c-u>normal! F)vi(<cr>
onoremap ie :<c-u>execute "normal! 
    \/[a-zA-Z0-9._]\\+@[a-zA-Z0-9._]\\+\\.[a-zA-Z]\\{2,3}\rv/@\rE"<cr>
"}}}
"open window-buffer mappings
" ---------------------------- {{{
nnoremap <localleader>pb :execute "rightbelow vsplit  " . bufname("#")  <cr>
"}}}
"grep
"---------------------------- {{{
nnoremap <leader>n :cnext<cr>
nnoremap <leader>p :cprevious<cr>
"}}}

" fengjie


"---------------------------- disable key :inoremap <esc> <nop>
"autocmd BufNewFile * :write
"autocmd BufWritePre,BufRead *.html :normal gg=G
"autocmd BufWritePost .vimrc :source ~/.vimrc
"FileType specific settings
"---------------------------- {{{
augroup text
    autocmd!
    autocmd FileType text onoremap <buffer> ih :<c-u>execute "normal! ?^==\\+$\r:nohlsearch\rkvg_"<cr>
    autocmd FileType text onoremap <buffer> ah :<c-u>execute "normal! ?^==\\+$\r:nohlsearch\rg_vk0"<cr>
augroup END

augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END

augroup testgroup
    autocmd!
    autocmd BufWrite * :echom "Baz"
augroup END


augroup filetype_javascript
    autocmd!
    autocmd FileType javascript nnoremap <buffer> <localleader>c I//<esc>
    autocmd FileType javascript :iabbrev <buffer> iff if ()<left>
augroup END

augroup filetype_python
    autocmd!
    autocmd FileType python set statusline=%f-%y-[%l]/[%L]
    autocmd FileType python nnoremap <buffer> <localleader>c I#cesc>
    autocmd FileType python :iabbrev <buffer> iff if:<left>
augroup END

augroup filetype_html
    autocmd!
    autocmd BufWritePre,BufRead *.html setlocal nowrap
    autocmd FileType html nnoremap <buffer> <localleader>c I<!--<esc>A--><esc>
    autocmd FileType html iabbrev <buffer> --- &mdash;
    autocmd FileType html iabbrev <buffer> `` &ldquo;
    autocmd FileType html iabbrev <buffer> '' &rdquo;
    autocmd FileType html nnoremap <buffer> <localleader>f Vatzf
augroup END
"}}}






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
            cd "~" 
        endif 
    endif 
