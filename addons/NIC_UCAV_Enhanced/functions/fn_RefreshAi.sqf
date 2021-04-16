/*
	Author: 		Nicoman
	Function: 		NIC_EUAV_fnc_RefreshAi
	Version: 		1.0
	Edited Date: 	15.04.2021
	
	Description:
		Deletes old AI crew of an UAV, then creates a new one. Reconnects player and reassigns old role.
		Intention: 	Sometimes, UAVs get unresponsive to commands, fly away on their own, do things
					not commanded to do, etc. By replacing the UAV crew with a new one, hopefully
					things get corrected and the UAV gets responsive again.
	
	Parameters:
		_UAV:		Object - UAV 
		
	Returns:
		None
*/

params [["_UAV", objNull]];
if (isNull _UAV) exitWith {};
private _connectedPlayer = UAVControl _UAV select 0;
private _role = UAVControl _UAV select 1;
_connectedPlayer connectTerminalToUAV objNull;
{_UAV deleteVehicleCrew _x} forEach crew _UAV;
sleep 0.1;
createVehicleCrew _UAV;
(group ((crew _UAV) select 0)) setBehaviour "SAFE";
if !(isNull _connectedPlayer) then {
	_connectedPlayer connectTerminalToUAV _UAV;
	if (_role == "Driver") exitWith {_connectedPlayer action ["SwitchToUAVDriver", _UAV]};
	if (_role == "Gunner") then {_connectedPlayer action ["SwitchToUAVGunner", _UAV]};
};
