// Room: /d/quanzhou/shibosi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�в�˾");
	set("long", @LONG
���Ǹ���Ӵ�����ʹ�ڼ��ﱸ���������Ҫ�����ĵط����ſ�����
���߸���һ����ʯʨ�ӣ���̬�ý�������ߺ�������ͨ��˳���ţ���
�ϱ�ͨ���ۿ�·�����ߵĽֵ���ͷ����Ϳ�ż���
LONG );
	set("exits", ([
		"north"     : __DIR__"road2",
		"southwest" : __DIR__"portroad3",
		"northwest" : __DIR__"shunjiqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
