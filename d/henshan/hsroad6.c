// Room: /d/henshan/hsroad6.c �ּ���
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "�ּ���");
	set("long", @LONG
������һ���ּ����������������ѡ������Ǻ��Ͼ��ڡ�������
������·���пɹ�·����Ϣ��С��ͤ��
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"west"        : "/d/heizhao/shanlu1",
		"northwest"   : "/d/heizhao/shanlu6",
		"southwest"   : "/d/tiezhang/lx",
		"east"        : __DIR__"chating",
		"north"       : __DIR__"hsroad7",
		"south"       : __DIR__"hsroad5",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
