// /d/beijing/andao10.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�����߳��˰������㳤��������һ��������������ػ���ľ�õĴ�
���������ĵƹ����˸е��ޱ���ů��
LONG );
	set("exits", ([
		"west"  : __DIR__"andao9",
		"east"  : __DIR__"andao9",
		"north" : __DIR__"dating",
		"south" : __DIR__"andao9",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/first" : 1,
	]));
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
