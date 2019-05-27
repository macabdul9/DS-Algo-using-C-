set nocompatible
set shell=/bin/bash
syntax on
filetype off
set rtp+=~/.vim/bundle/Vundle.vim/
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
call vundle#end()
filetype plugin indent on


" encoding dectection
set fileencodings=utf-8,gb2312,gb18030,gbk,ucs-bom,cp936,latin1

" enable filetype dectection and ft specific plugin/indent
filetype plugin indent on

" enable syntax hightlight and completion
syntax on

" Vim UI
"--------
" color scheme
syntax enable
set background=dark
" colorscheme solarized

"set background=dark
"colorscheme molokai

" highlight current line
au WinLeave * set nocursorline nocursorcolumn
au WinEnter * set cursorline cursorcolumn
set cursorline cursorcolumn

Plugin 'terryma/vim-multiple-cursors'
Plugin 'tpope/vim-eunuch'

" search
set incsearch
"set highlight 	                                                  " conflict with highlight current line
set ignorecase
set smartcase

" editor settings
set history=1000
set nocompatible
set nofoldenable                                                  " disable folding"
set confirm                                                       " prompt when existing from an unsaved file
set backspace=indent,eol,start                                    " More powerful backspacing
set t_Co=256                                                      " Explicitly tell vim that the terminal has 256 colors "
set mouse=a                                                       " use mouse in all modes
set report=0                                                      " always report number of lines changed                "
set nowrap                                                        " dont wrap lines
set scrolloff=5                                                   " 5 lines above/below cursor when scrolling
set number                                                        " show line numbers
set relativenumber                                                " show relativenumber
set showmatch                                                     " show matching bracket (briefly jump)
set showcmd                                                       " show typed command in status bar
set title                                                         " show file in titlebar
set laststatus=2                                                  " use 2 lines for the status bar
set matchtime=2                                                   " show matching bracket for 0.2 seconds
set directory=~/.vim/tmp                                          " move swp file to /tmp

" Default Indentation
set autoindent
set expandtab       " expand tab to space
set smartindent     " indent when
set tabstop=4       " tab width
set softtabstop=4   " number of spaces in tab when editing
set shiftwidth=8    " indent width
" set textwidth=79
" set smarttab      " insert tabs on the start of a line according to shiftwidth, not tabstop

"https://dougblack.io/words/a-good-vimrc.html#spaces
set cursorline          " highlight current line

autocmd FileType python setlocal tabstop=4 shiftwidth=4 softtabstop=4 textwidth=120

" syntax support

