// Room: /d/kunlun/shufang.c
// Last Modified by Winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�������鷿����ǽһ�Ŵ���ܣ��ڷ��źܶ���鼮��������ʥ����
����������ų��ԡ�ʥ������������һֱ����Ϊ�٣���������ѧ�����ա�
һ������ȥ���ƺ��й��ڲ������巽����顣
LONG );
	set("exits", ([
		"west"  : __DIR__"jiuqulang3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119970);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}