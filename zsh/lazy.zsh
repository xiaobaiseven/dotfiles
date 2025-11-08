function lazygit_widget(){
	lazygit
	zle reset-prompt
}

zle -N lazygit_widget
bindkey '^g' lazygit_widget
