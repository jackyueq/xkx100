// /d/beijing/alley2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
�ֵ���һ����Ҳ����������ͻȻ�е㺦�����������ϱ���һ�ҹײ�
�ꡣ���ϱ���һ���������С��㲻֪��Ҫ��Ҫ���������ߡ�������
������ȥ�ɣ���á����������������ĵ���һ��������ס�ض���˵��
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"north"     : __DIR__"alley1",
		"southeast" : __DIR__"guancai1",
		"southwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
