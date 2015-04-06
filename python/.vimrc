au BufEnter /home/fog/LIVA/kernel/* set tags =/home/fog/LIVA/kernel/tags
au BufEnter /home/fog/LIVA/kernel/* set path^=/home/fog/LIVA/kernel/include
au BufEnter /home/fog/LIVA/bootable/bootloader/lk/*  set tags=/home/fog/LIVA/bootable/bootable/lk/tags
au BufEnter /home/fog/LIVA/bootable/bootloader/lk/*  set path^=/home/fog/LIVA/bootable/bootable/lk/dev/gcdb/display
au vimEnter /home/fog/LIVA/kernel/* cs add /home/fog/LIVA/kernel/cscope.out /home/fog/LIVA/kernel
au BufEnter /home/fog/Q39/kernel/* set tags =/home/fog/Q39/kernel/tags
au BufEnter /home/fog/Q39/kernel/* set path^=/home/fog/Q39/kernel/include
au BufEnter /home/fog/Q39/bootable/bootloader/lk/*  set tags =/home/fog/Q39/bootable/bootloader/lk/tags
au BufEnter /home/fog/Q39/bootable/bootloader/lk/*  set path^=/home/fog/Q39/bootable/bootloader/lk/dev/gcdb/display

au BufEnter /home/fog/Q39/Non-HLOS/boot_images/* set tags =/home/fog/Q39/Non-HLOS/boot_images/tags
au vimEnter /home/fog/Q39/Non-HLOS/boot_images/* cs add /home/fog/Q39/Non-HLOS/boot_images/cscope.out /home/fog/Q39/Non-HLOS/boot_images
au BufEnter /home/fog/Q39/vendor/* set tags =/home/fog/Q39/vendor/tags
au vimEnter /home/fog/Q39/kernel/* cs add /home/fog/Q39/kernel/cscope.out /home/fog/Q39/kernel

au BufEnter /home/fog/D801/kernel/* set tags=/home/fog/D801/kernel/tags
au BufEnter /home/fog/D801/kernel/* set path^=/home/fog/D801/kernel/include
au BufEnter /home/fog/D801/bootable/bootloader/lk/*  set tags=/home/fog/D801/bootable/bootloader/lk/tags
au BufEnter /home/fog/D801/bootable/bootloader/lk/*  set path^=/home/fog/D801/bootable/bootloader/lk/dev/gcdb/display

:set number
let &termencoding=&encoding
set fileencodings=utf-8,gbk,ucs-bom,cp936,chinese
syntax on "开启语法高亮(需要安装vim-full)
set linebreak 
set textwidth=80
set nocompatible
set history=50
set ruler
set number
set hlsearch
set noincsearch
"set expandtab
set noerrorbells
set novisualbell
set vb t_vb= 
"set showmatch
set nocompatible
"close visual bell
set foldmethod=marker
set incsearch
set tabstop=8
set shiftwidth=8
set nobackup
set nowritebackup
"set noswapfile
"set smarttab
set smartindent
set autoindent
"set noautoindent
"设置在粘贴的时候不自动缩进
"set paste  
"set cursorline 
set cindent
set wrap
set autoread
"set mouse=a 
"set the height of command line
set cmdheight=1
"set showtabline=2
"set clipboard+=unnamed
set tabpagemax=20
set laststatus=2
set csprg=/usr/bin/cscope
let Tlist_Ctags_Cmd='/usr/bin/ctags'
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Right_Window=1
let Tlist_Auto_Open=0
au VimLeave * wviminfo! ~/viminfo
au VimEnter * rviminfo  ~/viminfo
nmap <C-@>d :scs find d <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>c :scs find c <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>s :scs find s <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>g :scs find g <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>t :scs find t <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>e :scs find e <C-R>=expand("<cword>")<CR><CR>	
nmap <C-@>f :scs find f <C-R>=expand("<cfile>")<CR><CR>	
nmap <C-@>i :scs find i ^<C-R>=expand("<cfile>")<CR>$<CR>	
