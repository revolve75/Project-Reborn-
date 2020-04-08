/*
 * Author: Xees
 * FileName: ArenaGambler.cpp
 * Description: This file is used to script the npc for the Arena Gambling System
 * Version: 1.9
 * Status: functional
*/

#include "ArenaGamblingSystem.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "GameObjectAI.h"
#include "GameObject.h"

class ArenaGambler : public CreatureScript
{
    public:
        ArenaGambler() : CreatureScript(ARENA_GAMBLER_SCRIPT_NAME) {}

        static bool OnGossipHello(Player *pPlayer, Creature *pCreature)
        {
            switch (urand(0,6))
            {
                case 0: pCreature->Say("|cffbbbbbbWelcome ye great warrior , fight to the last for the Lich King!",LANG_UNIVERSAL,pPlayer); break;
                case 1: pCreature->Say("|cffbbbbbbOnly great warriors are welcome!",LANG_UNIVERSAL,pPlayer); break;
                case 2: pCreature->Say("|cffbbbbbbMere mortals cannot be gods!",LANG_UNIVERSAL,pPlayer); break;
                case 3: pCreature->Say("|cffbbbbbbGreat warrior , you seek to duel!",LANG_UNIVERSAL,pPlayer); break;
                case 4: pCreature->Say("|cffbbbbbbDeath and glory await!",LANG_UNIVERSAL,pPlayer); break;
                case 5: pCreature->Say("|cffbbbbbbBegone, weaklings are unwelcome!",LANG_UNIVERSAL,pPlayer); break;
                case 6: pCreature->Say("|cffbbbbbbDeath and honor!",LANG_UNIVERSAL,pPlayer); break;
            }
                pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_ITEM, ARENA_GAMBLER_MENU_MAIN, GOSSIP_ACTION_INFO_DEF + 1, "", false);
                SendGossipMenuFor(pPlayer, pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

            return true;
        }

