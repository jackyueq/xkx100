// Room: /d/hengshan/cuiping1.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ�ʯ�׶��ͣ�����Ŀǰ����ͷ��������ɽ���͵�
�֣���ľ������о��ס�
LONG
	);
	set("exits", ([
		"westup"  : __DIR__"cuiping2",
		"down"    : __DIR__"cuipinggu2",
	]));

	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

