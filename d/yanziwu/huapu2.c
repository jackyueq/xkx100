// Room: /d/yanziwu/huapu2.c
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
		"north"  : __DIR__"path6",
		"west"   : __DIR__"huapu1",
	]));
	set("objects", ([
		__DIR__"obj/mutong" : 1,
		"/d/dali/obj/chahua10" : 1,
	]));
	set("coor/x", 1250);
	set("coor/y", -1280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}