        static bool OnGossipSelect(Player *pPlayer, Creature *pCreature, uint32 sender, uint32 action)
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            switch(sender)
            {
                case ARENA_GAMBLER_MENU_MAIN:
                {
                    if(GamblerMatchData *matchData = sGamblingSystem->GetMatchDataBy(pPlayer))
                    {
                            if(matchData->MatchStarted())
                                return true;
                            if(matchData->GetItemIdBy(pPlayer) == 0) // if there is match data, but no item was bet
                                pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM,    ARENA_GAMBLER_TEXT_BET_ITEM,            ARENA_GAMBLER_MENU_BET_ITEM,            GOSSIP_ACTION_INFO_DEF + 1, ARENA_GAMBLER_TEXT_BET_ITEM_CODE_TEXT, 0, true);
                            if(matchData->GetItemIdBy(pPlayer) != 0 && matchData->GetItemCountBy(pPlayer) == 0) // if there is match data and an item, but no amount was entered
                            pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM,    ARENA_GAMBLER_TEXT_BET_ITEM_AMOUNT,    ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT,    GOSSIP_ACTION_INFO_DEF + 1, "", false);
                            if(matchData->GetChallengerItemId() && matchData->GetDefenderItemId() && matchData->GetItemCountBy(pPlayer) != 0 &&  matchData->HasSetReady(pPlayer) == false) // if everything checks out, but player is not yet ready.
                                pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_ACCEPT,    ARENA_GAMBLER_TEXT_ACCEPT_CHALLENGE,    ARENA_GAMBLER_MENU_ACCEPT_CHALLENGE,    GOSSIP_ACTION_INFO_DEF + 1, "", false);
                            if(matchData->GetChallengerGUID() == pPlayer->GetGUID().GetCounter())
                                pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_CANCEL,    ARENA_GAMBLER_TEXT_CANCEL_CHALLENGE,    ARENA_GAMBLER_MENU_CANCEL_CHALLENGE,    GOSSIP_ACTION_INFO_DEF + 1, "", false);
                            else
                                pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_DECLINE,    ARENA_GAMBLER_TEXT_DECLINE_CHALLENGE,    ARENA_GAMBLER_MENU_DECLINE_CHALLENGE,    GOSSIP_ACTION_INFO_DEF + 1, "", false);
                        }
                        else // if no match data was found
                        {
                            pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_CHALLENGE, ARENA_GAMBLER_TEXT_CHALLENGE, ARENA_GAMBLER_MENU_CHALLENGE_PLAYER, GOSSIP_ACTION_INFO_DEF + 1, ARENA_GAMBLER_TEXT_CHALLENGE_CODE_TEXT, 0, true);
                        }
                        pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_EXIT, ARENA_GAMBLER_TEXT_EXIT, ARENA_GAMBLER_MENU_EXIT, GOSSIP_ACTION_INFO_DEF + 1, "", false);
                        SendGossipMenuFor(pPlayer, pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT:
                {
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_1, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_1, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_10, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_10, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_20, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_20, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_30, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_30, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_40, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_40, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_50, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_50, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_100, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_100, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_200, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_200, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_300, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_300, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_500, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_500, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);
                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_BET_ITEM, ARENA_GAMBLER_TEXT_BET_AMOUNT_1000, ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_1000, GOSSIP_ACTION_INFO_DEF + 1, "", 0, false);

                    pPlayer->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, ARENA_GAMBLER_ICON_EXIT, ARENA_GAMBLER_TEXT_EXIT, ARENA_GAMBLER_MENU_EXIT, GOSSIP_ACTION_INFO_DEF + 1, "", false);
                    SendGossipMenuFor(pPlayer, pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
                }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_1:
                    {
                        if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 1) == false)
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                        else
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_10:
                    {
                        if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 10) == false)
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                        else
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_20:
                    {
                        if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 20) == false)
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                        else
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_30:
                    {
                        if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 30) == false)
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                        else
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_40:
                    {
                        if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 40) == false)
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                        else
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                    case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_50:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 50) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_100:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 100) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_200:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 200) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_300:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 300) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_500:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 500) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_BET_ITEM_AMOUNT_1000:
                {
                    if(sGamblingSystem->AddItemAmountForMatch(pPlayer, 1000) == false)
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_BET_AMOUNT_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_AMOUNT_SUCCESS);
                    CloseGossipMenuFor(pPlayer);
                }break;
                case ARENA_GAMBLER_MENU_ACCEPT_CHALLENGE:
                    {
                        sGamblingSystem->AcceptChallenge(pPlayer);
                        CloseGossipMenuFor(pPlayer);
                    }break;
                case ARENA_GAMBLER_MENU_CANCEL_CHALLENGE:
                case ARENA_GAMBLER_MENU_DECLINE_CHALLENGE:
                    {
                    sGamblingSystem->CancelChallenge(pPlayer);
                    CloseGossipMenuFor(pPlayer);
                    }break;
                case ARENA_GAMBLER_MENU_EXIT:{
                    CloseGossipMenuFor(pPlayer);
                    }break;
            }

            return true;
        }

        static bool OnGossipSelectCode(Player *pPlayer, Creature *pCreature, uint32 sender, uint32 action, const char *pCode)
        {
            switch(sender)
            {
                case ARENA_GAMBLER_MENU_CHALLENGE_PLAYER:
                {
                    if(Player* pDefender = ObjectAccessor::FindPlayerByName(pCode))
                    {
                        if(sGamblingSystem->CanHaveMatch(pPlayer, pDefender) == false)
                        {
                            // General Error Message: Match not possible because:
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_MATCH_NOT_POSSIBLE);
                            // Reason is: no gamemasters
                            if(pPlayer->GetSession()->GetSecurity() > 0 || pDefender->GetSession()->GetSecurity() > 0)
                            {
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_NO_GMS_ALLOWED);
                            }
                            // Reason is: you cannot duel your self!
                            if(pPlayer->GetSession()->GetAccountId() == pDefender->GetSession()->GetAccountId())
                            {
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_SAME_ACC_ID);
                            }
                            // Reason is: multiboxing is not allowed, or players have the same ip.
                            if(pPlayer->GetSession()->GetRemoteAddress().compare(pDefender->GetSession()->GetRemoteAddress()) == 0)
                            {
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_MULTI_BOX);
                            }
                            // Reason is: your level is smaller than the minimum level required
                            uint32 m_minRequiredLevel = 0;
                            if(pPlayer->getLevel() <= m_minRequiredLevel || pDefender->getLevel() <= m_minRequiredLevel )
                            {
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_LOW_LEVEL);
                            }
                            // Reason is: you are requesting a duel from someone who already is in a duel.
                            ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_LOW_LEVEL);
                            // Reason is: level diffrance is too high
                            uint32 levelDiff = 0;
                            if(pPlayer->getLevel() > pDefender->getLevel())
                            {
                                levelDiff = pPlayer->getLevel() - pDefender->getLevel();
                            }
                            else
                            {
                                levelDiff = pDefender->getLevel() - pPlayer->getLevel();
                            }
                            return true;
                        }
                        sGamblingSystem->SetupMatch(pPlayer, pDefender);
                        pPlayer->GetSession()->SendAreaTriggerMessage(ARENA_GAMBLER_MSG_CHALLENGE_ISSUED, pDefender);
                        pDefender->GetSession()->SendAreaTriggerMessage(ARENA_GAMBLER_MSG_CHALLENGED, pPlayer);
                        OnGossipSelect(pPlayer, pCreature, ARENA_GAMBLER_MENU_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    }
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_PLAYER_NOT_FOUND);
                }break;

                case ARENA_GAMBLER_MENU_BET_ITEM:
                {
                    if(sGamblingSystem->AddItemForMatch(pPlayer, pCode) == false)
                        pPlayer->GetSession()->SendAreaTriggerMessage(ARENA_GAMBLER_MSG_ITEM_ADD_FAILED);
                    else
                        ChatHandler(pPlayer->GetSession()).PSendSysMessage(ARENA_GAMBLER_MSG_ITEM_ADD_SUCCESS);
                    OnGossipSelect(pPlayer, pCreature, ARENA_GAMBLER_MENU_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                }break;
            }
            return true;
        }

    struct MyAI : public ScriptedAI
        {
            MyAI(Creature* m_creature) : ScriptedAI(m_creature) { }
            bool GossipHello(Player* player) override
            {
                return OnGossipHello(player, me);
            }
            bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
            {
                uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                return OnGossipSelect(player, me, sender, action);
            }
            bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override
            {
                uint32 sender = player->PlayerTalkClass->GetGossipOptionSender(gossipListId);
                uint32 action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
                return OnGossipSelectCode(player, me, sender, action, code);
            }
        };

    CreatureAI* GetAI(Creature* m_creature) const override
        {
            return new MyAI(m_creature);
        }
};

