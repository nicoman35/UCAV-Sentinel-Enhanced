/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_AddAiRefreshAction
	Version: 		1.0
	Edited Date: 	15.04.2021
	
	Description:
		Add 'Refresh UAV AI' action to this UAV
		
	Parameters:
		_UAV:		Object - UAV 
		
	Returns:
		None
*/

params [["_UAV", objNull]];
if (isNull _UAV) exitWith {};
if (isNil{_UAV getVariable "EUAV_ActionID_RefreshAi"}) then {				// add Refresh AI action to uav
	private _actionID = _UAV addAction [
		"Refresh AI",														// Title
		{_this select 0 call NIC_EUAV_fnc_RefreshAi},						// Script
		nil,																// Arguments
		0,																	// Priority
		false,																// showWindow
		true,																// hideOnUse
		"",																	// Shortcut
		"[_target] call NIC_EUAV_fnc_RefreshAiActionCheck"					// Condition
	];
	_UAV setVariable ["EUAV_ActionID_RefreshAi", _actionID];
};