// Room: /d/quanzhou/portroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�ۿ�·");
	set("long", @LONG
�����ô�黨��ʯ�̳ɵĿ������ƽ̹��ʵ��·���������ų�
�صĻ�������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ��
�������Ǻ��⽻ͨʹ�ڸ������߽���˳���š�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northeast" : __DIR__"shibosi",
		"southeast" : __DIR__"portroad4",
		"north"     : __DIR__"shunjiqiao",
	]));
	set("objects", ([
		"/d/taishan/npc/tangzi" : 2,
		"/d/fuzhou/npc/biaotou" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
