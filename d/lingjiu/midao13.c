// midao13.c
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
		"south" : __FILE__,
		"north" : __FILE__,
		"east" : __FILE__,
		"west" : __DIR__"midao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}