// Room: /d/yanziwu/huapu1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ɽׯ�еĻ��ԡ������а��˺ܶ໨������࣬���񴦻�
����������硣�Ĵ�ɢ���Ų��ٲ�֪���Ļ������з��е�󷲲軨����
֦���񻣬����ʤ�硣
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"path5",
		"east"   : __DIR__"huapu2",
	]));
	set("objects", ([
		__DIR__"obj/chutou" : 1,
		"/d/dali/obj/chahua9" : 1,
	]));
	set("coor/x", 1240);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}