// /d/beihai/qingxiao.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��������¥Ϊһ��ɽ��֮���㽨����Ъɽ�����ϲ��������ȣ��Ƕ�
�չ۱���֮����վ�������������Ŀ����������ľ�ɫ��
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"yuexin",
		"northdown" : __DIR__"yuegu",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
