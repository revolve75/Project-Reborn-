SET @RATE_PERM := '1300';

DELETE FROM `rbac_permissions` WHERE `id` BETWEEN @RATE_PERM AND @RATE_PERM+1;
INSERT INTO `rbac_permissions` (`id`,`name`) VALUES
(@RATE_PERM+0,'rate xp'),
(@RATE_PERM+1,'rate loot');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` BETWEEN @RATE_PERM AND @RATE_PERM+1;
INSERT INTO `rbac_linked_permissions` (`id`,`linkedId`) VALUES
('199',@RATE_PERM+0), -- GM command .rate xp
('199',@RATE_PERM+1); -- GM command .rate loot