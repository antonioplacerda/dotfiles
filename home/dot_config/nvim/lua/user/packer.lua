vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
	-- Packer can manage itself
	use 'wbthomason/packer.nvim'

	use {
		'nvim-telescope/telescope.nvim', tag = '0.1.1',
		requires = { { 'nvim-lua/plenary.nvim' } }
	}

	use('nvim-treesitter/nvim-treesitter', { run = ':TSUpdate' })

	use { "briones-gabriel/darcula-solid.nvim", requires = "rktjmp/lush.nvim" }

	use('mbbill/undotree')
	use('tpope/vim-fugitive')
	use('lukas-reineke/indent-blankline.nvim') -- Add indentation guides even on blank lines
	use('numToStr/Comment.nvim')            -- "gc" to comment visual regions/lines use 'tpope/vim-sleuth'

	use {
		'VonHeikemen/lsp-zero.nvim',
		branch = 'v2.x',
		requires = {
			-- LSP Support
			{ 'neovim/nvim-lspconfig' }, -- Required
			{
				-- Optional
				'williamboman/mason.nvim',
				run = function()
					pcall(vim.cmd, 'MasonUpdate')
				end,
			},
			{ 'williamboman/mason-lspconfig.nvim' }, -- Optional

			-- Autocompletion
			{ 'hrsh7th/nvim-cmp' }, -- Required
			{ 'hrsh7th/cmp-nvim-lsp' }, -- Required
			{ 'L3MON4D3/LuaSnip' }, -- Required
		}
	}

	use('lewis6991/gitsigns.nvim')
	use({
		"iamcco/markdown-preview.nvim",
		run = function() vim.fn["mkdp#util#install"]() end,
	})

	-- should explore this one
	use('ray-x/go.nvim')
end)
