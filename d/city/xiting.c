// Room: /city/xiting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ�����������֪�����鷿���鰸�����ҵط��ż�������
�Ĺż����������ע�����ǽ�Ϲ���һ���ܴ�ĵ�ͼ(ditu)��
LONG );
	set("item_desc", ([
		"ditu" : "����һ�������������н��ĵ�ͼ�������и�����ɫ��ȦȦ��㣬�Լ����˾���\n"
		"���������ҿ�����Ϊ��ϸ���ƺ���Ѱ��һ���ر�ĵص㡣\n",	
	]));
	set("exits", ([
		"east" : __DIR__"zhengtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -21);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}