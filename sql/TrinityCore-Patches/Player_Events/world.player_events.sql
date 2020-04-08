/*
Navicat MySQL Data Transfer

Source Server         : Local
Source Server Version : 50612
Source Host           : localhost:3306
Source Database       : tc_world

Target Server Type    : MYSQL
Target Server Version : 50612
File Encoding         : 65001

Date: 2014-07-11 05:24:41
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for lil_actions
-- ----------------------------
DROP TABLE IF EXISTS `lil_actions`;
CREATE TABLE `lil_actions` (
  `id` int(10) unsigned NOT NULL,
  `type` int(10) DEFAULT '0',
  `avalue0` float DEFAULT '0',
  `avalue1` float DEFAULT '0',
  `avalue2` float DEFAULT '0',
  `avalue3` float DEFAULT '0',
  `avalue4` float DEFAULT '0',
  `message` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of lil_actions
-- ----------------------------
INSERT INTO `lil_actions` VALUES ('1', '1', '10000', '0', '0', '0', '0', 'CODEMSG');

-- ----------------------------
-- Table structure for lil_conditions
-- ----------------------------
DROP TABLE IF EXISTS `lil_conditions`;
CREATE TABLE `lil_conditions` (
  `id` int(10) unsigned NOT NULL,
  `TCConditionType` int(10) DEFAULT '0',
  `TCConditionEntry` int(10) DEFAULT '0',
  `TCGameEventEntry` int(10) DEFAULT '0',
  `PRace` int(1) DEFAULT '0',
  `PClass` int(1) DEFAULT '0',
  `CValue` int(10) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of lil_conditions
-- ----------------------------
INSERT INTO `lil_conditions` VALUES ('1', '0', '0', '0', '0', '0', '0');

-- ----------------------------
-- Table structure for lil_events
-- ----------------------------
DROP TABLE IF EXISTS `lil_events`;
CREATE TABLE `lil_events` (
  `id` int(10) unsigned NOT NULL,
  `type` int(10) DEFAULT '0',
  `condition` int(10) DEFAULT '0',
  `action` int(10) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of lil_events
-- ----------------------------
INSERT INTO `lil_events` VALUES ('0', '0', '0', '0');
INSERT INTO `lil_events` VALUES ('1', '1', '1', '1');
