// Room: /d/nanshaolin/jietan2.c
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
		"west"      : __DIR__"jietan1",
		"north"     : __DIR__"jietan4",
		"southwest" : __DIR__"sblu-3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6130);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

