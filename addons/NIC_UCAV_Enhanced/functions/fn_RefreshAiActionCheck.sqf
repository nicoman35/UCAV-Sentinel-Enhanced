/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_RefreshAiActionCheck
	Version: 		1.0
	Edited Date: 	15.04.2021
	
	Description:
		Checks, if action 'Refresh AI' is available
	
	Parameters:
		_UAV:	Object - player 
	
	Returns:
		bool
*/

params [["_UAV", objNull]];
if (isNull _UAV) exitWith {};
if (UAVControl _UAV select 0 == player) exitWith {true};
if (_UAV == cursorObject && _UAV distance player < 50) exitWith {true};
false