"-----------------
" Plugin settings
"-----------------
" Rainbow parentheses for Lisp and variants
let g:rbpt_colorpairs = [
    \ ['brown',       'RoyalBlue3'],
    \ ['Darkblue',    'SeaGreen3'],
    \ ['darkgray',    'DarkOrchid3'],
    \ ['darkgreen',   'firebrick3'],
    \ ['darkcyan',    'RoyalBlue3'],
    \ ['darkred',     'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['brown',       'firebrick3'],
    \ ['gray',        'RoyalBlue3'],
    \ ['black',       'SeaGreen3'],
    \ ['darkmagenta', 'DarkOrchid3'],
    \ ['Darkblue',    'firebrick3'],
    \ ['darkgreen',   'RoyalBlue3'],
    \ ['darkcyan',    'SeaGreen3'],
    \ ['darkred',     'DarkOrchid3'],
    \ ['white',         'firebrick3'],
    \ ]
let g:rbpt_max = 16
autocmd Syntax lisp,scheme,clojure,racket RainbowParenthesesToggle

" tabbar
let g:Tb_MaxSize = 2
let g:Tb_TabWrap = 1

hi Tb_Normal guifg=white ctermfg=white
hi Tb_Changed guifg=green ctermfg=green
hi Tb_VisibleNormal ctermbg=252 ctermfg=235
hi Tb_VisibleChanged guifg=green ctermbg=252 ctermfg=white

" easy-motion
let g:EasyMotion_leader_key = '<Leader>'

" Tagbar
let g:tagbar_left=1
let g:tagbar_width=30
let g:tagbar_autofocus = 1
let g:tagbar_sort = 0
let g:tagbar_compact = 1
" tag for markdown
let g:tagbar_type_markdown = {
	\ 'ctagstype' : 'markdown',
	\ 'kinds' : [
		\ 'h:Heading_L1',
		\ 'i:Heading_L2',
		\ 'k:Heading_L3'
	\ ]
\ }

" Nerd Tree
 let NERDChristmasTree=0
 let NERDTreeWinSize=30
 let NERDTreeChDirMode=2
 let NERDTreeIgnore=['\~$', '\.pyc$', '\.swp$']
 let NERDTreeSortOrder=['^__\.py$', '\/$', '*', '\.swp$',  '\~$']
 let NERDTreeShowBookmarks=1
let NERDTreeWinPos = "left"

"nerdcommenter
let NERDSpaceDelims=1
 nmap <D-/> :NERDComToggleComment<cr>
let NERDCompactSexyComs=1

Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'scrooloose/nerdtree'

Plugin 'vim-syntastic/syntastic'

"let g:tmpl_search_paths = ['~/templates']"
Plugin 'tibabit/vim-templates'

Plugin 'altercation/vim-colors-solarized'

" Plugin for github integeration
Plugin 'tpope/vim-fugitive'

Plugin 'Valloric/YouCompleteMe'

" bracket completion
Plugin 'jiangmiao/auto-pairs'


" color scheme plugin aka theme

Plugin 'arcticicestudio/nord-vim'
colorscheme nord




" powerline::
"let g:Powerline_symbols = 'fancy'
set directory=~/.vim/tmp
set directory=~/.vim-swap/
set directory=.,$TEMP

"auto identation for python
Plugin 'vim-scripts/indentpython.vim'
Plugin 'nvie/vim-flake8'
let python_highlight_all=1
syntax on
Plugin 'jnurmine/Zenburn'
"Plugin 'altercation/vim-colors-solarized'


"python identation
"au BufNewFile,BufRead *.py
"    set tabstop=4
"    set softtabstop=4
"    set shiftwidth=4
"    set textwidth=79
"    set expandtab
"    set autoindent
"    set fileformat=unix
"python with virtualenv support



" SuperTab
" let g:SuperTabDefultCompletionType='context'
let g:SuperTabDefaultCompletionType = '<C-X><C-U>'
let g:SuperTabRetainCompletionType=2

" ctrlp
set wildignore+=*/tmp/*,*.so,*.o,*.a,*.obj,*.swp,*.zip,*.pyc,*.pyo,*.class,.DS_Store  " MacOSX/Linux
let g:ctrlp_custom_ignore = '\.git$\|\.hg$\|\.svn$'

" Keybindings for plugin toggle
nnoremap <F2> :set invpaste paste?<CR>
set pastetoggle=<F2>
nmap <F5> :TagbarToggle<cr>
nmap <F6> :NERDTreeToggle<cr>
nmap <F3> :GundoToggle<cr>
nmap <F4> :IndentGuidesToggle<cr>
nmap  <D-/> :
nnoremap <leader>a :Ack
nnoremap <leader>v V`]

" Useful Functions
"------------------
" easier navigation between split windows
nnoremap <c-j> <c-w>j
nnoremap <c-k> <c-w>k
nnoremap <c-h> <c-w>h
nnoremap <c-l> <c-w>l

" When editing a file, always jump to the last cursor position
autocmd BufReadPost *
      \ if ! exists("g:leave_my_cursor_position_alone") |
      \     if line("'\"") > 0 && line ("'\"") <= line("$") |
      \         exe "normal g'\"" |
      \     endif |
      \ endif

" w!! to sudo & write a file
cmap w!! %!sudo tee >/dev/null %

" Quickly edit/reload the vimrc file
nmap <silent> <leader>ev :e $MYVIMRC<CR>
nmap <silent> <leader>sv :so $MYVIMRC<CR>

" sublime key bindings
nmap <D-]> >>
nmap <D-[> <<
vmap <D-[> <gv
vmap <D-]> >gv

" eggcache vim
nnoremap ; :
:command W w
:command WQ wq
:command Wq wq
:command Q q
:command Qa qa
:command QA qa

" c++ compiler
autocmd filetype cpp nnoremap <C-c> :w <bar> !clear && g++ -std=gnu++14 -O2 % -o %:p:h/%:t:r.exe && ./%:r.exe<CR>
autocmd filetype c nnoremap <C-c> :w <bar> !gcc -std=c99 -lm % -o %:p:h/%:t:r.out && ./%:r.out<CR>     
autocmd filetype java nnoremap <C-c> :w <bar> !javac % && java -enableassertions %:p <CR>
autocmd filetype python nnoremap <C-c> :w <bar> !python % <CR>
autocmd filetype perl nnoremap <C-c> :w <bar> !perl % <CR>
autocmd filetype go nnoremap <C-c> :w <bar> !go build % && ./%:p <CR>
" this shit is for cpp temp
" autocmd BufNewFile *.cpp 0r ~/.vim/templates/cppmain.template

" Vim color file
" Maintainer:	Michael Piefel <piefel@informatik.hu-berlin.de>
" Last Change:	2001 Aug 16
" Licence:	Public Domain

" This color scheme uses a White background. It's based on Bram's
" morning theme, but doesn't try to work for non-GUI editing.
" 
" It's supposed to look like the Emacs standard colors, at least
" for C. But Emacs has different categories, so it's not very good.

" First remove all existing highlighting.
set background = "Light"
hi clear
if exists("syntax_on")
  syntax reset
endif

" let colors_name = "emacs"

" hi Normal guifg=Black guibg=White

" Groups used in the 'highlight' and 'guicursor' options default value.
hi ErrorMsg guibg=Red guifg=White
hi IncSearch gui=reverse
hi ModeMsg gui=bold
hi StatusLine gui=reverse,bold
hi StatusLineNC gui=reverse
hi VertSplit gui=reverse
hi Visual gui=reverse guifg=Grey guibg=fg
hi VisualNOS gui=underline,bold
hi DiffText gui=bold guibg=Red
hi Cursor guibg=Black guifg=NONE
hi lCursor guibg=Cyan guifg=NONE
hi Directory guifg=Blue
hi LineNr guifg=Brown
hi MoreMsg gui=bold guifg=SeaGreen
hi NonText gui=bold guifg=Blue guibg=grey90
hi Question gui=bold guifg=SeaGreen
hi Search guibg=Yellow guifg=NONE
hi SpecialKey guifg=Blue
hi Title gui=bold guifg=Magenta
hi WarningMsg guifg=Red
hi WildMenu guibg=Yellow guifg=Black
hi Folded guibg=White guifg=DarkBlue
hi FoldColumn guibg=Grey guifg=DarkBlue
hi DiffAdd guibg=LightBlue
hi DiffChange guibg=LightMagenta
hi DiffDelete gui=bold guifg=Blue guibg=LightCyan

" Colors for syntax highlighting
hi Comment guifg=#AC2020 guibg=White
hi Constant guifg=#C28F8F guibg=White
hi PreProc guifg=#D569D5 guibg=White
hi Statement gui=NONE guifg=#9C20EE guibg=White
hi Type guifg=#9C20EE guibg=White
hi Special guifg=SlateBlue guibg=White
hi Ignore guifg=White

" Some specials (override hilinks)

set autowrite
nnoremap <C-c> :!g++ -std=c++11 % -Wall -g -o %.out && ./%.out<CR>


" vim: sw=2
