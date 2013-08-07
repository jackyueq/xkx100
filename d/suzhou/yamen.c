// Room: /d/suzhou/yamen.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ݸ��á����϶������������������һ��������������
��������ϸ������ǽ������һ�����ң�������顰����������ĸ����
�����Ĵ��֡�һ����ྲ�����رܡ������ӷ������ࡣ֪����������
�����������飬ʦү�����ں�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"neizhai",
		"south"  : __DIR__"yamengate",
		"east"   : __DIR__"dongting",
		"west"   : __DIR__"xiting",
	]));
	set("objects", ([
		__DIR__"npc/feng": 1,
		__DIR__"npc/shiye": 1,
		__DIR__"npc/yayi": 4,
	]));
	set("coor/x", 840);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
