// Room: /d/wuyi/yonglechansi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Թ���԰���ã�������ɽɮռ�ࡱ��λ�������Ҹ��ص�������
�����£��Ӵ����������𣬾Ͱ����Ĺ������ĵ�ɽˮ��ȥ�ˡ���ΧȺ��
���ͣ���ľ���졣�������ȥ�ˣ�ÿ��ĳ���ĺ�ģ��ô���ͬ����������
������ԭ�����ˮ��ɽ�����磬���ֱ����������������硣��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"tianxinyan",
		"south"     : __DIR__"path5",
		"southwest" : __DIR__"path11",
		"northwest" : __DIR__"path14",
	]));
	set("objects", ([
		"/d/hangzhou/npc/seng": random(2),
		"/d/hangzhou/npc/shami": random(3),
	]));
	set("coor/x", 1400);
	set("coor/y", -4930);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

