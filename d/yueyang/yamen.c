// Room: /d/yueyang/yamen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������á�������ľ���Ž����ر��ţ��������š���ү���ǡ�
�����������������¹�δ���������Ҳ�Ͳ��ÿ��ˡ����ྲ�����رܡ�
�����ӷַ���ͷʯʨ�ӵ��Աߡ���ǰ������Ӱ��Ÿ�Ƥ�ģ�����һ��ľ
颡���Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�
LONG );
	set("exits", ([
		"south" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 2,
	]));
	set("outdoors", "yueyang");
	set("coor/x", -1400);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

