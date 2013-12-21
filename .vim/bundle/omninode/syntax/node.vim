if exists("b:current_syntax")"{{{
    finish
endif"}}}


syntax keyword potionKeyword to times
syntax keyword potionKeyword loop times to while
syntax keyword potionKeyword if elsif else
syntax keyword potionKeyword class return
syntax keyword potionFunction print join string
syntax match potionComment "\v#.*$""{{{
syntax match potionOperator "\V*"
syntax match potionOperator "\V/"
syntax match potionOperator "\V+"
syntax match potionOperator "\V-"
syntax match potionOperator "\V?"
syntax match potionOperator "\v\="
syntax match potionOperator "\V*="
syntax match potionOperator "\V/="
syntax match potionOperator "\V+="
syntax match potionOperator "\V-="
syntax match potionNumber "\v\d+\.?\d*"
syntax match potionNumber "\v0x\x{1,8}"
syntax match potionNumber "\v\d+\.?\d*[Ee][+-]\d+"
syntax region potionString start=/\v"/ skip=/\v\\./ end=/\v"/"}}}


highlight link potionString String
highlight link potionNumber Number
highlight link potionOperator Operator
highlight link potionComment Comment
highlight link potionKeyword Keyword
highlight link potionFunction Function
let b:current_syntax = "potion"
