//tan1.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
	     "�����Ǽ����Ϻ�ˮ�� �����ܵ����Ƚ���������������ͷ����̶ˮ��Ͷ��������\n"
	     "�Ե�ʮ���������������һƬҲ��֪��Щʲô���㲻�ɶ��Լ�˵......\n"

	);
	set("exits", ([
		"up"   : "/d/jiaxing/nanhu1",
		"down" : __DIR__"tan2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
