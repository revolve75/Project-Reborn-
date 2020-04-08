# Reforging [![Build Status](https://travis-ci.org/Rochet2/TrinityCore.svg?branch=reforging)](https://travis-ci.org/Rochet2/TrinityCore)

#### About
Blizz*like* reforging
Change 40% of your item stats to something else
Sends item packets so you can see the changes on item tooltips
Simple and easy to use interface
Made for 3.3.5a.<br />
Source: http://rochet2.github.io/Reforging.html

Video: https://youtu.be/84EtvKTfqQM

#### Installation

Available as:
- Direct merge: https://github.com/Rochet2/TrinityCore/tree/reforging
- Diff: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...reforging.diff
- Diff in github view: https://github.com/Rochet2/TrinityCore/compare/TrinityCore:3.3.5...reforging

Using direct merge:
- open git bash to source location
- do `git remote add rochet2 https://github.com/Rochet2/TrinityCore.git`
- do `git pull rochet2 reforging`
- use cmake and compile

Using diff:
- DO NOT COPY THE DIFF DIRECTLY! It causes apply to fail.
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `reforging.diff` to the source root folder
- open git bash to source location
- do `git apply reforging.diff`
- use cmake and compile

After compiling:
- TrinityCore auto updater should run needed SQLs automatically.
- If you do not use the auto updater then run files named `*_reforging.sql` from `\sql\custom` to your databases.
- optionally you can also insert a reforger NPC to your database by running `\src\server\scripts\Custom\Reforging\sql\world_npc.sql` to your world database.

#### Bugs and Contact
Report issues and similar to https://rochet2.github.io/
