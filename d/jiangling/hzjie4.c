//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG
�����人����Ľֵ����Ӵ��ϱ����ĸ�ɫ�˵ȣ�����������Ħ
����ࡣ������һ�ҿ�ջ����������ҩ�ĵĵ��̣��ƺ�������������ҩ��
����һ������ʯ�ʵ�������
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"kedian",
		"west" : __DIR__"yaocaidian",
		"south": __DIR__"hzjie5",
		"north": __DIR__"hzjie3",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
