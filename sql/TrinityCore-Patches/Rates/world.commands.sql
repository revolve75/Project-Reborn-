SET @RATE_PERM := '1300';

INSERT INTO `command`(`name`,`permission`,`help`) VALUES
('rate xp',@RATE_PERM+0,'Syntax: .rate xp $value\r\nSets your XP multiplier to $value. If no parameter is provided, it will show your current XP rate.'),
('rate loot',@RATE_PERM+1,'Syntax: .rate loot $value\r\nSets your loot multiplier to $value. If no parameter is provided, it will show your current loot rate. A $value of 0 means you won\'t be able to loot anything.');
