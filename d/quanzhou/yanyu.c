// Room: /d/quanzhou/yanyu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�������¥");
	set("long", @LONG
���˵���˼�飬�������ߡ���������������Ȥ��Ȼ���������¥
�����¥��ʵ��Զ��������һ����¥�����㣬һ�����ţ����ɼ�԰����
̨ͤ¥鿣���ɽ��ˮ��һ�ر�ˮ����źӳ�졣�����������ͷ����ӡ�
LONG );
	set("exits", ([
		"west"   : __DIR__"road2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
