// Room: /d/huashan/jzroad4.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "����ɽɭ��");
	set("long", @LONG
����������ɽ·�ϡ�·����С����Χï��ɭ�����������Ұ��ҹ
�ݵ�˻������������ë���Ȼ��
LONG );
	set("exits", ([
		"southup"  : __DIR__"jzroad5",
		"westdown" : __DIR__"jzroad3",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);
	set("coor/x", -920);
	set("coor/y", 210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
