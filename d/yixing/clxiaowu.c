// /d/yixing/clxiaowu.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���ǰ�������ƶ�Ǯ�ĵ�С�ݣ����еķ����ϱ����Ǽ���������
��һ�ԣ��������¡����Ⱥ�������һ�Ŷ�����������������ߺ�������
��Ǯ���������ҡҷ���ƺ�û����ע���������
LONG );
	set("exits", ([
		"east" : __DIR__"clzoulang2",
	]));
	set("objects",([
		__DIR__"npc/cl_bangzhong3" : 1,
	]));
	set("resource/water", 1);
	setup();
	replace_program(ROOM);
}
