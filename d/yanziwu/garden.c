// Room: /d/yanziwu/garden.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����������ɽׯ�Ļ�԰����ݺ�������ݱ̻�Ũ����Ȼ�ǽ��Ϻô�ɫ��
��������עĿ����԰�еļ���軨���ڴ��������Ʒ���ڽ���ȴίʵ��
�á�һ��Ϫˮ��������԰�д�����˳���۳�һ��С����
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"north"  : __DIR__"yunjin1",
		"south"  : __DIR__"path4",
		"east"   : __DIR__"path5",
		"west"   : __DIR__"path25",
	]));
	set("objects", ([
		"/d/dali/obj/chahua1": 1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}