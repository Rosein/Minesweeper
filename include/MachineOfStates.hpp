#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Minesweeper
{
	typedef std::unique_ptr<State> StateRef;

	class MachineOfStates
	{
	public:
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		// Run at start of each loop in Game.cpp
		void ProcessStateChanges();

		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}