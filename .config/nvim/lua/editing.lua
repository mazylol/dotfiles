vim.g['python_recommended_style'] = 0
vim.g['rust_recommended_style'] = 0
vim.g['lua_recommended_style'] = 0

vim.g['neoformat_try_node_exe'] = 1
vim.cmd[[
  autocmd BufWritePre *.tsx Neoformat
  autocmd InsertLeave *.{vue,js,ts,jsx,tsx} Neoformat
]]

local set = vim.opt
set.tabstop = 2
set.expandtab = true
set.shiftwidth = 2
set.number = true
