// /d/beihai/yuwen.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����ǵ�֮���ϵ�һ��ʯͤ������Ԫ�����͡�������ͨ�徧Ө��͸��
Ϊһ����ī���̶������������֮����������֮��ʵ�ǲ��ɶ��
֮�ȴ��֪����������������ʲô�ġ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"chengguang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

