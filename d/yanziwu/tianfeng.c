// Room: /d/yanziwu/tianfeng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���鿽�������ɽ���ϣ������ο̵Ĵ��ȣ���ʱ��������ˬ���ˣ�
��Ϊ��硣
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"path24",
	]));
	set("coor/x", 1220);
	set("coor/y", -1250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}