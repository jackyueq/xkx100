// Room: /d/suzhou/xiting.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ�����������֪�����鷿���鰸�����ҵط��ż�������
�Ĺż����������ע�����ǽ�Ϲ���һ���ܴ�ĵ�ͼ(ditu)��
LONG
	);
	set("item_desc", ([
		"ditu" : "����һ�����ݵ����Ƿ���ͼ�������и�����ɫ��ȦȦ��㣬�Լ����˾���\n���������ҿ�����Ϊ��ϸ���ƺ���Ѱ��һ���ر�ĵص㡣\n",	
	]));
	set("exits", ([
		"east" : __DIR__"yamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", 835);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

