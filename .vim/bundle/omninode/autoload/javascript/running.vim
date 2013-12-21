function! javascript#running#nodeCompileAndRunFile()
    silent !clear
    execute "!" . g:node_command . " " . bufname("%")
endfunction

function! javascript#running#nodeShowBytecode()
    " Get the bytecode.
    let bytecode = system(g:potion_command . " -c -V " . bufname("%") . " 2>&1")
    silent! let l:bufEx =  bufwinnr("__Potion_Bytecode__")
    if l:bufEx != -1
        buffer __Potion_Bytecode__
    else
        vsplit __Potion_Bytecode__
    endif

    normal! ggdG
    setlocal filetype=potionBytecode
    setlocal buftype=nofile

    " Insert the bytecode.
    call append(0, split(bytecode, '\v\n'))
endfunction
