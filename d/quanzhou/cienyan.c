// Room: /d/quanzhou/cienyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�Ͷ���");
	set("long", @LONG
�����ʯ���࣬������Ƭ��������ţ��з������á���������
�ȡ���ʯȺ�����������ʯ��Ȼ�����ʹ�����γ�һ����Ȼʯ�ң��Ͽ�
����ɽ��ֹ�����ݳ�������ҶȪ�ݵĽ�ʿ�뺫����½�޵�ͬ�ǡ�������
����ŷ��ղ�Ķ�������ҡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu5",
		"northdown" : __DIR__"shanlu4",
	]));
	set("coor/x", 1850);
	set("coor/y", -6460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
