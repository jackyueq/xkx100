// Room: /d/chengdu/dongjie3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ֹᴩ�ɶ����С����������ؽֶ�����Ǯ���Ƶľ�¥����
�ݣ������ֳ�Ϊ����ʳ�֡�����������������ֳ̼�Ⱥ���������ﳵ��
�������������У�ҹ���ǹ���£��ƻ�ͨ�����ϱ��Ǹ���ݣ������и�
ˮ����
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"dongjie2",
		"north" : __DIR__"shuijing",
		"south" : __DIR__"chaguan3",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 1,
	]));
	set("coor/x", -8020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

