// Room: /d/nanyang/hanshui1.c
// Last Modified by winder on Nov. 20 2001

inherit RIVER;

void create()
{
	::create();
	set("short", "��ˮ�ϰ�");
	set("long", @LONG
��ǰ��һ�����η����Ĵ� (river)���������������۾���������
�ɴ���������������һ�����������̯����Ҿͽ������ڰ��ߣ�������
���֧һ��ľ�壬���ϰ����˻�������ĺ������㡣��ȥ��Զ��������
���Ϻӿڣ����ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG );
	set("exits", ([
		"south" : __DIR__"yidao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanyang");
	set("coor/x", 10);
	set("coor/y", 320);
	set("coor/z", 0);
	set("to",__DIR__"hanshui2");
	setup();
}


