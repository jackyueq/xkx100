//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
�����人����Ľֵ����Ӵ��ϱ����ĸ�ɫ�˵ȣ�����������Ħ
����ࡣ������һ��С�Ե꣬�ſڵ�������д�š���ͨ�ǡ��������֡�
������һ����ͷ������ϸ��������������ˮ�Ĵ򽭰���������
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"matou1",
		"west" : __DIR__"laotc",
		"south": __DIR__"hzjie3",
		"north": __DIR__"hzjie1",
	]));

	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
