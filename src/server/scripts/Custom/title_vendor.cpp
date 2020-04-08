/*
<--------------------------------------------------------------------------->
 - Developer(s): Ghostcrawler336
 - Updated 2017: beimax76
 - Complete: 100%
 - ScriptName: 'Title System' 
 <--------------------------------------------------------------------------->*/
 
#include "ScriptPCH.h"

#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "GossipDef.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "QueryResult.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>

enum eRanks
{
	  /* Alliance */
	PRIVATE = 1,
	CORPORAL = 2,
	SERGEANT = 3,
	MASTER_SERGEANT = 4,
	SERGEANT_MAJOR = 5,
	KNIGHT = 6,
	KNIGHT_LIEUTENANT = 7,
	KNIGHT_CAPTAIN = 8,
	KNIGHT_CHAMPION = 9,
	LIEUTENANT_COMMANDER = 10,
	COMMANDER = 11,
	MARSHAL = 12,
	FIELD_MARSHAL = 13,
	GRAND_MARSHAL = 14,
	OF_THE_ALLIANCE = 126,
  /* Horde */
    SCOUT = 15,
	GRUNT = 16,
	SERGEANT_H = 17,
	SENIOR_SERGEANT = 18,
	FIRST_SERGEANT = 19,
	STONE_GUARD = 20,
	BLOOD_GUARD = 21,
	LEGIONNAIRE = 22,
	CENTURION = 23,
	CHAMPION = 24,
	LIEUTENANT_GENERAL = 25,
	GENERAL = 26,
	WARLORD = 27,
	HIGH_WARLORD = 28,
	OF_THE_HORDE = 127
};

enum  defines
{
 title_token = 190050, // title Token
 title_cost = 65
};

class Title_Npc : public CreatureScript
{
	public:
		Title_Npc() : CreatureScript("Title_Npc"){}
		
		class TitleAI : public ScriptedAI
		{
				
			public:
			
			TitleAI(Creature* creature) : ScriptedAI(creature) {}
			
			void CreatureWhisperBasedOnBool(const char *text, Creature *creature, Player *player, bool value)
				{
					if (value)
					creature->TextEmote(text, player);
				}
				
			bool GossipHello(Player* player) override
				{
						return OnGossipHello(player, me);
				}
				
