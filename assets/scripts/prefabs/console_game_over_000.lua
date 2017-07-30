message = {
	type = 'crimild::Group',
	nodes = {
		{
			filename = 'assets/models/console_processing_answer.fbx',
		},
	},
	components = {
		{
			type = 'purge::ConsoleMessage',
			timeout = 3.0,
			nextMessage = 'assets/scripts/prefabs/console_game_over_001.lua',
		},
	},
}
