// Room: /d/wuyi/xianyutan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��ԡ̶");
	set("long", @LONG
���ʵ�ʯ�ڣ�Ӫ����һ������������⾳��һ���峺�ĳ�ˮ������
�ԵĲ��⡣���յ���������ܽ�ѩ��Ȫ�����ȱ���ˮ���С����㲽����
�η����ԡ̶��ƣ������Ķ�Ȼ�������еĸ�ο�����������ǲ�������
��ǳǳ�������ľ����⣬Ҳ����������뷲�˵�����ɣ���Ȼ�������
��û�з��˰��Ѳ��˵�Զ�ǽ��ǡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"tianyoufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4960);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

