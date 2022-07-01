#pragma once

class CBlender_scope_view : public IBlender
{
public:
	virtual LPCSTR getComment() { return "scope_view"; }
	virtual BOOL canBeDetailed() { return FALSE; }
	virtual BOOL canBeLMAPped() { return FALSE; }

	virtual void Compile(CBlender_Compile& C);

	CBlender_scope_view();
	virtual ~CBlender_scope_view() = default;
};
