// Room: /d/quanzhou/portroad2.c
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
		"south" : __DIR__"houzhu",
		"north" : __DIR__"portroad1",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 1,
		"/d/taishan/npc/tiao-fu" : 1,
		__DIR__"npc/kuli" : 1,
		__DIR__"npc/langren" : 1,
	]));
	set("coor/x", 1880);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
