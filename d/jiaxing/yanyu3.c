// Room: /d/jiaxing/Yanyu3.c  ����¥��
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����¥��");
	set("long", @LONG
����������¥��¥��������һƬ����������������ԧ�콻��������
��侣�΢���������������ɣ�������������ɧ�ͰѾ�ƾ����������ӽ��
�����ڡ�
LONG );
	set("no_sleep_room",1);
	
	set("exits", ([
	    "down"     : __DIR__"yanyu2",
	]));
	
	set("objects", ([
		CLASS_D("baituo")+"/ouyangfeng1": 1
	]));
	set("coor/x", 1520);
	set("coor/y", -1020);
	set("coor/z", 20);
	setup();
}

