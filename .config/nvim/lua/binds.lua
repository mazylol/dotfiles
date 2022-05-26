-- vim.cmd[[
-- nnoremap <C-f> :FZF<CR>
-- ]]

function map(mode, lhs, rhs, opts)
  local options = { noremap = true }
  if opts then
    options = vim.tbl_extend("force", options, opts)
  end
  vim.api.nvim_set_keymap(mode, lhs, rhs, options)
end

map("n", "<C-f>", ":FZF<CR>", { silent = true })
map("n", "<C-n>", ":Neoformat<CR>", { silent = true })
