// Room: /d/hengshan/cuipinggu1.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ڹ��г�ˢ�����������ʹ���ɽ����Ͽ�����࣬����ǧ��
���絶���������������ƣ������Թž�������ͨ���ڵص��ʺ�Ҫ������
��һ�򵱹����Ī��֮�ơ�
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/wen" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 3190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

