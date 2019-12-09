/****************************************************************************************
* Copyright (C) 2018-2019, Jovibor: https://github.com/jovibor/                         *
* This is a Hex Control for MFC/Win32 applications.                                     *
* Official git repository: https://github.com/jovibor/HexCtrl/                          *
* This software is available under the "MIT License modified with The Commons Clause".  *
* https://github.com/jovibor/HexCtrl/blob/master/LICENSE                                *
* For more information visit the project's official repository.                         *
****************************************************************************************/
#pragma once
#include "CHexCtrl.h"
#include <vector>
#include <ctime>

namespace HEXCTRL::INTERNAL
{
	class CHexBookmarks
	{
	public:
		CHexBookmarks() {}
		DWORD Add(const HEXBOOKMARKSTRUCT& stBookmark); //Returns new bookmark Id.
		void Attach(CHexCtrl* pHex);
		void ClearAll();
		auto GetBookmark(DWORD dwID)->HEXBOOKMARKSTRUCT*;
		auto GetTouchTime()const->std::time_t;
		auto GetVector()->std::deque<HEXBOOKMARKSTRUCT>&;
		void GoBookmark(DWORD nID);
		void GoNext();
		void GoPrev();
		bool HasBookmarks()const;
		auto HitTest(ULONGLONG ullOffset)->HEXBOOKMARKSTRUCT*;
		bool IsVirtual();
		void Remove(ULONGLONG ullOffset);
		void RemoveId(DWORD dwID);
		void SetVirtual(IHexBkmVirtual* pVirtual);
		void Update(DWORD dwID, const HEXBOOKMARKSTRUCT& stBookmark);
	private:
		std::deque<HEXBOOKMARKSTRUCT> m_deqBookmarks;
		CHexCtrl* m_pHex { };
		IHexBkmVirtual* m_pVirtual { };
		int m_iCurrent { };
		std::time_t m_time { }; //Last modification time.
	};
}