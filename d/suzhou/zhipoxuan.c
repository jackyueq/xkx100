// Room: /d/suzhou/zhipoxuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "Ҿ��ָ����");
	set("long", @LONG
��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ˵���д
ʫ����֮��������ȡ���䡰ǰҾ®ɽ��һ����㡱�͸����ġ�Цָͥǰ
�ء���ʫ�⡣���ڰ�������ɫ��ƾ����������Ŀʯ����ᾣ��Ű��֦
���ƣ�������Դ��ʮ�˾���֮�ơ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : __DIR__"shizilin",
	]));
	set("coor/x", 870);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
