// Room: /d/hengshan/cuipinggu2.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ͽ�����ʯ�ڶ�ֱ�����±�����һ����������������ƾ���
�ĺ�ɽɽ���У�ȴ����ʮ���������ڴ���ɽ������������Σ�ң�������
�ȣ��������£���������¥�Կ���ȽȽ���䡣�Ǿ����������ˡ�
LONG
	);
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

	set("outdoors", "hengshan");
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

