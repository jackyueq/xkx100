// Room: /d/huashan/jzroad1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ��ɸߵ�������
���Ͻ��Ų����ɹ��������Ұ�������ζ�����
LONG );
	set("exits", ([
		"southwest" : "/d/village/hsroad2",
		"east"      : __DIR__"jzroad2",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu": 2,
	]));
	set("outdoors", "zhongtiao");
	set("coor/x", -950);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
