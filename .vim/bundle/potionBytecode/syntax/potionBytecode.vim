if exists("b:potionBytecode_syntax") "{{{
    finish
endif "}}}


"syntax keyword potionKeyword to times
"syntax keyword potionFunction print join string

highlight link potionKeyword Keyword
highlight link potionFunction Function


syntax match pbBracketNumber "\v\[[0-9 ]*\]"
syntax match pbLabel "\v^--.*--$"

highlight link pbBracketNumber String
highlight link pbLabel Label

let b:current_syntax = "potionBytecode"
