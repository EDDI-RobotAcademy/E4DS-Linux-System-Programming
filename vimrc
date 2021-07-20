set tags=/root/compiler/gcc-4.5.0/tags
set smartindent
set tabstop=4
set shiftwidth=4
if version >= 500
	func! Sts()
		let st = expand("<cword>")
		exe "sts ".st
	endfunc
	nmap ,st :call Sts()<cr>
	func! Tj()
		let st = expand("<cword>")
		exe "tj ".st
	endfunc
	nmap ,tj :call Tj()<cr>
endif
set csprg=/usr/bin/cscope
set nocsverb
cs add /root/compiler/gcc-4.5.0/cscope.out
set csto=0
set cst
func! Css()
	let css = expand("<cword>")
	new
	exe "cs find s ".css
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,css :call Css()<cr>
func! Csc()
	let csc = expand("<cword>")
	new
	exe "cs find c ".csc
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,csc :call Csc()<cr>
func! Csd()
	let csd = expand("<cword>")
	new
	exe "cs find d ".csd
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,csd :call Csd()<cr>
func! Csg()
	let csg = expand("<cword>")
	new
	exe "cs find g ".csg
	if getline(1) == ""
		exe "q!"
	endif
endfunc
nmap ,csg :call Csg()<cr>
