message = {
	type = 'crimild::Group',
	nodes = {
		{
			filename = 'assets/models/console_welcome.fbx',
		},
		{
			filename = 'assets/models/console_start.fbx',
		},
	},
	components = {
		{
			type = 'purge::ConsoleMessage',
			nextMessage = 'assets/scripts/prefabs/console_status.lua',
			waitForInput = true,
		},
	},
}