			bool OnGossipHello(Player * player, Creature * creature)
			{
			
			
			   if (player->GetTeam() == ALLIANCE)
				{
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Private", GOSSIP_SENDER_MAIN, PRIVATE);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Corporal", GOSSIP_SENDER_MAIN, CORPORAL);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Sergeant", GOSSIP_SENDER_MAIN, SERGEANT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Master Sergeant", GOSSIP_SENDER_MAIN, MASTER_SERGEANT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Sergeant Major", GOSSIP_SENDER_MAIN, SERGEANT_MAJOR);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher Knight", GOSSIP_SENDER_MAIN, KNIGHT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Knight Lieutenant", GOSSIP_SENDER_MAIN, KNIGHT_LIEUTENANT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Knight Captain", GOSSIP_SENDER_MAIN, KNIGHT_CAPTAIN);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Knight Champion", GOSSIP_SENDER_MAIN, KNIGHT_CHAMPION);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Lieutenant Commander", GOSSIP_SENDER_MAIN, LIEUTENANT_COMMANDER);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Commander.", GOSSIP_SENDER_MAIN, COMMANDER);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Marshal", GOSSIP_SENDER_MAIN, MARSHAL);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Field Marshal", GOSSIP_SENDER_MAIN, FIELD_MARSHAL);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[65 Title Voucher] Grand Marshal", GOSSIP_SENDER_MAIN, GRAND_MARSHAL);
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Ability_Spy:35:35|tNevermind..", GOSSIP_SENDER_MAIN, 100);
					SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				}
				
				if (player->GetTeam() == HORDE)
				
				{
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Scout", GOSSIP_SENDER_MAIN, SCOUT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Grunt", GOSSIP_SENDER_MAIN, GRUNT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Sergeant", GOSSIP_SENDER_MAIN, SERGEANT_H);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Senior Sergeant", GOSSIP_SENDER_MAIN, SENIOR_SERGEANT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] First Sergeant", GOSSIP_SENDER_MAIN, FIRST_SERGEANT);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Stone Guard", GOSSIP_SENDER_MAIN, STONE_GUARD);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Blood Guard", GOSSIP_SENDER_MAIN, BLOOD_GUARD);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Legionnaire", GOSSIP_SENDER_MAIN, LEGIONNAIRE);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Centurion", GOSSIP_SENDER_MAIN,CENTURION);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Champion", GOSSIP_SENDER_MAIN, CHAMPION);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Lieutenant General", GOSSIP_SENDER_MAIN, LIEUTENANT_GENERAL);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] General", GOSSIP_SENDER_MAIN, GENERAL);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] Warlord", GOSSIP_SENDER_MAIN, WARLORD);
					AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface/ICONS/Inv_jewelry_frostwolftrinket_04:35:35|t[1 Title Voucher] High Warlord", GOSSIP_SENDER_MAIN, HIGH_WARLORD);
					AddGossipItemFor(player, GOSSIP_ICON_INTERACT_2, "|TInterface/ICONS/Ability_Spy:35:35|tNevermind..", GOSSIP_SENDER_MAIN, 100);
					SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
				}
			
				return true;

			}
			
			bool GossipSelect(Player* player, uint32 /*menu_id*/, uint32 gossipListId) override
			{
				uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
				uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
				return OnGossipSelect(player, me, sender, action);
			}
			
			bool OnGossipSelect(Player * player, Creature * creature, uint32 uiSender, uint32 uiAction)
			{
				if(uiSender == GOSSIP_SENDER_MAIN)
				{
					 switch (uiAction)
					{
						
						case PRIVATE:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(1);
								player->DestroyItemCount(title_token, title_cost, true);						
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;

						case CORPORAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(2);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case SERGEANT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(3);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case MASTER_SERGEANT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(4);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case SERGEANT_MAJOR:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(5);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case KNIGHT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(6);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case KNIGHT_LIEUTENANT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(7);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						
						break;
						case KNIGHT_CAPTAIN:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(8);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						break;
						case KNIGHT_CHAMPION:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(9);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
						    }
							
						break;
						case LIEUTENANT_COMMANDER:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(10);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						break;
						case COMMANDER:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(11);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
						    }
						break;
						case MARSHAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(12);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
							player->GetSession()->SendNotification("You dont have enough tokens");
							OnGossipHello(player, creature);
						    }
							
						break;
						case FIELD_MARSHAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(13);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case GRAND_MARSHAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(14);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case SCOUT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(15);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
								
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case GRUNT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(16);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						break;
						case SERGEANT_H:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(17);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
						break;
						case SENIOR_SERGEANT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(18);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case FIRST_SERGEANT:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(19);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case STONE_GUARD:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(20);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case BLOOD_GUARD:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(21);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case LEGIONNAIRE:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(22);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{	
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case CENTURION:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(23);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case CHAMPION:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(24);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case LIEUTENANT_GENERAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(25);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case GENERAL:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(26);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case WARLORD:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(27);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;
						case HIGH_WARLORD:
						
							if (player->HasItemCount(title_token, title_cost, true))
							{
								CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(28);
								player->DestroyItemCount(title_token, title_cost, true);
								player->SetTitle(titleInfo);
								OnGossipHello(player, creature);
							}
							else
							{
								player->GetSession()->SendNotification("You dont have enough tokens");
								OnGossipHello(player, creature);
							}
							
						break;

						case 100:
						
							CloseGossipMenuFor(player);
							
						break;
			        }
				
				
				}

				
				return true;
	
			
			}
			
			
		};
		
		
	CreatureAI* GetAI(Creature* creature) const override
	{
		return  new TitleAI(creature);
	}
		
};

void AddSC_Title_Npc()
{
	new Title_Npc();
}