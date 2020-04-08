Below are the original README files from Rochet2. The first is for Transmog, the second is Transmog vendor.
I combined the two, so players have options. If you want to only use one, don't spawn the other NPC.
190012 = Transmog
190010 = Transmog-Vendor

- LordPsyan

# Transmogrification [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=transmog)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
Transmogrification allows you to change the display of an item to something else.
You can use any item in your bags as source of display, as long as it fits the requirements.
Requirements can be tweaked in the server configuration file.
Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system.
Has a feature to store sets of displays. This can be removed before compiling or in the configuration file.
Made for 3.3.5a.<br />
Source: http://rochet2.github.io/Transmogrification.html

Video: https://youtu.be/xtH4ogz12iM

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/transmog
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmog

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 transmog`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `transmog.diff` to the source root folder
- open git bash to source location
- do `git apply transmog.diff`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_transmog.sql` from `\sql\custom` to your databases.
- Optionally you can also insert a transmogrifier NPC to your database by running `\src\server\scripts\Custom\Transmog\sql\world_NPC.sql` to your world database.
- Change the settings to your liking in `worldserver.conf` (Note that you should copy over the new config created from compiling)

#### Usage
Equip an item that is suitable for transmogrification.
Have an item in your bags that is suitable to be used to transmogrify the equipped item
Talk to Transmogrifier and select the item slot. Then select the item you want to transmogrify to.
Click to proceed when prompted and your items are transmogrified.
Currently the default settings are according to this: http://wowwiki.wikia.com/Transmogrification#Current_rules
Tweak the settings if you need in worldserver.conf

#### Changelog: [Changelog](https://github.com/Rochet2/TrinityCore/blob/transmog/src/server/scripts/Custom/Transmog/CHANGELOG.md)

#### Bugs and Contact
Report issues and similar to https://rochet2.github.io/

_____________________________________________________________________________________________________________________________________________________________________

# Transmogrification Display Vendor [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=transmogvendor)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
Original idea by LilleCarl.
Coding work and execution by Rochet2.
Transmogrification Display Vendor allows you to change the display of an item to something else.
You can use any item display in the game, as long as it fits the requirements.
Requirements can be tweaked in the `TransmogDisplayVendor.cpp` file.
Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system.
Has a feature to work with the regular [Transmogrification](http://rochet2.github.io/Transmogrification.html). This can be enabled before compiling in `TransmogDisplayVendor.h`.
Made for 3.3.5a.<br />
Source: http://www.trinitycore.org/f/topic/7993-transmogrification-display-vendor/

Video: https://youtu.be/PIheEziN_dY

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/transmogvendor
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmogvendor.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...transmogvendor

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 transmogvendor`
- optionally tweak the config settings in `src/server/game/Entities/Item/TransmogDisplayVendor.cpp`
- use cmake and compile

Using diff *(recommended)*:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `transmogvendor.diff` to the source root folder
- open git bash to source location
- do `git apply transmogvendor.diff`
 - if using the regular transmogrification, simply use --reject with either and overwrite the parts of the other. Order doesnt matter, as long as duplicate code doesnt exist.
- optionally tweak the config settings in `src/server/game/Entities/Item/TransmogDisplayVendor.cpp`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_transmogvendor.sql` from `\sql\custom` to your databases.
- Optionally you can also insert a transmogrifier NPC to your database by running `\src\server\scripts\Custom\TransmogDisplayVendor\sql\world_NPC.sql` to your world database.

#### Usage
Equip an item that is suitable for transmogrification.
Talk to Transmogrifier and select the item slot. Then select the quality and then the item you want to transmogrify to.

#### Bugs and Contact
Report issues and similar to http://rochet2.github.io/
