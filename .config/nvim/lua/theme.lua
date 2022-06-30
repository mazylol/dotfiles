local catppuccin = require("catppuccin")

local set = vim.opt

require('lualine').setup {
 options = {
  theme = 'sonokai'
 }
}

catppuccin.setup()