// Arena Records GameObject
class ArenaRecords : public GameObjectScript
{ public:
    ArenaRecords() : GameObjectScript(ARENA_RECORDS_SCRIPT_NAME) { }

    struct ArenaRecordsAI : public GameObjectAI
    {
        ArenaRecordsAI(GameObject* go) : GameObjectAI(go) { }

    bool OnGossipHello(Player* pPlayer, GameObject* pGo)
    {
        if(QueryResult queryResult = CharacterDatabase.PQuery("SELECT `playerGUID`,`duelsLost`,`duelsWon`,`duelsRefused`,`duelsTotal` FROM `custom_duel_statistics` WHERE `playerGUID` = '%u'", pPlayer->GetGUID().GetCounter()))
        {
            uint32 playerGUID = queryResult->Fetch()[0].GetUInt32();
            uint32 duelsLost = queryResult->Fetch()[1].GetUInt32();
            uint32 duelsWon = queryResult->Fetch()[2].GetUInt32();
            uint32 duelsRefused = queryResult->Fetch()[3].GetUInt32();
            uint32 duelsTotal = queryResult->Fetch()[4].GetUInt32();

            std::ostringstream Lost;
            std::ostringstream Won;
            std::ostringstream Refused;
            std::ostringstream Total;

            Lost << MSG_COLOR_SUBWHITE << "You have Lost : " << MSG_COLOR_LIGHTBLUE <<  duelsLost << " Duel(s)." ;
            Won << MSG_COLOR_SUBWHITE << "You have Won : " << MSG_COLOR_LIGHTBLUE <<  duelsWon << " Duel(s)." ;
            Refused << MSG_COLOR_SUBWHITE << "You have Refused : " << MSG_COLOR_LIGHTBLUE <<  duelsRefused << " Duel(s)." ;
            Total << MSG_COLOR_SUBWHITE << "You have Fought : " << MSG_COLOR_LIGHTBLUE <<  duelsTotal << " Duel(s)." ;

            ChatHandler(pPlayer->GetSession()).SendSysMessage(Lost.str( ).c_str( ));
            ChatHandler(pPlayer->GetSession()).SendSysMessage(Won.str( ).c_str( ));
            ChatHandler(pPlayer->GetSession()).SendSysMessage(Refused.str( ).c_str( ));
            ChatHandler(pPlayer->GetSession()).SendSysMessage(Total.str( ).c_str( ));
        }
        else
        {
            switch (urand(0,5))
            {
            case 0: pPlayer->Say("I never fought once , i should be ashamed.",LANG_UNIVERSAL,pPlayer);break;
            case 1: pPlayer->Say("This book does not hold any records of me!",LANG_UNIVERSAL,pPlayer);break;
            case 2: pPlayer->Say("i have never challenged anyone here!",LANG_UNIVERSAL,pPlayer);break;
            case 3: pPlayer->Say("I should first challenge someone!",LANG_UNIVERSAL,pPlayer);break;
            case 4: pPlayer->Say("No Wins, No losses",LANG_UNIVERSAL,pPlayer);break;
            case 5: pPlayer->Say("I should hide in a cave, i don't deserve to be here!",LANG_UNIVERSAL,pPlayer);break;
            }
        }
        return true;
    }
};

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new ArenaRecordsAI(go);
    }
};

void AddSC_ArenaGambler()
{
    sGamblingSystem->Initalize();
    new ArenaGambler();
    new ArenaRecords();
}