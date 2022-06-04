local set = vim.opt
set.termguicolors = true

require('lualine').setup {
 options = {
  theme = 'sonokai'
 }
}

vim.g['sonokai_better_performance'] = 1

vim.cmd[[
colorscheme sonokai
]]
