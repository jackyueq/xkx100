// midao11.c
//
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
���������ţ�ͻȻ��������ʧ�˷����������ߵ�ʱ��ȴ��������
���������ĵ�·�ˣ��㲻������һ���顣ͻȻ���ڻ�Ƶĵƹ��£���
Լ�������ߵĺ�����ǽ���Ͽ���һЩ���ι�״�ķ���(fuhao)��
LONG );
	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao12",
		"east" : __DIR__"midao14",
		"west" : __DIR__"mishi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}