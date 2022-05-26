local set = vim.opt
set.termguicolors = true

require('lualine').setup {
 options = {
  theme = 'palenight'
 }
}

require('onedark').load()

-- vim.cmd[[
-- set background=dark
-- ]]

-- vim.g['everforest_better_preformance'] = 1
