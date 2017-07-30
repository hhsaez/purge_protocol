function createTestMessage( id )
	return {
		filename = 'assets/models/console_test_' .. id .. '.fbx',
		components = {
			{
				type = 'purge::ConsoleMessage',
				nextMessage = 'assets/scripts/prefabs/console_test_' .. id .. '_processing.lua',
				waitForInput = true,
			},
		},
	}
end

function createProcessingMessage( id, eventName )
	return {
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
				nextMessage = 'assets/scripts/prefabs/console_test_' .. id .. '_result.lua',
				event = eventName,
			},
		},
	}
end

function createTestResultsMessage( id, nextMessageId )
	local nextMessageFileName = ''
	if nextMessageId == nil then
		nextMessageFileName = 'assets/scripts/prefabs/console_ending_001.lua'
	else
		nextMessageFileName = 'assets/scripts/prefabs/console_test_' .. nextMessageId .. '.lua'
	end
	
	return {
		type = 'crimild::Group',
		nodes = {
			{
				filename = 'assets/models/console_ship.fbx',
			},
			{
				filename = 'assets/models/console_test_' .. id .. '_result.fbx',
			},
		},
		components = {
			{
				type = 'purge::ConsoleMessage',
				timeout = 5.0,
				nextMessage = nextMessageFileName,
			},
		},
	}
end

