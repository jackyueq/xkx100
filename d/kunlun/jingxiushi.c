// Room: /d/kunlun/jingxiushi.c
// Last Modified by winder on Nov. 14 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ����ң�����˳��ط��ż������ţ��������ż����㣬����
�������𡣼�λ�����ɵ�������ϥ��������������ޡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"huayuan1",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}