#include "stdafx.h"
#include "game_sv_freemp.h"
#include "ai_space.h"
#include "../../../xrScripts/script_engine.h"
#include "inventory_item.h"
#include "Level.h"


void game_sv_freemp::OnPlayerRepairItem(NET_Packet& P, ClientID const& clientID)
{
	game_PlayerState* ps = get_id(clientID);
	if (!ps) return;

	u16 itemId = P.r_u16();
	s32 cost = P.r_s32();

	PIItem item = smart_cast<CInventoryItem*>(Level().Objects.net_Find(itemId));
	if (!item) return;

	if (ps->money_for_round < cost) return;

	AddMoneyToPlayer(ps, -cost);

	NET_Packet NP;
	CGameObject::u_EventGen(NP, GE_REPAIR_ITEM, itemId);
	CGameObject::u_EventSend(NP);

	GenerateGameMessage(NP);
	NP.w_u32(GAME_EVENT_MP_REPAIR_SUCCESS);
	NP.w_u16(itemId);
	m_server->SendTo(clientID, NP);
}