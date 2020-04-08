/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is where scripts' loading functions should be declared:
// start01
// start02
// start03
// start04
// Beastmaster
    void AddSC_Npc_Beastmaster();
// start06
// start07
// start08
// start09
// VIP Commands
     //void AddSC_vipcommands();
// start11
// start12
// Enchant NPC
    void AddSC_npc_enchantment();
// start14
// start15
// start16
    //GuildHouse NPC
    void AddSC_guildmaster();
// start18
// start19
// start20
// Buff NPC
    void AddSC_Npc_Buff();
// start22
// start23
// start24
// Profession Npc
    void AddSC_professionnpc();
// start26
// start27
// start28
// start29
// start30
// start31
// start32
// start33
// start34
// start35
// start36
// start37
// start38
// start39
// start40
// start42
// start43
// start44
// start45
// start46
// start47
// start48
// start49
// start50
// start51
// start52
// start53
// start54
// start55
// start56
void AddSC_Transmogrification();
void AddSC_NPC_TransmogDisplayVendor();
// start58
// start59
// start60
// 1v1 Arena
void AddSC_npc_1v1arena();
// start62
// start63
// start64
// start65
// start66
// start67
// start68
// start69
// start70
// start71
// start72
void AddSC_REFORGER_NPC();
// start74
// start75
// start76
// Start Guild
    void AddSC_gon_playerscripts();
// start78
// start79
// start80
// World Chat
void AddSC_World_Chat();
// start82
// start83
// start84
// start85
// start86
// start87
// start88
// Account Mounts
void AddSC_accontmounts();
// start90
// start91
// start92
// Announce Login
void AddSC_announce_login();
// start94
// start95
// start96
// start97
// start98
// start99
// start100
// start101
// start102
// start103
// Arena Template
void AddSC_TemplateNPC();
// start105
// start106
// start107
// start108
// start109
// start100
// start111
// start112
// start113
// start114
// start115
// start116
// start117
// Auto Learn Spells
void AddSC_LearnSpellsOnLevelUp();
// start119
// start120
// start121
// start122
// start123
// start124
// start125
// start126
// start127
// start128
// start129
// Chat Censor
void AddSC_System_Censure();
// start131
// start132
// start133
// start134
// start135
// start136
// start137
// start138
// start139
// start140
// start141
// start142
// start143
// start144
// start145
// start146
// Lottery NPC
    void AddSC_npc_lottery();
// start148
// start149
// start150
// start151
// VIP
//void AddSC_premium_commandscript();
// start153
// start154
// start155
// start156
// start157
// start158
// start159
// start160
// start161
// start162
// start163
// start164
// start165
// start166
// start167
// start168
// start169
// start170
// start171
// start172
// start173
// start174
// start175
// start176
void AddSC_Title_Npc();
// start177
// start178
// start179
// start180
// start181
// start182
// start183
// start184
// start185
// start186
// start187
// start188
// start189
// start190
// start191
// start192
// start193
// start195
// start196
// start197
// start198
// start199
// start200

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
// end01
// end02
// end03
// end04
// Beastmaster
AddSC_Npc_Beastmaster();
// end06
// end07
// end08
// end09
// VIP Commands
//AddSC_vipcommands();
// end11
// end12
// Enchant NPC
AddSC_npc_enchantment();
// end14
// end15
// end16
    // GuildHouse NPC
    AddSC_guildmaster();
// end18
// end19
// end20
// Buff NPC
AddSC_Npc_Buff();
// end22
// end23
// end24
// Profession Npc
AddSC_professionnpc();
// end26
// end27
// end28
// end29
// end30
// end31
// end32
// end33
// end34
// end35
// end36
// end37
	AddSC_Title_Npc();
// end38
// end39
// end40
// end42
// end43
// end44
// end45
// end46
// end47
// end48
// end49
// end50
// end51
// end52
// end53
// end54
// end55
// end56
    AddSC_Transmogrification();
    AddSC_NPC_TransmogDisplayVendor();
// end58
// end59
// end60
// 1v1 Arena
    AddSC_npc_1v1arena();
// end62
// end63
// end64
// end65
// end66
// end67
// end68
// end69
// end70
// end71
// end72
    AddSC_REFORGER_NPC();
// end74
// end75
// end76
// Start Guild
    AddSC_gon_playerscripts();
// end78
// end79
// end80
// World Chat
    AddSC_World_Chat();
// end82
// end83
// end84
// end85
// end86
// end87
// end88
// Account Mount
    AddSC_accontmounts();
// end90
// end91
// end92
// Announce Login
    AddSC_announce_login();
// end94
// end95
// end96
// end97
// end98
// end99
// end100
// end101
// end102
// end103
// Arena Template
    AddSC_TemplateNPC();
// end105
// end106
// end107
// end108
// end109
// end100
// end111
// end112
// end113
// end114
// end115
// end116
// end117
// Auto Learn Spells
    AddSC_LearnSpellsOnLevelUp();
// end119
// end120
// end121
// end122
// end123
// end124
// end125
// end126
// end127
// end128
// end129
// Chat Censor
    AddSC_System_Censure();
// end131
// end132
// end133
// end134
// end135
// end136
// end137
// end138
// end139
// end140
// end141
// end142

// end143
// end144
// end145
// end146
// Lottery NPC
AddSC_npc_lottery();
// end148
// end149
// end150
// end151
// VIP
    //AddSC_premium_commandscript();
// end153
// end154
// end155
// end156
// end157
// end158
// end159
// end160
// end161
// end162
// end163
// end164
// end165
// end166
// end167
// end168
// end169
// end170
// end171
// end172
// end173
// end174
// end175
// end176
// end177
// end178
// end179
// end180
// end181
// end182
// end183
// end184
// end185
// end186
// end187
// end188
// end189
// end190
// end191
// end192
// end193
// end195
// end196
// end197
// end198
// end199
// end200
}
