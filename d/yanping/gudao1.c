// Room: /d/yanping/gudao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
���뽭�������ǲ�����ɽ���������Ĺȣ����ղ�����⡣����ɽ��
�������޳�û�޳�����·������һ��������ŵ�һ���ȷ��˱Ƕ�����
LONG );
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"gudao2",
	]));
	set("objects", ([
		__DIR__"npc/huananhu" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1100);
	set("coor/y", -6200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
