// ROOM liangunshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
�����������Ŷ�����ĵط�����Χ����Ķѷ�������õ�ԭ�ϣ�һ
������С����������һ�����������������ϸ���ж��š����������˹�
������æ�������е��飬����һ��������㺩����һЦ���������ֺ��ˡ�
LONG );
	set("exits", ([
		"east" : "/d/xueshan/shenghu",
	]));
	set("objects", ([
		__DIR__"npc/shigun" : 1,
	]));
	set("coor/x", -30050);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
