// Room: /d/taishan/yitian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "һ����");
	set("long", @LONG
����ڷ���ɽ��Լ�����������һ���š�������һ����׷�����
�˴˷�������˵�̩ɽ���̵���������һ������ͤ��ʿ����Ǽ�����ӣ�
���������ﻻ�����ķ�װ���ż�����ɽ����һ������������������
��ʮ���������������������֣���̩ɽ���˵������й�ֹ֮̾������
��һ�Ʒ����ξ�״Ԫ�޺������(e) ����(lian)���ഫΪ�����ӹ�̩ɽ
�ࡹ�Ĺ��·����ĵط���
LONG );
	set("exits", ([
		"southwest" : __DIR__"guandi",
		"northup"   : __DIR__"sanyibai",
		"southdown" : __DIR__"hongmen",
	]));
	set("item_desc", ([
		"e"    : "���ӵ��ٴ�\n",
		"lian" : "����������ǧ��  ʥ��ң��������\n",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 560);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
