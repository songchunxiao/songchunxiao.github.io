function! potion#running#PotionCompileAndRunFile()
    silent !clear
    execute "!" . g:potion_command . " " . bufname("%")
endfunction

function! potion#running#PotionShowBytecode()
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
