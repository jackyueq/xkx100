// Room: /yangzhou/hejiajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "�̼ν�");
	set("long", @LONG
�̼ν������ǳ����𣬼���ʿ����վ�ڣ���ʱ��ʿ��Уξ��������
�˵��ˣ��಻��ͣ���������Ƿǡ��ֵ������࣬Ҳ������Ƥ�ڴ˴��֡�
�����Ϊ��լ�����ܱȴ��ܽӡ��м���һС��ͨ��������԰���ҡ����
ʯ����ס����
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"nanmendajie",
		"east"  : __DIR__"dongmenqiao",
		"south" : __DIR__"bingyindamen",
		"north" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}