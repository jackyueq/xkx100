// /kaifeng/huiguan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "ɽ�¸ʻ��");
	set("long", @LONG
ɽ�¸ʻ����ɽ��������������ĸ��̾޼ֽ���ģ�������ͬ���
��ĳ��������Ǹ������ص��˾ۻ�ġ���ȻҲ���ڴ�����̸����ġ���
����ǹص���
LONG);
	set("exits", ([
		"west" : __DIR__"eroad2",
		"east" : __DIR__"paifang",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
