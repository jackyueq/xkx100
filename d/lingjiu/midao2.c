// midao2.c

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ��
���ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ��
LONG );
	set("exits", ([
		"southup" : __DIR__"midao1",
		"northdown": __DIR__"midao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}