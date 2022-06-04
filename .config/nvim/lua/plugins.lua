return require('packer').startup(function()
 -- theme
 use {
  'nvim-lualine/lualine.nvim',
  requires = { 'kyazdani42/nvim-web-devicons', opt = true }
 }
 use 'andweeb/presence.nvim'
 use 'mhinz/vim-startify'
 use 'morhetz/gruvbox'
 use 'sainnhe/everforest'
 use 'navarasu/onedark.nvim'
 use 'carakan/new-railscasts-theme'
 use 'sainnhe/sonokai'
 
 -- syntax
 use 'sheerun/vim-polyglot'
 use 'sbdchd/neoformat'

 --git
 use 'tpope/vim-fugitive'
 use 'airblade/vim-gitgutter'
 
 --editing
 use 'jiangmiao/auto-pairs'
 use 'Yggdroot/indentLine'
 use 'tpope/vim-commentary'
 use 'haya14busa/incsearch.vim'
 use 'junegunn/fzf.vim'

 -- performance
 use 'lewis6991/impatient.nvim'
 use {
  'folke/trouble.nvim',
	config = function()
	 require("trouble").setup {

	 }
	end
 }

 --management
 use 'wbthomason/packer.nvim'
end)
