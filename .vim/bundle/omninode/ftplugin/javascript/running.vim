if !exists("g:node_command")
    let g:node_command = "node"
endif

nnoremap <buffer> <localleader>r
            \ :call javascript#running#nodeCompileAndRunFile()<cr>

nnoremap <buffer> <localleader>b
            \ :call javascript#running#nodeShowBytecode()<cr>
