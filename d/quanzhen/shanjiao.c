// shanjiao.c ����ɽ��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����������ɽ��ɽ�ţ�����ɽ�ų������ĵ�һɽ����ɽ�������
�����������ơ������ɽ�ƻ���ƽ����һ��ʯ������ͨ��ɽ�ϡ���ǰ
��һ����ɽ����ͬ����һ���������գ����Թ��˵�ʫ�����С�����
һ������˵����
LONG
	);
	set("outdoors", "zhongnan");
	set("exits", ([
		"north"    : __DIR__"shanlu4",
		"westdown" : __DIR__"shanlu3",
	]));
	set("objects",([
		__DIR__"npc/youke" : 1,
		__DIR__"npc/xiangke" : 2,
		"/clone/misc/dache" : 1,
	]));

	set("coor/x", -3130);
	set("coor/y", -10);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
