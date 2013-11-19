syntax on
set shiftwidth=4
set expandtab
set tabstop=4
set smartindent
set autoindent
set number
map <F5> : !python %<CR>

"""""""""""""""" python Begin
set nocompatible
filetype off

set rtp+=~/.vim/bundle/vundle/
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
nmap <F9> :SCCompile<cr>
nmap <F10> :SCCompileRun<cr>
map gc I//
colorscheme darkblue
map [5~ dd
echo "Jie's vIM >^.^<"
