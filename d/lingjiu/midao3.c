// midao3.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ��
���ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ��
LONG );
	set("exits", ([
		"southup" : __DIR__"midao2",
		"eastdown": __DIR__"midao4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30170);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}