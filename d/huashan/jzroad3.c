// Room: /d/huashan/jzroad3.c

inherit ROOM;
void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����������ɽ�š�������գ�ɽ��ѹ������ߵĺ�ϼӳ͸������ɽ
�֣���Х�Ĵ�ɽ��θ���ͣ���㲻��������Щ���⡣����һ����ɽС
·��
LONG );
	set("outdoors", "zhongtiao");
	set("exits", ([
		"west"   : __DIR__"jzroad2",
		"eastup" : __DIR__"jzroad4",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -930);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
