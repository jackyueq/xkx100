// Room: /d/quanzhou/shunjiqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "˳����");
	set("long", @LONG
���Ǻ����ӵ�һ��ʯ���š��ſ�ˮ�ˮ½��ͨ��ݣ�����ȥ��
Ψһ���ڡ�һ�ӹٱ�פ�������
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south"     : __DIR__"portroad3",
		"north"     : __DIR__"huajiaoting",
		"southeast" : __DIR__"shibosi",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1850);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
