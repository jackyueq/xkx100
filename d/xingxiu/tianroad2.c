// room: /d/xingxiu/tianroad2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ɽɽ·");
	set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ
��ԭ��·��ͷ������һλ׳�����ڳ�Х���������Ͼ������˺��µ�����
���ˡ�
LONG );
	set("exits", ([
		"northup"   : "/d/lingjiu/shanjiao",
		"northdown" : __DIR__"xxh",
		"south"     : __DIR__"tianroad1",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/dulong" : 1,
		__DIR__"npc/gushou"  : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou"  : 1,
		"/clone/misc/dache" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "xiyu");
	set("coor/x", -50000);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
