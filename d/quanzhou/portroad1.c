// Room: /d/quanzhou/portroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ۿ�·");
	set("long", @LONG
�����ô�黨��ʯ�̳ɵĿ������ƽ̹��ʵ��·���������ų�
�صĻ�������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ��
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"portroad2",
		"north" : __DIR__"lingshan",
	]));
	set("objects", ([
		"/d/fuzhou/npc/biaotou" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
