// Room: /d/nanshaolin/jietan4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��̳");
	set("long", @LONG
����һ�������Σ��Ľ��ܼⶥ��̨ͤʽ������������ɮͽ�ܽ�ĵ�
����̳�����з��з����������򱳶�����˫��ͭ�������汱����ҩʦ
�����ϵ�Ϊ�����ӷ�̳�Ͽ���һ�ˣ��ž�������Խ���Եô˴���ׯ
�����¡�
LONG );
	set("exits", ([
		"west"      : __DIR__"jietan3",
		"south"     : __DIR__"jietan2",
		"northwest" : __DIR__"fatang",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6120);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

